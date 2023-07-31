#ifndef LLCL_STANDARD_SYSTEM_ATOMICOPERATIONSCLANGINTRINSICS_H
#define LLCL_STANDARD_SYSTEM_ATOMICOPERATIONSCLANGINTRINSICS_H

#include "llcl/Standard/System/AtomicOperationsDefault.h"
#include "llcl/Standard/System/Platform.h"
#include "llcl/Standard/System/Types.h"

#if defined(LLCL_PLATFORM_CMP_CLANG)
#if __has_extension(c_atomic) || __has_extension(cxx_atomic)

namespace llcl {
namespace standard {

struct AtomicOperationsClangIntrinsics;
using AtomicOperationsImpl = AtomicOperationsClangIntrinsics;

// ==================================================================
// struct AtomicTypeTraits<AtomicOperationsClangIntrinsics>
// ==================================================================

template <>
struct AtomicTypeTraits<AtomicOperationsClangIntrinsics> {
  struct __attribute__((__aligned__(sizeof(int)))) Int {
    _Atomic(int) d_value;
  };

  struct __attribute__((__aligned__(sizeof(Types::Int64)))) Int64 {
    _Atomic(Types::Int64) d_value;
  };

  struct __attribute__((__aligned__(sizeof(unsigned int)))) Uint {
    _Atomic(unsigned int) d_value;
  };

  struct __attribute__((__aligned__(sizeof(Types::Uint64)))) Uint64 {
    _Atomic(Types::Uint64) d_value;
  };

  struct __attribute__((__aligned__(sizeof(void*)))) Pointer {
    _Atomic(void*) d_value;
  };
};

// ===============================================
// struct AtomicOperationsClangIntrinsics
// ===============================================

struct AtomicOperationsClangIntrinsics
#ifdef LLCL_PLATFORM_CPU_64_BIT
    : AtomicOperationsDefault64<AtomicOperationsClangIntrinsics>
#else
    : AtomicOperationsDefault32<AtomicOperationsClangIntrinsics>
#endif
{
  typedef AtomicTypeTraits<AtomicOperationsClangIntrinsics>
      AtomicTypes;

  typedef char AtomicIntSizeCheck[sizeof(int) == 4 ? 1 : -1];
  // compile-time assert

  // *** atomic functions for int ***

  static void initInt(AtomicTypes::Int* atomic_int, int value);

  static int getInt(const AtomicTypes::Int* atomic_int);

  static int getIntAcquire(const AtomicTypes::Int* atomic_int);

  static int getIntRelaxed(const AtomicTypes::Int* atomic_int);

  static void setInt(AtomicTypes::Int* atomic_int, int value);

  static void setIntRelease(AtomicTypes::Int* atomic_int, int value);

  static void setIntRelaxed(AtomicTypes::Int* atomic_int, int value);

  static int swapInt(AtomicTypes::Int* atomic_int, int swap_value);

  static int swapIntAcqRel(AtomicTypes::Int* atomic_int, int swap_value);

  static int testAndSwapInt(AtomicTypes::Int* atomic_int, int compare_value,
                            int swap_value);

  static int testAndSwapIntAcqRel(AtomicTypes::Int* atomic_int, int compare_value,
                                  int swap_value);

  static int addIntNv(AtomicTypes::Int* atomic_int, int value);

  static int addIntNvAcqRel(AtomicTypes::Int* atomic_int, int value);

  static int addIntNvRelaxed(AtomicTypes::Int* atomic_int, int value);

  // *** atomic functions for Int64 ***

  static void initInt64(AtomicTypes::Int64* atomic_int, Types::Int64 value);

  static Types::Int64 getInt64(const AtomicTypes::Int64* atomic_int);

  static Types::Int64 getInt64Acquire(const AtomicTypes::Int64* atomic_int);

  static Types::Int64 getInt64Relaxed(const AtomicTypes::Int64* atomic_int);

  static void setInt64(AtomicTypes::Int64* atomic_int, Types::Int64 value);

  static void setInt64Release(AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  static void setInt64Relaxed(AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  static Types::Int64 swapInt64(AtomicTypes::Int64* atomic_int,
                                Types::Int64 swap_value);

  static Types::Int64 swapInt64AcqRel(AtomicTypes::Int64* atomic_int,
                                      Types::Int64 swap_value);

  static Types::Int64 testAndSwapInt64(AtomicTypes::Int64* atomic_int,
                                       Types::Int64 compare_value,
                                       Types::Int64 swap_value);

  static Types::Int64 testAndSwapInt64AcqRel(AtomicTypes::Int64* atomic_int,
                                             Types::Int64 compare_value,
                                             Types::Int64 swap_value);

  static Types::Int64 addInt64Nv(AtomicTypes::Int64* atomic_int,
                                 Types::Int64 value);

  static Types::Int64 addInt64NvAcqRel(AtomicTypes::Int64* atomic_int,
                                       Types::Int64 value);

  static Types::Int64 addInt64NvRelaxed(AtomicTypes::Int64* atomic_int,
                                        Types::Int64 value);
};

// ============================================================================
//                        INLINE FUNCTION DEFINITIONS
// ============================================================================

// -----------------------------------------------
// struct AtomicOperationsClangIntrinsics
// -----------------------------------------------

inline void AtomicOperationsClangIntrinsics::initInt(
    AtomicTypes::Int* atomic_int, int value) {
  __c11_atomic_init(&atomic_int->d_value, value);
}

inline int AtomicOperationsClangIntrinsics::getInt(
    const AtomicTypes::Int* atomic_int) {
  return __c11_atomic_load(const_cast<_Atomic(int)*>(&atomic_int->d_value),
                           __ATOMIC_SEQ_CST);
}

inline int AtomicOperationsClangIntrinsics::getIntAcquire(
    const AtomicTypes::Int* atomic_int) {
  return __c11_atomic_load(const_cast<_Atomic(int)*>(&atomic_int->d_value),
                           __ATOMIC_ACQUIRE);
}

inline int AtomicOperationsClangIntrinsics::getIntRelaxed(
    const AtomicTypes::Int* atomic_int) {
  return __c11_atomic_load(const_cast<_Atomic(int)*>(&atomic_int->d_value),
                           __ATOMIC_RELAXED);
}

inline void AtomicOperationsClangIntrinsics::setInt(
    AtomicTypes::Int* atomic_int, int value) {
  __c11_atomic_store(&atomic_int->d_value, value, __ATOMIC_SEQ_CST);
}

inline void AtomicOperationsClangIntrinsics::setIntRelease(
    AtomicTypes::Int* atomic_int, int value) {
  __c11_atomic_store(&atomic_int->d_value, value, __ATOMIC_RELEASE);
}

inline void AtomicOperationsClangIntrinsics::setIntRelaxed(
    AtomicTypes::Int* atomic_int, int value) {
  __c11_atomic_store(&atomic_int->d_value, value, __ATOMIC_RELAXED);
}

inline int AtomicOperationsClangIntrinsics::swapInt(
    AtomicTypes::Int* atomic_int, int swap_value) {
  return __c11_atomic_exchange(&atomic_int->d_value, swap_value,
                               __ATOMIC_SEQ_CST);
}

inline int AtomicOperationsClangIntrinsics::swapIntAcqRel(
    AtomicTypes::Int* atomic_int, int swap_value) {
  return __c11_atomic_exchange(&atomic_int->d_value, swap_value,
                               __ATOMIC_ACQ_REL);
}

inline int AtomicOperationsClangIntrinsics::testAndSwapInt(
    AtomicTypes::Int* atomic_int, int compare_value, int swap_value) {
  __c11_atomic_compare_exchange_strong(&atomic_int->d_value, &compare_value,
                                       swap_value, __ATOMIC_SEQ_CST,
                                       __ATOMIC_SEQ_CST);
  return compare_value;
}

inline int AtomicOperationsClangIntrinsics::testAndSwapIntAcqRel(
    AtomicTypes::Int* atomic_int, int compare_value, int swap_value) {
  __c11_atomic_compare_exchange_strong(&atomic_int->d_value, &compare_value,
                                       swap_value, __ATOMIC_ACQ_REL,
                                       __ATOMIC_ACQUIRE);
  return compare_value;
}

inline int AtomicOperationsClangIntrinsics::addIntNv(
    AtomicTypes::Int* atomic_int, int value) {
  return __c11_atomic_fetch_add(&atomic_int->d_value, value, __ATOMIC_SEQ_CST) +
         value;
}

inline int AtomicOperationsClangIntrinsics::addIntNvAcqRel(
    AtomicTypes::Int* atomic_int, int value) {
  return __c11_atomic_fetch_add(&atomic_int->d_value, value, __ATOMIC_ACQ_REL) +
         value;
}

inline int AtomicOperationsClangIntrinsics::addIntNvRelaxed(
    AtomicTypes::Int* atomic_int, int value) {
  return __c11_atomic_fetch_add(&atomic_int->d_value, value, __ATOMIC_RELAXED) +
         value;
}

inline void AtomicOperationsClangIntrinsics::initInt64(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  __c11_atomic_init(&atomic_int->d_value, value);
}

inline Types::Int64 AtomicOperationsClangIntrinsics::getInt64(
    const AtomicTypes::Int64* atomic_int) {
  return __c11_atomic_load(
      const_cast<_Atomic(Types::Int64)*>(&atomic_int->d_value),
      __ATOMIC_SEQ_CST);
}

inline Types::Int64 AtomicOperationsClangIntrinsics::getInt64Acquire(
    const AtomicTypes::Int64* atomic_int) {
  return __c11_atomic_load(
      const_cast<_Atomic(Types::Int64)*>(&atomic_int->d_value),
      __ATOMIC_ACQUIRE);
}

inline Types::Int64 AtomicOperationsClangIntrinsics::getInt64Relaxed(
    const AtomicTypes::Int64* atomic_int) {
  return __c11_atomic_load(
      const_cast<_Atomic(Types::Int64)*>(&atomic_int->d_value),
      __ATOMIC_RELAXED);
}

inline void AtomicOperationsClangIntrinsics::setInt64(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  __c11_atomic_store(&atomic_int->d_value, value, __ATOMIC_SEQ_CST);
}

inline void AtomicOperationsClangIntrinsics::setInt64Release(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  __c11_atomic_store(&atomic_int->d_value, value, __ATOMIC_RELEASE);
}

inline void AtomicOperationsClangIntrinsics::setInt64Relaxed(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  __c11_atomic_store(&atomic_int->d_value, value, __ATOMIC_RELAXED);
}

inline Types::Int64 AtomicOperationsClangIntrinsics::swapInt64(
    AtomicTypes::Int64* atomic_int, Types::Int64 swap_value) {
  return __c11_atomic_exchange(&atomic_int->d_value, swap_value,
                               __ATOMIC_SEQ_CST);
}

inline Types::Int64 AtomicOperationsClangIntrinsics::swapInt64AcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 swap_value) {
  return __c11_atomic_exchange(&atomic_int->d_value, swap_value,
                               __ATOMIC_ACQ_REL);
}

inline Types::Int64 AtomicOperationsClangIntrinsics::testAndSwapInt64(
    AtomicTypes::Int64* atomic_int, Types::Int64 compare_value,
    Types::Int64 swap_value) {
  __c11_atomic_compare_exchange_strong(&atomic_int->d_value, &compare_value,
                                       swap_value, __ATOMIC_SEQ_CST,
                                       __ATOMIC_SEQ_CST);
  return compare_value;
}

inline Types::Int64
AtomicOperationsClangIntrinsics::testAndSwapInt64AcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 compare_value,
    Types::Int64 swap_value) {
  __c11_atomic_compare_exchange_strong(&atomic_int->d_value, &compare_value,
                                       swap_value, __ATOMIC_ACQ_REL,
                                       __ATOMIC_ACQUIRE);
  return compare_value;
}

inline Types::Int64 AtomicOperationsClangIntrinsics::addInt64Nv(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return __c11_atomic_fetch_add(&atomic_int->d_value, value, __ATOMIC_SEQ_CST) +
         value;
}

inline Types::Int64 AtomicOperationsClangIntrinsics::addInt64NvAcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return __c11_atomic_fetch_add(&atomic_int->d_value, value, __ATOMIC_ACQ_REL) +
         value;
}

inline Types::Int64 AtomicOperationsClangIntrinsics::addInt64NvRelaxed(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return __c11_atomic_fetch_add(&atomic_int->d_value, value, __ATOMIC_RELAXED) +
         value;
}

}  // namespace standard
}  // namespace llcl

#endif  //  __has_extension(c_atomic) || __has_extension(cxx_atomic)

#endif  // LLCL_PLATFORM_CMP_CLANG

#endif  // LLCL_STANDARD_SYSTEM_ATOMICOPERATIONSCLANGINTRINSICS_H