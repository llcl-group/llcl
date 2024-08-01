#ifndef LLCL_STANDARD_SUPPORT_DATATYPES_H
#define LLCL_STANDARD_SUPPORT_DATATYPES_H

#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>

/* Set defaults for constants which we cannot find. */
#if !defined(INT64_MAX)
#define INT64_MAX 9223372036854775807LL
#endif
#if !defined(INT64_MIN)
#define INT64_MIN ((-INT64_MAX) - 1)
#endif
#if !defined(UINT64_MAX)
#define UINT64_MAX 0xffffffffffffffffULL
#endif

#endif  // LLCL_STANDARD_SUPPORT_DATATYPES_H