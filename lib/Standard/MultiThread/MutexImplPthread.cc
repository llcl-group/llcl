#include "llcl/Standard/MultiThread/MutexImplPthread.h"

#ifdef LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS

namespace llcl {
namespace standard {
namespace mt {

static_assert(0 == sizeof(MutexImpl<Platform::PosixThreads>) % sizeof(int));

MutexImpl<Platform::PosixThreads>::~MutexImpl() {
  const int status = pthread_mutex_destroy(&data_lock);
  (void)status;

  LLCL_ASSERT(0 == status);

#ifdef LLCL_ASSERT_SAFE_IS_ACTIVE
  int* pInt = reinterpret_cast<int*>(&data_lock);
  const int* pEnd = reinterpret_cast<const int*>(&data_lock + 1);

  while (pInt < pEnd) {
    *pInt = 0xdeadbeef;
    ++pInt;
  }
#endif
}

}  // namespace mt
}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_MT_PLATFORM_POSIX_THREADS