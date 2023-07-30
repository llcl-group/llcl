#include "llcl/Standard/MultiThread/MutexImplPthread.h"

#ifdef LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS

#include "llcl/Standard/System/Assert.h"

namespace llcl {
namespace standard {
namespace mt {

static_assert(0 == sizeof(MutexImpl<Platform::PosixThreads>) % sizeof(int));

MutexImpl<Platform::PosixThreads>::MutexImpl() {
  const int status = pthread_mutex_init(&data_lock, 0);
  (void)status;
  LLCL_ASSERT(0 == status);
}

MutexImpl<Platform::PosixThreads>::~MutexImpl() {
  const int status = pthread_mutex_destroy(&data_lock);
  (void)status;

  LLCL_ASSERT(0 == status);

#ifdef LLCL_ASSERT_SAFE_IS_ACTIVE
  // Since we do not want to burden 'lock' and 'unlock' with the overhead of
  // 'BSLS_ASSERT_OPT' (as their 'status' values should always be 0 in a
  // well-behaved program), we overwrite 'd_lock' with garbage so as to
  // (potentially) trigger a fault on attempts to lock or unlock following
  // destruction.

  int* pInt = reinterpret_cast<int*>(&data_lock);
  const int* pEnd = reinterpret_cast<const int*>(&data_lock + 1);

  while (pInt < pEnd) {
    *pInt = 0xdeadbeef;
    ++pInt;
  }
#endif
}

inline int MutexImpl<Platform::PosixThreads>::try_lock() {
  LLCL_ASSERT_SAFE(0xdeadbeef != *reinterpret_cast<const unsigned*>(&data_lock));

  return pthread_mutex_trylock(&data_lock);
}

inline void MutexImpl<Platform::PosixThreads>::unlock() {
  LLCL_ASSERT_SAFE(0xdeadbeef != *reinterpret_cast<const unsigned*>(&data_lock));

  const int status = pthread_mutex_unlock(&data_lock);
  (void)status;
  LLCL_ASSERT_SAFE(0 == status);
}

MutexImpl<Platform::PosixThreads>::NativeType&
MutexImpl<Platform::PosixThreads>::native_mutex() {
  return data_lock;
}

}  // namespace mt
}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS