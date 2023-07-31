#ifndef LLCL_STANDARD_MULTITHREAD_MUTEX_H
#define LLCL_STANDARD_MULTITHREAD_MUTEX_H

#include "llcl/Standard/MultiThread/MutexImplPthread.h"

namespace llcl {
namespace standard {
namespace mt {

template <class ThreadPolicy>
class MutexImpl;

class Mutex {
  MutexImpl<Platform::ThreadPolicy> data_impl;

  Mutex(const Mutex&);
  Mutex& operator=(const Mutex&);

 public:
  using NativeType = MutexImpl<Platform::ThreadPolicy>::NativeType;

  Mutex();

  ~Mutex();

  void lock();

  NativeType& native_mutex();

  int try_lock();

  void unlock();
};

inline Mutex::Mutex() {}

inline Mutex::~Mutex() {}

inline void Mutex::lock() { data_impl.lock(); }

inline Mutex::NativeType& Mutex::native_mutex() {
  return data_impl.native_mutex();
}

inline int Mutex::try_lock() { return data_impl.try_lock(); }

inline void Mutex::unlock() { data_impl.unlock(); }

}  // namespace mt
}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_MULTITHREAD_MUTEX_H