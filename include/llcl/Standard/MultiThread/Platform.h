#ifndef LLCL_STANDARD_MULTITHREAD_PLATFORM_H
#define LLCL_STANDARD_MULTITHREAD_PLATFORM_H

#include "llcl/Standard/System/Platform.h"

namespace llcl {

namespace standard {

namespace mt {

struct Platform {
  struct PosixThreads {};

#ifdef LLCL_PLATFORM_OS_UNIX
  using ThreadPolicy = PosixThreads;
#define LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS 1
#endif

  struct CountedSemaphore {};
  struct PosixSemaphore {};

#ifdef LLCL_PLATFORM_OS_UNIX
  using SemaphorePolicy = PosixSemaphore;
#define LLCL_STANDARD_MT_PLATFORM_POSIX_SEMAPHORE
#endif

  struct PosixAdvTimedSemaphore {};
  struct PthreadTimedSemaphore {};

  enum {
    CACHE_LINE_SIZE = 64
  };
};

}  // namespace mt
}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_MULTITHREAD_PLATFORM_H