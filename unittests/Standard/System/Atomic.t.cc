#include "llcl/Standard/System/Atomic.h"

#include <gtest/gtest.h>
#include <pthread.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>

#include <cstddef>
#include <iostream>

typedef pthread_t thread_t;

namespace llcl {
namespace {

struct APTestObj {
  const APTestObj* self() const { return this; }
};

typedef llcl::standard::AtomicInt AI;
typedef llcl::standard::AtomicInt64 AI64;
typedef llcl::standard::AtomicUint AUI;
typedef llcl::standard::AtomicUint64 AUI64;
typedef llcl::standard::AtomicPointer<APTestObj> AP;
typedef llcl::standard::AtomicPointer<const APTestObj> CAP;
typedef llcl::standard::AtomicBool AB;

typedef llcl::standard::Types::Int64 Int64;
typedef llcl::standard::Types::Uint64 Uint64;

#define UINT64_M1 0xFFFFFFFFFFFFFFFFLL
#define UINT64_M2 0xFFFFFFFFFFFFFFFELL
#define INT64_MN  0x1000000000000000LL
#define INT64_MN1 0x1000000000000001LL

const int g_spinCount = 100;

void yield() { sched_yield(); }

template <class INT>
struct LockData {
  INT flags[2];
  INT turn;  // 0 or 1 - index into d_flags
};

template <class INT>
class PetersonsLock {
 public:
  PetersonsLock(int id, LockData<INT>& lockData) : d_id(id), d_data(lockData) {
    EXPECT_TRUE(id == 0 || id == 1);
  }

  void lock() {
    d().flags[d_id].storeRelaxed(1);
    d().turn.swapAcqRel(1 - d_id);

    int spin = g_spinCount;

    while (d().flags[1 - d_id].loadAcquire() &&
           static_cast<int>(d().turn.loadAcquire()) == 1 - d_id) {
      if (--spin == 0) {
        yield();
        spin = g_spinCount;
      }
    }
  }

  void unlock() { d().flags[d_id].storeRelease(0); }

 private:
  LockData<INT>& d() const { return d_data; }

 private:
  int d_id;  // 0 or 1 - id of the thread that owns this object
  LockData<INT>& d_data;
};

template <class INT>
class PetersonsLockSeqCst {
 public:
  PetersonsLockSeqCst(int id, LockData<INT>& lockData)
      : d_id(id), d_data(lockData) {
    EXPECT_TRUE(id == 0 || id == 1);
  }

  void lock() {
    d().flags[d_id] = 1;
    d().turn.swap(1 - d_id);

    int spin = g_spinCount;

    while (d().flags[1 - d_id] &&
           static_cast<llcl::standard::Types::Int64>(d().turn) == 1 - d_id) {
      if (--spin == 0) {
        yield();
        spin = g_spinCount;
      }
    }
  }

  void unlock() { d().flags[d_id] = 0; }

 private:
  LockData<INT>& d() const { return d_data; }

 private:
  int d_id;  // 0 or 1 - id of the thread that owns this object
  LockData<INT>& d_data;
};

template <class LOCK>
struct Guard {
  Guard(LOCK& lock) : d_lock(lock) { d_lock.lock(); }

  ~Guard() { d_lock.unlock(); }

  LOCK& d_lock;
};

llcl::standard::AtomicInt s_data1(0);
llcl::standard::AtomicInt s_data2(0);
llcl::standard::AtomicInt s_data3(1);

template <class LOCK>
void testAtomicLocking(LOCK& lock, int iterations) {
  for (int i = 0; i < iterations; ++i) {
    if (rand() & 1) {
      // read shared data
      Guard<LOCK> guard(lock);

      int data1 = s_data1.loadRelaxed();
      int data2 = s_data2.loadRelaxed();
      int data3 = s_data3.loadRelaxed();

      EXPECT_TRUE(data1 == -data2 && data1 + 1 == data3);
    } else {
      // write to shared data
      Guard<LOCK> guard(lock);

      int data = rand();
      s_data1.storeRelaxed(data);
      s_data2.storeRelaxed(-data);
      s_data3.storeRelaxed(data + 1);
    }
  }
}

struct AtomicLockingThreadParamBase {
  virtual void test() = 0;
};

template <class LOCK>
struct AtomicLockingThreadParam : public AtomicLockingThreadParamBase {
  AtomicLockingThreadParam(LOCK& lock, int iterations)
      : d_lock(lock), d_iterations(iterations) {}

  LOCK& d_lock;
  int d_iterations;

  virtual void test() { testAtomicLocking(d_lock, d_iterations); }
};

extern "C" void* testAtomicLockingThreadFunc(void* arg) {
  reinterpret_cast<AtomicLockingThreadParamBase*>(arg)->test();

  return 0;
}

extern "C" {
typedef void* (*thread_func)(void* arg);
}

thread_t createThread(thread_func func, void* arg) {
  thread_t thr;
  pthread_create(&thr, 0, func, arg);
  return thr;
}

void joinThread(thread_t thr) { pthread_join(thr, 0); }

void sleepSeconds(int sec) { sleep(sec); }

struct TestLoopParameters {
  typedef void (*TestFunc)(TestLoopParameters*);

  llcl::standard::AtomicInt d_cancel;
  llcl::standard::AtomicInt d_iterations;
  TestFunc d_testFunc;
};

void petersonsLockLoopTest(TestLoopParameters* params) {
  LockData<llcl::standard::AtomicInt64> ld;
  PetersonsLockSeqCst<llcl::standard::AtomicInt64> lock(0, ld);

  for (; !params->d_cancel; ++params->d_iterations) {
    Guard<PetersonsLockSeqCst<llcl::standard::AtomicInt64> > guard(lock);
  }
}

void sharedCountLoopTest(TestLoopParameters* params) {
  llcl::standard::AtomicInt count;

  for (; !params->d_cancel; ++params->d_iterations) {
    count.storeRelease(10);

    while (count.loadAcquire() != 0) {
      count.addAcqRel(-1);
    }
  }
}

extern "C" void* runTestingLoop(void* arg) {
  TestLoopParameters* params = static_cast<TestLoopParameters*>(arg);
  params->d_testFunc(params);

  return 0;
}

extern "C" void* runObserverLoop(void* arg) {
  TestLoopParameters* params = static_cast<TestLoopParameters*>(arg);

  while (!params->d_cancel && params->d_iterations >= 0) {
  }

  return 0;
}

int getTestCaseIterations(TestLoopParameters::TestFunc testFunc) {
  TestLoopParameters params;
  params.d_testFunc = testFunc;
  thread_t loopThr = createThread(&runTestingLoop, &params);
  thread_t obsvThr = createThread(&runObserverLoop, &params);

  sleepSeconds(1);  // this makes the real test run for a couple of minutes

  params.d_cancel = 1;
  joinThread(loopThr);
  joinThread(obsvThr);

  return params.d_iterations;
}

template <template <class> class LOCK, class INT>
void testCaseMemOrder(int iterations) {
  LockData<INT> lockData;
  LOCK<INT> lock0(0, lockData);
  LOCK<INT> lock1(1, lockData);

  AtomicLockingThreadParam<LOCK<INT> > param0(lock0, iterations);
  AtomicLockingThreadParam<LOCK<INT> > param1(lock1, iterations);

  thread_t thr0 = createThread(&testAtomicLockingThreadFunc, &param0);
  thread_t thr1 = createThread(&testAtomicLockingThreadFunc, &param1);

  joinThread(thr0);
  joinThread(thr1);
}

void testSharedCountWrite(int& data, llcl::standard::AtomicInt& shared,
                          llcl::standard::AtomicInt& done, int) {
  int spin = g_spinCount;

  while (!done.loadRelaxed()) {
    while (shared.loadRelaxed() > 1) {
      const_cast<int volatile&>(data) = shared.loadRelaxed();
      shared.addAcqRel(-1);  // plays the role of store release
    }

    if (--spin == 0) {
      yield();
      spin = g_spinCount;
    }
  }
}

void testSharedCountRead(int& data, llcl::standard::AtomicInt& shared,
                         llcl::standard::AtomicInt& done, int iterations) {
  for (int i = 0; i < iterations; ++i) {
    shared.storeRelease(10);

    int spin = g_spinCount;

    while (shared.loadRelaxed() != 1) {
      if (--spin == 0) {
        yield();
        spin = g_spinCount;
      }
    }

    if (shared.addAcqRel(-1) == 0) {  // plays the role of load acquire
      EXPECT_TRUE(const_cast<int volatile&>(data) == 2);
    } else {
      EXPECT_TRUE(false && "logic error in test");
    }
  }

  done.storeRelaxed(1);
}

struct SharedCountThreadParam {
  typedef void (*ThreadFunc)(int&, llcl::standard::AtomicInt&,
                             llcl::standard::AtomicInt&, int);

  SharedCountThreadParam(int& data, llcl::standard::AtomicInt& shared,
                         llcl::standard::AtomicInt& done, ThreadFunc func,
                         int iterations)
      : d_data(data),
        d_shared(shared),
        d_done(done),
        d_func(func),
        d_iterations(iterations) {}

  int& d_data;
  llcl::standard::AtomicInt& d_shared;
  llcl::standard::AtomicInt& d_done;
  ThreadFunc d_func;
  int d_iterations;
};

extern "C" void* testSharedCountThreadFunc(void* arg) {
  SharedCountThreadParam* param =
      reinterpret_cast<SharedCountThreadParam*>(arg);

  param->d_func(param->d_data, param->d_shared, param->d_done,
                param->d_iterations);
  return 0;
}

void testCaseSharedPtr(int iterations) {
  llcl::standard::AtomicInt shared;
  llcl::standard::AtomicInt done;
  int data = 0;

  SharedCountThreadParam paramReader(data, shared, done, &testSharedCountRead,
                                     iterations);
  thread_t thrReader = createThread(&testSharedCountThreadFunc, &paramReader);

  SharedCountThreadParam paramWriter(data, shared, done, &testSharedCountWrite,
                                     iterations);
  thread_t thrWriter = createThread(&testSharedCountThreadFunc, &paramWriter);

  joinThread(thrReader);
  joinThread(thrWriter);
}

int processNextTransaction()
// Dummy implementation.
{
  return 0;
}

void createWorkerThread()
// Dummy implementation.
{}

void waitAllThreads()
// Dummy implementation.
{}

static llcl::standard::AtomicInt64 transactionCount;
static llcl::standard::AtomicInt64 successCount;
static llcl::standard::AtomicInt64 failureCount;

void serverMain() {
  const int num_threads = 10;
  for (int i = 0; i < num_threads; ++i) {
    createWorkerThread();
  }
  waitAllThreads();
}

template <class INSTANCE>
class my_CountedHandle;

template <class INSTANCE>
class my_CountedHandleRep {
  // DATA
  INSTANCE* d_instance_p;             // address of managed instance
  llcl::standard::AtomicInt d_count;  // number of active references

  // FRIENDS
  friend class my_CountedHandle<INSTANCE>;

  // NOT IMPLEMENTED
  my_CountedHandleRep(const my_CountedHandleRep&);
  my_CountedHandleRep& operator=(const my_CountedHandleRep&);

 private:
  // PRIVATE CLASS METHODS
  static void deleteObject(my_CountedHandleRep<INSTANCE>* object);

  // PRIVATE CREATORS
  my_CountedHandleRep(INSTANCE* instance);
  ~my_CountedHandleRep();

  // PRIVATE MANIPULATORS
  void increment();
  int decrement();
};

template <class INSTANCE>
class my_CountedHandle {
  // DATA
  my_CountedHandleRep<INSTANCE>* d_rep_p;  // shared rep.

 public:
  // CREATORS
  my_CountedHandle();
  my_CountedHandle(INSTANCE* instance);

  my_CountedHandle(const my_CountedHandle<INSTANCE>& other);

  ~my_CountedHandle();

  // ACCESSORS
  INSTANCE* operator->() const;
  int numReferences() const;
};

template <class INSTANCE>
inline void my_CountedHandleRep<INSTANCE>::deleteObject(
    my_CountedHandleRep<INSTANCE>* object) {
  delete object;
}

template <class INSTANCE>
inline my_CountedHandleRep<INSTANCE>::my_CountedHandleRep(INSTANCE* instance)
    : d_instance_p(instance), d_count(1) {}

template <class INSTANCE>
inline my_CountedHandleRep<INSTANCE>::~my_CountedHandleRep() {
  delete d_instance_p;
}

template <class INSTANCE>
inline void my_CountedHandleRep<INSTANCE>::increment() {
  ++d_count;
}

template <class INSTANCE>
inline int my_CountedHandleRep<INSTANCE>::decrement() {
  return --d_count;
}

template <class INSTANCE>
inline my_CountedHandle<INSTANCE>::my_CountedHandle(INSTANCE* instance) {
  d_rep_p = new my_CountedHandleRep<INSTANCE>(instance);
}

template <class INSTANCE>
inline my_CountedHandle<INSTANCE>::my_CountedHandle(
    const my_CountedHandle<INSTANCE>& other)
    : d_rep_p(other.d_rep_p) {
  if (d_rep_p) {
    d_rep_p->increment();
  }
}

template <class INSTANCE>
inline my_CountedHandle<INSTANCE>::~my_CountedHandle() {
  if (d_rep_p && 0 == d_rep_p->decrement()) {
    my_CountedHandleRep<INSTANCE>::deleteObject(d_rep_p);
  }
}

template <class INSTANCE>
inline INSTANCE* my_CountedHandle<INSTANCE>::operator->() const {
  return d_rep_p->d_instance_p;
}

template <class INSTANCE>
inline int my_CountedHandle<INSTANCE>::numReferences() const {
  return d_rep_p ? d_rep_p->d_count : 0;
}

template <class TYPE>
class my_PtrStack {
  // TYPES
  struct Node {
    TYPE* d_item_p;
    Node* d_next_p;
    llcl::standard::AtomicInt d_inUseFlag;  // used to lock this node
  };

  // DATA
  llcl::standard::AtomicPointer<Node> d_list;
  llcl::standard::AtomicPointer<Node> d_freeList;

  // PRIVATE MANIPULATORS
  Node* allocateNode();
  void freeNode(Node* node);
  void deleteNodes(Node* node);

 public:
  // CREATORS
  my_PtrStack();
  ~my_PtrStack();

  // MANIPULATORS
  void push(TYPE* item);
  TYPE* pop();
};

template <class TYPE>
inline my_PtrStack<TYPE>::my_PtrStack() {}

template <class TYPE>
inline void my_PtrStack<TYPE>::deleteNodes(Node* node) {
  while (node) {
    Node* next = node->d_next_p;
    delete node;
    node = next;
  }
}

template <class TYPE>
inline my_PtrStack<TYPE>::~my_PtrStack() {
  deleteNodes(d_list);
  deleteNodes(d_freeList);
}

template <class TYPE>
typename my_PtrStack<TYPE>::Node* my_PtrStack<TYPE>::allocateNode() {
  Node* node;
  while (1) {
    node = d_freeList;  // get the current head
    if (!node) {
      break;
    }

    if (node->d_inUseFlag.swapInt(1)) {
      continue;
    }

    if (d_freeList.testAndSwap(node, node->d_next_p) == node) {
      break;
    }

    // Unlock the node.
    node->d_inUseFlag = 0;
  }

  if (!node) {
    node = new Node();
    node->d_inUseFlag = 1;
  }

  return node;
}

template <class TYPE>
inline void my_PtrStack<TYPE>::freeNode(Node* node) {
  if (!node) {
    return;  // RETURN
  }

  while (1) {
    node->d_next_p = d_freeList;
    if (d_freeList.testAndSwap(node->d_next_p, node) == node->d_next_p) {
      break;
    }
  }

  // unlock the 'node'
  node->d_inUseFlag = 0;
}

template <class TYPE>
void my_PtrStack<TYPE>::push(TYPE* item) {
  Node* node = allocateNode();
  node->d_item_p = item;
  while (1) {
    node->d_next_p = d_list;
    if (d_list.testAndSwap(node->d_next_p, node) == node->d_next_p) {
      break;
    }
  }

  node->d_inUseFlag = 0;
}

template <class TYPE>
TYPE* my_PtrStack<TYPE>::pop() {
  Node* node;
  while (1) {
    node = d_list;
    if (!node) {
      break;
    }

    if (node->d_inUseFlag.swapInt(1)) {
      continue;
    }

    if (d_list.testAndSwap(node, node->d_next_p) == node) {
      break;
    }

    node->d_inUseFlag = 0;
  }

  TYPE* item = node ? node->d_item_p : 0;
  if (node) {
    freeNode(node);
  }
  return item;
}

TEST(AtomicTest, Basic) {
  { my_PtrStack<int> stack; }
  { my_CountedHandle<double> handle(NULL); }

  int XVA = -1;
  int XVB = 2;
  int XVC = -2;

  APTestObj* PVA = (APTestObj*)0xffff8888;
  APTestObj* PVB = (APTestObj*)0xffffffff;
  APTestObj* PVC = (APTestObj*)0x78888888;

  int lresult;
  void* pResult;

  AI mX1;

  EXPECT_TRUE(0 == mX1);

  mX1 = XVA;
  EXPECT_TRUE(XVA == mX1);

  mX1.storeRelaxed(XVB);
  EXPECT_TRUE(mX1.loadRelaxed() == XVB);

  mX1.storeRelease(XVC);
  EXPECT_TRUE(mX1.loadAcquire() == XVC);

  mX1 = 0;
  EXPECT_TRUE(0 == mX1);

  ++mX1;
  EXPECT_TRUE(1 == mX1);

  --mX1;
  EXPECT_TRUE(0 == mX1);

  lresult = ++mX1;
  EXPECT_TRUE(1 == lresult);
  EXPECT_TRUE(1 == mX1);

  lresult = --mX1;
  EXPECT_TRUE(0 == lresult);
  EXPECT_TRUE(0 == mX1);

  mX1 = 0;
  EXPECT_TRUE(0 == mX1);

  mX1 += XVB;
  EXPECT_TRUE(XVB == mX1);

  mX1.addRelaxed(XVC);
  EXPECT_TRUE(mX1 == XVB + XVC);

  mX1.addAcqRel(XVA);
  EXPECT_TRUE(mX1 == XVA + XVB + XVC);

  mX1 = 0;
  EXPECT_TRUE(0 == mX1);

  lresult = mX1.swap(XVA);
  EXPECT_TRUE(0 == lresult);
  EXPECT_TRUE(mX1 == XVA);

  lresult = mX1.swapAcqRel(XVC);
  EXPECT_TRUE(lresult == XVA);
  EXPECT_TRUE(mX1 == XVC);

  lresult = mX1.testAndSwap(XVA, XVB);
  EXPECT_TRUE(XVC == lresult);
  EXPECT_TRUE(XVC == mX1);

  lresult = mX1.testAndSwap(XVC, 0);
  EXPECT_TRUE(XVC == lresult);
  EXPECT_TRUE(0 == mX1);

  lresult = mX1.testAndSwapAcqRel(XVC, XVA);
  EXPECT_TRUE(lresult == 0);
  EXPECT_TRUE(mX1 == 0);

  lresult = mX1.testAndSwapAcqRel(0, XVA);
  EXPECT_TRUE(lresult == 0);
  EXPECT_TRUE(mX1 == XVA);

  // Pointers
  // --------
  AP mP1;

  EXPECT_TRUE(((APTestObj*)0) == mP1);

  pResult = mP1.swap(PVC);
  EXPECT_TRUE(((APTestObj*)0) == pResult);
  EXPECT_TRUE(PVC == mP1);

  pResult = mP1.testAndSwap(PVA, PVB);
  EXPECT_TRUE(PVC == pResult);
  EXPECT_TRUE(PVC == mP1);

  pResult = mP1.testAndSwap(PVC, 0);
  EXPECT_TRUE(PVC == pResult);
  EXPECT_TRUE(((APTestObj*)0) == mP1);
}

}  // namespace
}  // namespace llcl