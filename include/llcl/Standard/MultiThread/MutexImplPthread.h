#ifndef LLCL_STANDARD_MULTITHREAD_MUTEXIMPLPTHREAD_H
#define LLCL_STANDARD_MULTITHREAD_MUTEXIMPLPTHREAD_H

#include "llcl/Standard/MultiThread/Platform.h"

#ifdef LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS

#include <pthread.h>

#include "llcl/Standard/Std/cstring.h"

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

}  // namespace mt
}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS

#endif  // LLCL_STANDARD_MULTITHREAD_MUTEXIMPLPTHREAD_H