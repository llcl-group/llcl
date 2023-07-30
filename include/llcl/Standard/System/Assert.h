#ifndef LLCL_STANDARD_SYSTEM_ASSERT_H
#define LLCL_STANDARD_SYSTEM_ASSERT_H

#include <cassert>

#define LLCL_ASSERT(X)             assert(X)

#define LLCL_ASSERT_SAFE_IS_ACTIVE 1
#ifdef LLCL_ASSERT_SAFE_IS_ACTIVE
#define LLCL_ASSERT_SAFE(X) assert(X)
#else
#define LLCL_ASSERT_SAFE(X)
#endif

#endif  // LLCL_STANDARD_SYSTEM_ASSERT_H