#ifndef LLCL_STANDARD_MULTITHREAD_MUTEXIMPLPTHREAD_H
#define LLCL_STANDARD_MULTITHREAD_MUTEXIMPLPTHREAD_H

#include "llcl/Standard/MultiThread/Platform.h"

#ifdef LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS

#include <pthread.h>

#include "llcl/Standard/Std/cstring.h"
#include "llcl/Standard/System/Assert.h"

namespace llcl {
namespace standard {
namespace mt {

template <class ThreadPolicy>
class MutexImpl;

template <>
class MutexImpl<Platform::PosixThreads> {
  pthread_mutex_t data_lock;

  MutexImpl(const MutexImpl&);
  MutexImpl& operator=(const MutexImpl&);

 public:
  using NativeType = pthread_mutex_t;

  MutexImpl();

  ~MutexImpl();

  void lock();

  NativeType& native_mutex();

  int try_lock();

  void unlock();
};

inline MutexImpl<Platform::PosixThreads>::MutexImpl() {
  const int status = pthread_mutex_init(&data_lock, 0);
  (void)status;
  LLCL_ASSERT(0 == status);
}

inline int MutexImpl<Platform::PosixThreads>::try_lock() {
  LLCL_ASSERT_SAFE(0xdeadbeef !=
                   *reinterpret_cast<const unsigned*>(&data_lock));

  return pthread_mutex_trylock(&data_lock);
}

inline void MutexImpl<Platform::PosixThreads>::lock() {
  LLCL_ASSERT_SAFE(0xdeadbeef !=
                   *reinterpret_cast<const unsigned*>(&data_lock));

  const int status = pthread_mutex_lock(&data_lock);
  (void)status;
  LLCL_ASSERT_SAFE(0 == status);
}

inline void MutexImpl<Platform::PosixThreads>::unlock() {
  LLCL_ASSERT_SAFE(0xdeadbeef !=
                   *reinterpret_cast<const unsigned*>(&data_lock));

  const int status = pthread_mutex_unlock(&data_lock);
  (void)status;
  LLCL_ASSERT_SAFE(0 == status);
}

inline MutexImpl<Platform::PosixThreads>::NativeType&
MutexImpl<Platform::PosixThreads>::native_mutex() {
  return data_lock;
}

}  // namespace mt
}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS

#endif  // LLCL_STANDARD_MULTITHREAD_MUTEXIMPLPTHREAD_H