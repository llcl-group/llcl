#ifndef LLCL_STANDARD_SYSTEM_ATOMICOPERATIONS_H
#define LLCL_STANDARD_SYSTEM_ATOMICOPERATIONS_H

#include "llcl/Standard/System/Platform.h"
#include "llcl/Standard/System/Types.h"

#if defined(LLCL_PLATFORM_CMP_CLANG)
#if __has_extension(c_atomic) || __has_extension(cxx_atomic)
#define LLCL_ATOMICOPERATIONS_CLANG_ATOMICS
#endif
#endif

#if defined(LLCL_ATOMICOPERATIONS_CLANG_ATOMICS)
#include "llcl/Standard/System/AtomicOperationsClangIntrinsics.h"
#endif

namespace llcl {
namespace standard {

// 'AtomicOperations' provides a namespace for a suite of atomic operations
// on the following types as defined by the 'AtomicTypes'
struct AtomicOperations {
  typedef AtomicOperationsImpl Imp;
  typedef AtomicTypeTraits<Imp> AtomicTypes;

  // Atomically retrieve the value of the specified 'atomic_int',
  // providing the sequential consistency memory ordering guarantee.
  static int getInt(AtomicTypes::Int const* atomic_int);

  // Atomically retrieve the value of the specified 'atomic_int',
  // providing the acquire memory ordering guarantee.
  static int getIntAcquire(AtomicTypes::Int const* atomic_int);

  // Atomically retrieve the value of the specified 'atomic_int', without
  // providing any memory ordering guarantees.
  static int getIntRelaxed(AtomicTypes::Int const* atomic_int);

  // Initialize the specified 'atomic_int' and set its value to the
  // optionally specified 'initial_value'.
  static void initInt(AtomicTypes::Int* atomic_int, int initial_value = 0);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', providing the sequential consistency memory
  // ordering guarantee.
  static void setInt(AtomicTypes::Int* atomic_int, int value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', without providing any memory ordering guarantees.
  static void setIntRelaxed(AtomicTypes::Int* atomic_int, int value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', providing the release memory ordering guarantee.
  static void setIntRelease(AtomicTypes::Int* atomic_int, int value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'swap_value', and return its previous value, providing the
  // sequential consistency memory ordering guarantee.
  static int swapInt(AtomicTypes::Int* atomic_int, int swap_value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'swap_value', and return its previous value, providing the
  // acquire/release memory ordering guarantee.
  static int swapIntAcqRel(AtomicTypes::Int* atomic_int, int swap_value);

  // Conditionally set the value of the specified 'atomic_int' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_int', providing the sequential consistency memory
  // ordering guarantee.  The whole operation is performed atomically.
  static int testAndSwapInt(AtomicTypes::Int* atomic_int, int compare_value,
                            int swap_value);

  // Conditionally set the value of the specified 'atomic_int' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_int', providing the acquire/release memory ordering
  // guarantee.  The whole operation is performed atomically.
  static int testAndSwapIntAcqRel(AtomicTypes::Int* atomic_int,
                                  int compare_value, int swap_value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // providing the sequential consistency memory ordering guarantee.
  static void addInt(AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // providing the acquire/release memory ordering guarantee.
  static void addIntAcqRel(AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // without providing any memory ordering guarantees.
  static void addIntRelaxed(AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, providing the sequential consistency
  // memory ordering guarantee.
  static int addIntNv(AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  static int addIntNvAcqRel(AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, without providing any memory
  // ordering guarantees.
  static int addIntNvRelaxed(AtomicTypes::Int* atomic_int, int value);

  // Atomically decrement the value of the specified 'atomic_int' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void decrementInt(AtomicTypes::Int* atomic_int);

  // Atomically decrement the value of the specified 'atomic_int' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void decrementIntAcqRel(AtomicTypes::Int* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static int decrementIntNv(AtomicTypes::Int* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static int decrementIntNvAcqRel(AtomicTypes::Int* atomic_int);

  // Atomically increment the value of the specified 'atomic_int' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void incrementInt(AtomicTypes::Int* atomic_int);

  // Atomically increment the value of the specified 'atomic_int' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void incrementIntAcqRel(AtomicTypes::Int* atomic_int);

  // Atomically increment the specified 'atomic_int' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static int incrementIntNv(AtomicTypes::Int* atomic_int);

  // Atomically increment the specified 'atomic_int' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static int incrementIntNvAcqRel(AtomicTypes::Int* atomic_int);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, providing the sequential
  // consistency memory ordering guarantee.
  static int subtractIntNv(AtomicTypes::Int* atomic_int, int value);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, providing the
  // acquire/release memory ordering guarantee.
  static int subtractIntNvAcqRel(AtomicTypes::Int* atomic_int, int value);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, without providing any memory
  // ordering guarantees.
  static int subtractIntNvRelaxed(AtomicTypes::Int* atomic_int, int value);

  // Atomically retrieve the value of the specified 'atomic_int',
  // providing the sequential consistency memory ordering guarantee.
  static Types::Int64 getInt64(AtomicTypes::Int64 const* atomic_int);

  // Atomically retrieve the value of the specified 'atomic_int',
  // providing the acquire memory ordering guarantee.
  static Types::Int64 getInt64Acquire(AtomicTypes::Int64 const* atomic_int);

  // Atomically retrieve the value of the specified 'atomic_int', without
  // providing any memory ordering guarantees.
  static Types::Int64 getInt64Relaxed(AtomicTypes::Int64 const* atomic_int);

  // Initialize the specified 'atomic_int' and set its value to the
  // optionally specified 'initial_value'.
  static void initInt64(AtomicTypes::Int64* atomic_int,
                        Types::Int64 initial_value = 0);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', providing the sequential consistency memory
  // ordering guarantee.
  static void setInt64(AtomicTypes::Int64* atomic_int, Types::Int64 value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', without providing any memory ordering guarantees.
  static void setInt64Relaxed(AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', providing the release memory ordering guarantee.
  static void setInt64Release(AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'swap_value' and return its previous value, providing the
  // sequential consistency memory ordering guarantee.
  static Types::Int64 swapInt64(AtomicTypes::Int64* atomic_int,
                                Types::Int64 swap_value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'swap_value' and return its previous value, providing the
  // acquire/release memory ordering guarantee.
  static Types::Int64 swapInt64AcqRel(AtomicTypes::Int64* atomic_int,
                                      Types::Int64 swap_value);

  // Conditionally set the value of the specified 'atomic_int' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_int', providing the sequential consistency memory
  // ordering guarantee.  The whole operation is performed atomically.
  static Types::Int64 testAndSwapInt64(AtomicTypes::Int64* atomic_int,
                                       Types::Int64 compare_value,
                                       Types::Int64 swap_value);

  // Conditionally set the value of the specified 'atomic_int' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_int', providing the acquire/release memory ordering
  // guarantee.  The whole operation is performed atomically.
  static Types::Int64 testAndSwapInt64AcqRel(AtomicTypes::Int64* atomic_int,
                                             Types::Int64 compare_value,
                                             Types::Int64 swap_value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // providing the sequential consistency memory ordering guarantee.
  static void addInt64(AtomicTypes::Int64* atomic_int, Types::Int64 value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // providing the acquire/release memory ordering guarantee.
  static void addInt64AcqRel(AtomicTypes::Int64* atomic_int,
                             Types::Int64 value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // without providing any memory ordering guarantees.
  static void addInt64Relaxed(AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, providing the sequential consistency
  // memory ordering guarantee.
  static Types::Int64 addInt64Nv(AtomicTypes::Int64* atomic_int,
                                 Types::Int64 value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  static Types::Int64 addInt64NvAcqRel(AtomicTypes::Int64* atomic_int,
                                       Types::Int64 value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, without providing any memory
  // ordering guarantees.
  static Types::Int64 addInt64NvRelaxed(AtomicTypes::Int64* atomic_int,
                                        Types::Int64 value);

  // Atomically decrement the specified 'atomic_int' by 1, providing the
  // sequential consistency memory ordering guarantee.
  static void decrementInt64(AtomicTypes::Int64* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1, providing the
  // acquire/release memory ordering guarantee.
  static void decrementInt64AcqRel(AtomicTypes::Int64* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static Types::Int64 decrementInt64Nv(AtomicTypes::Int64* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static Types::Int64 decrementInt64NvAcqRel(AtomicTypes::Int64* atomic_int);

  // Atomically increment the value of the specified 'atomic_int' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void incrementInt64(AtomicTypes::Int64* atomic_int);

  // Atomically increment the value of the specified 'atomic_int' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void incrementInt64AcqRel(AtomicTypes::Int64* atomic_int);

  // Atomically increment the specified 'atomic_int' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static Types::Int64 incrementInt64Nv(AtomicTypes::Int64* atomic_int);

  // Atomically increment the specified 'atomic_int' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static Types::Int64 incrementInt64NvAcqRel(AtomicTypes::Int64* atomic_int);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, providing the sequential
  // consistency memory ordering guarantee.
  static Types::Int64 subtractInt64Nv(AtomicTypes::Int64* atomic_int,
                                      Types::Int64 value);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, providing the
  // acquire/release memory ordering guarantee.
  static Types::Int64 subtractInt64NvAcqRel(AtomicTypes::Int64* atomic_int,
                                            Types::Int64 value);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, without providing any memory
  // ordering guarantees.
  static Types::Int64 subtractInt64NvRelaxed(AtomicTypes::Int64* atomic_int,
                                             Types::Int64 value);

  // Atomically retrieve the value of the specified 'atomic_uint',
  // providing the sequential consistency memory ordering guarantee.
  static unsigned int getUint(AtomicTypes::Uint const* atomic_uint);

  // Atomically retrieve the value of the specified 'atomic_uint',
  // providing the acquire memory ordering guarantee.
  static unsigned int getUintAcquire(AtomicTypes::Uint const* atomic_uint);

  // Atomically retrieve the value of the specified 'atomic_uint', without
  // providing any memory ordering guarantees.
  static unsigned int getUintRelaxed(AtomicTypes::Uint const* atomic_uint);

  // Initialize the specified 'atomic_uint' and set its value to the
  // optionally specified 'initial_value'.
  static void initUint(AtomicTypes::Uint* atomic_uint,
                       unsigned int initial_value = 0);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'value', providing the sequential consistency memory
  // ordering guarantee.
  static void setUint(AtomicTypes::Uint* atomic_uint, unsigned int value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'value', without providing any memory ordering guarantees.
  static void setUintRelaxed(AtomicTypes::Uint* atomic_uint,
                             unsigned int value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'value', providing the release memory ordering guarantee.
  static void setUintRelease(AtomicTypes::Uint* atomic_uint,
                             unsigned int value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'swap_value', and return its previous value, providing the
  // sequential consistency memory ordering guarantee.
  static unsigned int swapUint(AtomicTypes::Uint* atomic_uint,
                               unsigned int swap_value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'swap_value', and return its previous value, providing the
  // acquire/release memory ordering guarantee.
  static unsigned int swapUintAcqRel(AtomicTypes::Uint* atomic_uint,
                                     unsigned int swap_value);

  // Conditionally set the value of the specified 'atomic_uint' to the
  // specified 'swap_value' if and only if the value of 'atomic_uint'
  // equals the value of the specified 'compare_value', and return the
  // initial value of 'atomic_uint', providing the sequential consistency
  // memory ordering guarantee.  The whole operation is performed
  // atomically.
  static unsigned int testAndSwapUint(AtomicTypes::Uint* atomic_uint,
                                      unsigned int compare_value,
                                      unsigned int swap_value);

  // Conditionally set the value of the specified 'atomic_uint' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_uint', providing the acquire/release memory ordering
  // guarantee.  The whole operation is performed atomically.
  static unsigned int testAndSwapUintAcqRel(AtomicTypes::Uint* atomic_uint,
                                            unsigned int compare_value,
                                            unsigned int swap_value);

  // Atomically add to the specified 'atomic_uint' the specified 'value',
  // providing the sequential consistency memory ordering guarantee.
  static void addUint(AtomicTypes::Uint* atomic_uint, unsigned int value);

  // Atomically add to the specified 'atomic_uint' the specified 'value',
  // providing the acquire/release memory ordering guarantee.
  static void addUintAcqRel(AtomicTypes::Uint* atomic_uint, unsigned int value);

  // Atomically add to the specified 'atomic_uint' the specified 'value',
  // without providing any memory ordering guarantees.
  static void addUintRelaxed(AtomicTypes::Uint* atomic_uint,
                             unsigned int value);

  // Atomically add to the specified 'atomic_uint' the specified 'value'
  // and return the resulting value, providing the sequential consistency
  // memory ordering guarantee.
  static unsigned int addUintNv(AtomicTypes::Uint* atomic_uint,
                                unsigned int value);

  // Atomically add to the specified 'atomic_uint' the specified 'value'
  // and return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  static unsigned int addUintNvAcqRel(AtomicTypes::Uint* atomic_uint,
                                      unsigned int value);

  // Atomically add to the specified 'atomic_uint' the specified 'value'
  // and return the resulting value, without providing any memory
  // ordering guarantees.
  static unsigned int addUintNvRelaxed(AtomicTypes::Uint* atomic_uint,
                                       unsigned int value);

  // Atomically decrement the value of the specified 'atomic_uint' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void decrementUint(AtomicTypes::Uint* atomic_uint);

  // Atomically decrement the value of the specified 'atomic_uint' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void decrementUintAcqRel(AtomicTypes::Uint* atomic_uint);

  // Atomically decrement the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static unsigned int decrementUintNv(AtomicTypes::Uint* atomic_uint);

  // Atomically decrement the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static unsigned int decrementUintNvAcqRel(AtomicTypes::Uint* atomic_uint);

  // Atomically increment the value of the specified 'atomic_uint' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void incrementUint(AtomicTypes::Uint* atomic_uint);

  // Atomically increment the value of the specified 'atomic_uint' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void incrementUintAcqRel(AtomicTypes::Uint* atomic_uint);

  // Atomically increment the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static unsigned int incrementUintNv(AtomicTypes::Uint* atomic_uint);

  // Atomically increment the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static unsigned int incrementUintNvAcqRel(AtomicTypes::Uint* atomic_uint);

  // Atomically subtract from the specified 'atomic_uint' the specified
  // 'value' and return the resulting value, providing the sequential
  // consistency memory ordering guarantee.
  static unsigned int subtractUintNv(AtomicTypes::Uint* atomic_uint,
                                     unsigned int value);

  // Atomically subtract from the specified 'atomic_uint' the specified
  // 'value' and return the resulting value, providing the
  // acquire/release memory ordering guarantee.
  static unsigned int subtractUintNvAcqRel(AtomicTypes::Uint* atomic_uint,
                                           unsigned int value);

  // Atomically subtract from the specified 'atomic_uint' the specified
  // 'value' and return the resulting value, without providing any memory
  // ordering guarantees.
  static unsigned int subtractUintNvRelaxed(AtomicTypes::Uint* atomic_uint,
                                            unsigned int value);

  // Atomically retrieve the value of the specified 'atomic_uint',
  // providing the sequential consistency memory ordering guarantee.
  static Types::Uint64 getUint64(AtomicTypes::Uint64 const* atomic_uint);

  // Atomically retrieve the value of the specified 'atomic_uint',
  // providing the acquire memory ordering guarantee.
  static Types::Uint64 getUint64Acquire(AtomicTypes::Uint64 const* atomic_uint);

  // Atomically retrieve the value of the specified 'atomic_uint', without
  // providing any memory ordering guarantees.
  static Types::Uint64 getUint64Relaxed(AtomicTypes::Uint64 const* atomic_uint);

  // Initialize the specified 'atomic_uint' and set its value to the
  // optionally specified 'initial_value'.
  static void initUint64(AtomicTypes::Uint64* atomic_uint,
                         Types::Uint64 initial_value = 0);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'value', providing the sequential consistency memory
  // ordering guarantee.
  static void setUint64(AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'value', without providing any memory ordering guarantees.
  static void setUint64Relaxed(AtomicTypes::Uint64* atomic_uint,
                               Types::Uint64 value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'value', providing the release memory ordering guarantee.
  static void setUint64Release(AtomicTypes::Uint64* atomic_uint,
                               Types::Uint64 value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'swap_value' and return its previous value, providing the
  // sequential consistency memory ordering guarantee.
  static Types::Uint64 swapUint64(AtomicTypes::Uint64* atomic_uint,
                                  Types::Uint64 swap_value);

  // Atomically set the value of the specified 'atomic_uint' to the
  // specified 'swap_value' and return its previous value, providing the
  // acquire/release memory ordering guarantee.
  static Types::Uint64 swapUint64AcqRel(AtomicTypes::Uint64* atomic_uint,
                                        Types::Uint64 swap_value);

  // Conditionally set the value of the specified 'atomic_uint' to the
  // specified 'swap_value' if and only if the value of 'atomic_uint'
  // equals the value of the specified 'compare_value', and return the
  // initial value of 'atomic_uint', providing the sequential consistency
  // memory ordering guarantee.  The whole operation is performed
  // atomically.
  static Types::Uint64 testAndSwapUint64(AtomicTypes::Uint64* atomic_uint,
                                         Types::Uint64 compare_value,
                                         Types::Uint64 swap_value);

  // Conditionally set the value of the specified 'atomic_uint' to the
  // specified 'swap_value' if and only if the value of 'atomic_uint'
  // equals the value of the specified 'compare_value', and return the
  // initial value of 'atomic_uint', providing the acquire/release memory
  // ordering guarantee.  The whole operation is performed atomically.
  static Types::Uint64 testAndSwapUint64AcqRel(AtomicTypes::Uint64* atomic_uint,
                                               Types::Uint64 compare_value,
                                               Types::Uint64 swap_value);

  // Atomically add to the specified 'atomic_uint' the specified 'value',
  // providing the sequential consistency memory ordering guarantee.
  static void addUint64(AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);

  // Atomically add to the specified 'atomic_uint' the specified 'value',
  // providing the acquire/release memory ordering guarantee.
  static void addUint64AcqRel(AtomicTypes::Uint64* atomic_uint,
                              Types::Uint64 value);

  // Atomically add to the specified 'atomic_uint' the specified 'value',
  // without providing any memory ordering guarantees.
  static void addUint64Relaxed(AtomicTypes::Uint64* atomic_uint,
                               Types::Uint64 value);

  // Atomically add to the specified 'atomic_uint' the specified 'value'
  // and return the resulting value, providing the sequential consistency
  // memory ordering guarantee.
  static Types::Uint64 addUint64Nv(AtomicTypes::Uint64* atomic_uint,
                                   Types::Uint64 value);

  // Atomically add to the specified 'atomic_uint' the specified 'value'
  // and return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  static Types::Uint64 addUint64NvAcqRel(AtomicTypes::Uint64* atomic_uint,
                                         Types::Uint64 value);

  // Atomically add to the specified 'atomic_uint' the specified 'value'
  // and return the resulting value, without providing any memory
  // ordering guarantees.
  static Types::Uint64 addUint64NvRelaxed(AtomicTypes::Uint64* atomic_uint,
                                          Types::Uint64 value);

  // Atomically decrement the specified 'atomic_uint' by 1, providing the
  // sequential consistency memory ordering guarantee.
  static void decrementUint64(AtomicTypes::Uint64* atomic_uint);

  // Atomically decrement the specified 'atomic_uint' by 1, providing the
  // acquire/release memory ordering guarantee.
  static void decrementUint64AcqRel(AtomicTypes::Uint64* atomic_uint);

  // Atomically decrement the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static Types::Uint64 decrementUint64Nv(AtomicTypes::Uint64* atomic_uint);

  // Atomically decrement the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static Types::Uint64 decrementUint64NvAcqRel(
      AtomicTypes::Uint64* atomic_uint);

  // Atomically increment the value of the specified 'atomic_uint' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void incrementUint64(AtomicTypes::Uint64* atomic_uint);

  // Atomically increment the value of the specified 'atomic_uint' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void incrementUint64AcqRel(AtomicTypes::Uint64* atomic_uint);

  // Atomically increment the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static Types::Uint64 incrementUint64Nv(AtomicTypes::Uint64* atomic_uint);

  // Atomically increment the specified 'atomic_uint' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static Types::Uint64 incrementUint64NvAcqRel(
      AtomicTypes::Uint64* atomic_uint);

  // Atomically subtract from the specified 'atomic_uint' the specified
  // 'value' and return the resulting value, providing the sequential
  // consistency memory ordering guarantee.
  static Types::Uint64 subtractUint64Nv(AtomicTypes::Uint64* atomic_uint,
                                        Types::Uint64 value);

  // Atomically subtract from the specified 'atomic_uint' the specified
  // 'value' and return the resulting value, providing the
  // acquire/release memory ordering guarantee.
  static Types::Uint64 subtractUint64NvAcqRel(AtomicTypes::Uint64* atomic_uint,
                                              Types::Uint64 value);

  // Atomically subtract from the specified 'atomic_uint' the specified
  // 'value' and return the resulting value, without providing any memory
  // ordering guarantees.
  static Types::Uint64 subtractUint64NvRelaxed(AtomicTypes::Uint64* atomic_uint,
                                               Types::Uint64 value);

  // Atomically retrieve the value of the specified 'atomic_ptr',
  // providing the sequential consistency memory ordering guarantee.
  static void* getPtr(AtomicTypes::Pointer const* atomic_ptr);

  // Atomically retrieve the value of the specified 'atomic_ptr',
  // providing the acquire memory ordering guarantee.
  static void* getPtrAcquire(AtomicTypes::Pointer const* atomic_ptr);

  // Atomically retrieve the value of the specified 'atomic_ptr', without
  // providing any memory ordering guarantees.
  static void* getPtrRelaxed(AtomicTypes::Pointer const* atomic_ptr);

  // Initialize the specified 'atomic_ptr' and set its value to the
  // optionally specified 'initial_value'.
  static void initPointer(AtomicTypes::Pointer* atomic_ptr,
                          void* initial_value = 0);

  // Atomically set the value of the specified 'atomic_ptr' to the
  // specified 'value', providing the sequential consistency memory
  // ordering guarantee.
  static void setPtr(AtomicTypes::Pointer* atomic_ptr, void* value);

  // Atomically set the value of the specified 'atomic_ptr' to the
  // specified 'value', without providing any memory ordering guarantees.
  static void setPtrRelaxed(AtomicTypes::Pointer* atomic_ptr, void* value);

  // Atomically set the value of the specified 'atomic_ptr' to the
  // specified 'value', providing the release memory ordering guarantee.
  static void setPtrRelease(AtomicTypes::Pointer* atomic_ptr, void* value);

  // Atomically set the value of the specified 'atomic_ptr' to the
  // specified 'swap_value', and return its previous value, providing the
  // sequential consistency memory ordering guarantee.
  static void* swapPtr(AtomicTypes::Pointer* atomic_ptr, void* swap_value);

  // Atomically set the value of the specified 'atomic_ptr' to the
  // specified 'swap_value', and return its previous value, providing the
  // acquire/release memory ordering guarantee.
  static void* swapPtrAcqRel(AtomicTypes::Pointer* atomic_ptr,
                             void* swap_value);

  // Conditionally set the value of the specified 'atomic_ptr' to the
  // specified 'swap_value' if and only if the value of 'atomic_ptr' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_ptr', providing the sequential consistency memory
  // ordering guarantee.  The whole operation is performed atomically.
  static void* testAndSwapPtr(AtomicTypes::Pointer* atomic_ptr,
                              void* compare_value, void* swap_value);

  // Conditionally set the value of the specified 'atomic_ptr' to the
  // specified 'swap_value' if and only if the value of 'atomic_ptr' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_ptr', providing the acquire/release memory ordering
  // guarantee.  The whole operation is performed atomically.
  static void* testAndSwapPtrAcqRel(AtomicTypes::Pointer* atomic_ptr,
                                    void* compare_value, void* swap_value);
};

inline int AtomicOperations::getInt(AtomicTypes::Int const* atomic_int) {
  return Imp::getInt(atomic_int);
}

inline int AtomicOperations::getIntAcquire(AtomicTypes::Int const* atomic_int) {
  return Imp::getIntAcquire(atomic_int);
}

inline int AtomicOperations::getIntRelaxed(AtomicTypes::Int const* atomic_int) {
  return Imp::getIntRelaxed(atomic_int);
}

inline void AtomicOperations::initInt(AtomicTypes::Int* atomic_int,
                                      int initial_value) {
  Imp::initInt(atomic_int, initial_value);
}

inline void AtomicOperations::setInt(AtomicTypes::Int* atomic_int, int value) {
  Imp::setInt(atomic_int, value);
}

inline void AtomicOperations::setIntRelaxed(AtomicTypes::Int* atomic_int,
                                            int value) {
  Imp::setIntRelaxed(atomic_int, value);
}

inline void AtomicOperations::setIntRelease(AtomicTypes::Int* atomic_int,
                                            int value) {
  Imp::setIntRelease(atomic_int, value);
}

inline int AtomicOperations::swapInt(AtomicTypes::Int* atomic_int,
                                     int swap_value) {
  return Imp::swapInt(atomic_int, swap_value);
}

inline int AtomicOperations::swapIntAcqRel(AtomicTypes::Int* atomic_int,
                                           int swap_value) {
  return Imp::swapIntAcqRel(atomic_int, swap_value);
}

inline int AtomicOperations::testAndSwapInt(AtomicTypes::Int* atomic_int,
                                            int compare_value, int swap_value) {
  return Imp::testAndSwapInt(atomic_int, compare_value, swap_value);
}

inline int AtomicOperations::testAndSwapIntAcqRel(AtomicTypes::Int* atomic_int,
                                                  int compare_value,
                                                  int swap_value) {
  return Imp::testAndSwapIntAcqRel(atomic_int, compare_value, swap_value);
}

// *** atomic arithmetic functions for int ***

inline void AtomicOperations::addInt(AtomicTypes::Int* atomic_int, int value) {
  Imp::addInt(atomic_int, value);
}

inline void AtomicOperations::addIntAcqRel(AtomicTypes::Int* atomic_int,
                                           int value) {
  Imp::addIntAcqRel(atomic_int, value);
}

inline void AtomicOperations::addIntRelaxed(AtomicTypes::Int* atomic_int,
                                            int value) {
  Imp::addIntRelaxed(atomic_int, value);
}

inline int AtomicOperations::addIntNv(AtomicTypes::Int* atomic_int, int value) {
  return Imp::addIntNv(atomic_int, value);
}

inline int AtomicOperations::addIntNvAcqRel(AtomicTypes::Int* atomic_int,
                                            int value) {
  return Imp::addIntNvAcqRel(atomic_int, value);
}

inline int AtomicOperations::addIntNvRelaxed(AtomicTypes::Int* atomic_int,
                                             int value) {
  return Imp::addIntNvRelaxed(atomic_int, value);
}

inline void AtomicOperations::decrementInt(AtomicTypes::Int* atomic_int) {
  Imp::decrementInt(atomic_int);
}

inline void AtomicOperations::decrementIntAcqRel(AtomicTypes::Int* atomic_int) {
  Imp::decrementIntAcqRel(atomic_int);
}

inline int AtomicOperations::decrementIntNv(AtomicTypes::Int* atomic_int) {
  return Imp::decrementIntNv(atomic_int);
}

inline int AtomicOperations::decrementIntNvAcqRel(
    AtomicTypes::Int* atomic_int) {
  return Imp::decrementIntNvAcqRel(atomic_int);
}

inline void AtomicOperations::incrementInt(AtomicTypes::Int* atomic_int) {
  Imp::incrementInt(atomic_int);
}

inline void AtomicOperations::incrementIntAcqRel(AtomicTypes::Int* atomic_int) {
  Imp::incrementIntAcqRel(atomic_int);
}

inline int AtomicOperations::incrementIntNv(AtomicTypes::Int* atomic_int) {
  return Imp::incrementIntNv(atomic_int);
}

inline int AtomicOperations::incrementIntNvAcqRel(
    AtomicTypes::Int* atomic_int) {
  return Imp::incrementIntNvAcqRel(atomic_int);
}

inline int AtomicOperations::subtractIntNv(AtomicTypes::Int* atomic_int,
                                           int value) {
  return Imp::subtractIntNv(atomic_int, value);
}

inline int AtomicOperations::subtractIntNvAcqRel(AtomicTypes::Int* atomic_int,
                                                 int value) {
  return Imp::subtractIntNvAcqRel(atomic_int, value);
}

inline int AtomicOperations::subtractIntNvRelaxed(AtomicTypes::Int* atomic_int,
                                                  int value) {
  return Imp::subtractIntNvRelaxed(atomic_int, value);
}

// *** atomic functions for Int64 ***

inline Types::Int64 AtomicOperations::getInt64(
    AtomicTypes::Int64 const* atomic_int) {
  return Imp::getInt64(atomic_int);
}

inline Types::Int64 AtomicOperations::getInt64Acquire(
    AtomicTypes::Int64 const* atomic_int) {
  return Imp::getInt64Acquire(atomic_int);
}

inline Types::Int64 AtomicOperations::getInt64Relaxed(
    AtomicTypes::Int64 const* atomic_int) {
  return Imp::getInt64Relaxed(atomic_int);
}

inline void AtomicOperations::initInt64(AtomicTypes::Int64* atomic_int,
                                        Types::Int64 initial_value) {
  Imp::initInt64(atomic_int, initial_value);
}

inline void AtomicOperations::setInt64(AtomicTypes::Int64* atomic_int,
                                       Types::Int64 value) {
  Imp::setInt64(atomic_int, value);
}

inline void AtomicOperations::setInt64Relaxed(AtomicTypes::Int64* atomic_int,
                                              Types::Int64 value) {
  Imp::setInt64Relaxed(atomic_int, value);
}

inline void AtomicOperations::setInt64Release(AtomicTypes::Int64* atomic_int,
                                              Types::Int64 value) {
  Imp::setInt64Release(atomic_int, value);
}

inline Types::Int64 AtomicOperations::swapInt64(AtomicTypes::Int64* atomic_int,
                                                Types::Int64 swap_value) {
  return Imp::swapInt64(atomic_int, swap_value);
}

inline Types::Int64 AtomicOperations::swapInt64AcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 swap_value) {
  return Imp::swapInt64AcqRel(atomic_int, swap_value);
}

inline Types::Int64 AtomicOperations::testAndSwapInt64(
    AtomicTypes::Int64* atomic_int, Types::Int64 compare_value,
    Types::Int64 swap_value) {
  return Imp::testAndSwapInt64(atomic_int, compare_value, swap_value);
}

inline Types::Int64 AtomicOperations::testAndSwapInt64AcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 compare_value,
    Types::Int64 swap_value) {
  return Imp::testAndSwapInt64AcqRel(atomic_int, compare_value, swap_value);
}

// *** atomic arithmetic functions for Int64 ***

inline void AtomicOperations::addInt64(AtomicTypes::Int64* atomic_int,
                                       Types::Int64 value) {
  Imp::addInt64(atomic_int, value);
}

inline void AtomicOperations::addInt64AcqRel(AtomicTypes::Int64* atomic_int,
                                             Types::Int64 value) {
  Imp::addInt64AcqRel(atomic_int, value);
}

inline void AtomicOperations::addInt64Relaxed(AtomicTypes::Int64* atomic_int,
                                              Types::Int64 value) {
  Imp::addInt64Relaxed(atomic_int, value);
}

inline Types::Int64 AtomicOperations::addInt64Nv(AtomicTypes::Int64* atomic_int,
                                                 Types::Int64 value) {
  return Imp::addInt64Nv(atomic_int, value);
}

inline Types::Int64 AtomicOperations::addInt64NvAcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return Imp::addInt64NvAcqRel(atomic_int, value);
}

inline Types::Int64 AtomicOperations::addInt64NvRelaxed(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return Imp::addInt64NvRelaxed(atomic_int, value);
}

inline void AtomicOperations::decrementInt64(AtomicTypes::Int64* atomic_int) {
  Imp::decrementInt64(atomic_int);
}

inline void AtomicOperations::decrementInt64AcqRel(
    AtomicTypes::Int64* atomic_int) {
  Imp::decrementInt64AcqRel(atomic_int);
}

inline Types::Int64 AtomicOperations::decrementInt64Nv(
    AtomicTypes::Int64* atomic_int) {
  return Imp::decrementInt64Nv(atomic_int);
}

inline Types::Int64 AtomicOperations::decrementInt64NvAcqRel(
    AtomicTypes::Int64* atomic_int) {
  return Imp::decrementInt64NvAcqRel(atomic_int);
}

inline void AtomicOperations::incrementInt64(AtomicTypes::Int64* atomic_int) {
  Imp::incrementInt64(atomic_int);
}

inline void AtomicOperations::incrementInt64AcqRel(
    AtomicTypes::Int64* atomic_int) {
  Imp::incrementInt64AcqRel(atomic_int);
}

inline Types::Int64 AtomicOperations::incrementInt64Nv(
    AtomicTypes::Int64* atomic_int) {
  return Imp::incrementInt64Nv(atomic_int);
}

inline Types::Int64 AtomicOperations::incrementInt64NvAcqRel(
    AtomicTypes::Int64* atomic_int) {
  return Imp::incrementInt64NvAcqRel(atomic_int);
}

inline Types::Int64 AtomicOperations::subtractInt64Nv(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return Imp::subtractInt64Nv(atomic_int, value);
}

inline Types::Int64 AtomicOperations::subtractInt64NvAcqRel(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return Imp::subtractInt64NvAcqRel(atomic_int, value);
}

inline Types::Int64 AtomicOperations::subtractInt64NvRelaxed(
    AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return Imp::subtractInt64NvRelaxed(atomic_int, value);
}

// *** atomic functions for unsigned int ***

inline unsigned int AtomicOperations::getUint(
    AtomicTypes::Uint const* atomic_uint) {
  return Imp::getUint(atomic_uint);
}

inline unsigned int AtomicOperations::getUintAcquire(
    AtomicTypes::Uint const* atomic_uint) {
  return Imp::getUintAcquire(atomic_uint);
}

inline unsigned int AtomicOperations::getUintRelaxed(
    AtomicTypes::Uint const* atomic_uint) {
  return Imp::getUintRelaxed(atomic_uint);
}

inline void AtomicOperations::initUint(AtomicTypes::Uint* atomic_uint,
                                       unsigned int initial_value) {
  Imp::initUint(atomic_uint, initial_value);
}

inline void AtomicOperations::setUint(AtomicTypes::Uint* atomic_uint,
                                      unsigned int value) {
  Imp::setUint(atomic_uint, value);
}

inline void AtomicOperations::setUintRelaxed(AtomicTypes::Uint* atomic_uint,
                                             unsigned int value) {
  Imp::setUintRelaxed(atomic_uint, value);
}

inline void AtomicOperations::setUintRelease(AtomicTypes::Uint* atomic_uint,
                                             unsigned int value) {
  Imp::setUintRelease(atomic_uint, value);
}

inline unsigned int AtomicOperations::swapUint(AtomicTypes::Uint* atomic_uint,
                                               unsigned int swap_value) {
  return Imp::swapUint(atomic_uint, swap_value);
}

inline unsigned int AtomicOperations::swapUintAcqRel(
    AtomicTypes::Uint* atomic_uint, unsigned int swap_value) {
  return Imp::swapUintAcqRel(atomic_uint, swap_value);
}

inline unsigned int AtomicOperations::testAndSwapUint(
    AtomicTypes::Uint* atomic_uint, unsigned int compare_value,
    unsigned int swap_value) {
  return Imp::testAndSwapUint(atomic_uint, compare_value, swap_value);
}

inline unsigned int AtomicOperations::testAndSwapUintAcqRel(
    AtomicTypes::Uint* atomic_uint, unsigned int compare_value,
    unsigned int swap_value) {
  return Imp::testAndSwapUintAcqRel(atomic_uint, compare_value, swap_value);
}

// *** atomic arithmetic functions for unsigned int ***

inline void AtomicOperations::addUint(AtomicTypes::Uint* atomic_uint,
                                      unsigned int value) {
  Imp::addUint(atomic_uint, value);
}

inline void AtomicOperations::addUintAcqRel(AtomicTypes::Uint* atomic_uint,
                                            unsigned int value) {
  Imp::addUintAcqRel(atomic_uint, value);
}

inline void AtomicOperations::addUintRelaxed(AtomicTypes::Uint* atomic_uint,
                                             unsigned int value) {
  Imp::addUintRelaxed(atomic_uint, value);
}

inline unsigned int AtomicOperations::addUintNv(AtomicTypes::Uint* atomic_uint,
                                                unsigned int value) {
  return Imp::addUintNv(atomic_uint, value);
}

inline unsigned int AtomicOperations::addUintNvAcqRel(
    AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return Imp::addUintNvAcqRel(atomic_uint, value);
}

inline unsigned int AtomicOperations::addUintNvRelaxed(
    AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return Imp::addUintNvRelaxed(atomic_uint, value);
}

inline void AtomicOperations::decrementUint(AtomicTypes::Uint* atomic_uint) {
  Imp::decrementUint(atomic_uint);
}

inline void AtomicOperations::decrementUintAcqRel(
    AtomicTypes::Uint* atomic_uint) {
  Imp::decrementUintAcqRel(atomic_uint);
}

inline unsigned int AtomicOperations::decrementUintNv(
    AtomicTypes::Uint* atomic_uint) {
  return Imp::decrementUintNv(atomic_uint);
}

inline unsigned int AtomicOperations::decrementUintNvAcqRel(
    AtomicTypes::Uint* atomic_uint) {
  return Imp::decrementUintNvAcqRel(atomic_uint);
}

inline void AtomicOperations::incrementUint(AtomicTypes::Uint* atomic_uint) {
  Imp::incrementUint(atomic_uint);
}

inline void AtomicOperations::incrementUintAcqRel(
    AtomicTypes::Uint* atomic_uint) {
  Imp::incrementUintAcqRel(atomic_uint);
}

inline unsigned int AtomicOperations::incrementUintNv(
    AtomicTypes::Uint* atomic_uint) {
  return Imp::incrementUintNv(atomic_uint);
}

inline unsigned int AtomicOperations::incrementUintNvAcqRel(
    AtomicTypes::Uint* atomic_uint) {
  return Imp::incrementUintNvAcqRel(atomic_uint);
}

inline unsigned int AtomicOperations::subtractUintNv(
    AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return Imp::subtractUintNv(atomic_uint, value);
}

inline unsigned int AtomicOperations::subtractUintNvAcqRel(
    AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return Imp::subtractUintNvAcqRel(atomic_uint, value);
}

inline unsigned int AtomicOperations::subtractUintNvRelaxed(
    AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return Imp::subtractUintNvRelaxed(atomic_uint, value);
}

// *** atomic functions for Uint64 ***

inline Types::Uint64 AtomicOperations::getUint64(
    AtomicTypes::Uint64 const* atomic_uint) {
  return Imp::getUint64(atomic_uint);
}

inline Types::Uint64 AtomicOperations::getUint64Acquire(
    AtomicTypes::Uint64 const* atomic_uint) {
  return Imp::getUint64Acquire(atomic_uint);
}

inline Types::Uint64 AtomicOperations::getUint64Relaxed(
    AtomicTypes::Uint64 const* atomic_uint) {
  return Imp::getUint64Relaxed(atomic_uint);
}

inline void AtomicOperations::initUint64(AtomicTypes::Uint64* atomic_uint,
                                         Types::Uint64 initial_value) {
  Imp::initUint64(atomic_uint, initial_value);
}

inline void AtomicOperations::setUint64(AtomicTypes::Uint64* atomic_uint,
                                        Types::Uint64 value) {
  Imp::setUint64(atomic_uint, value);
}

inline void AtomicOperations::setUint64Relaxed(AtomicTypes::Uint64* atomic_uint,
                                               Types::Uint64 value) {
  Imp::setUint64Relaxed(atomic_uint, value);
}

inline void AtomicOperations::setUint64Release(AtomicTypes::Uint64* atomic_uint,
                                               Types::Uint64 value) {
  Imp::setUint64Release(atomic_uint, value);
}

inline Types::Uint64 AtomicOperations::swapUint64(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 swap_value) {
  return Imp::swapUint64(atomic_uint, swap_value);
}

inline Types::Uint64 AtomicOperations::swapUint64AcqRel(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 swap_value) {
  return Imp::swapUint64AcqRel(atomic_uint, swap_value);
}

inline Types::Uint64 AtomicOperations::testAndSwapUint64(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 compare_value,
    Types::Uint64 swap_value) {
  return Imp::testAndSwapUint64(atomic_uint, compare_value, swap_value);
}

inline Types::Uint64 AtomicOperations::testAndSwapUint64AcqRel(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 compare_value,
    Types::Uint64 swap_value) {
  return Imp::testAndSwapUint64AcqRel(atomic_uint, compare_value, swap_value);
}

// *** atomic arithmetic functions for Uint64 ***

inline void AtomicOperations::addUint64(AtomicTypes::Uint64* atomic_uint,
                                        Types::Uint64 value) {
  Imp::addUint64(atomic_uint, value);
}

inline void AtomicOperations::addUint64AcqRel(AtomicTypes::Uint64* atomic_uint,
                                              Types::Uint64 value) {
  Imp::addUint64AcqRel(atomic_uint, value);
}

inline void AtomicOperations::addUint64Relaxed(AtomicTypes::Uint64* atomic_uint,
                                               Types::Uint64 value) {
  Imp::addUint64Relaxed(atomic_uint, value);
}

inline Types::Uint64 AtomicOperations::addUint64Nv(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return Imp::addUint64Nv(atomic_uint, value);
}

inline Types::Uint64 AtomicOperations::addUint64NvAcqRel(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return Imp::addUint64NvAcqRel(atomic_uint, value);
}

inline Types::Uint64 AtomicOperations::addUint64NvRelaxed(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return Imp::addUint64NvRelaxed(atomic_uint, value);
}

inline void AtomicOperations::decrementUint64(
    AtomicTypes::Uint64* atomic_uint) {
  Imp::decrementUint64(atomic_uint);
}

inline void AtomicOperations::decrementUint64AcqRel(
    AtomicTypes::Uint64* atomic_uint) {
  Imp::decrementUint64AcqRel(atomic_uint);
}

inline Types::Uint64 AtomicOperations::decrementUint64Nv(
    AtomicTypes::Uint64* atomic_uint) {
  return Imp::decrementUint64Nv(atomic_uint);
}

inline Types::Uint64 AtomicOperations::decrementUint64NvAcqRel(
    AtomicTypes::Uint64* atomic_uint) {
  return Imp::decrementUint64NvAcqRel(atomic_uint);
}

inline void AtomicOperations::incrementUint64(
    AtomicTypes::Uint64* atomic_uint) {
  Imp::incrementUint64(atomic_uint);
}

inline void AtomicOperations::incrementUint64AcqRel(
    AtomicTypes::Uint64* atomic_uint) {
  Imp::incrementUint64AcqRel(atomic_uint);
}

inline Types::Uint64 AtomicOperations::incrementUint64Nv(
    AtomicTypes::Uint64* atomic_uint) {
  return Imp::incrementUint64Nv(atomic_uint);
}

inline Types::Uint64 AtomicOperations::incrementUint64NvAcqRel(
    AtomicTypes::Uint64* atomic_uint) {
  return Imp::incrementUint64NvAcqRel(atomic_uint);
}

inline Types::Uint64 AtomicOperations::subtractUint64Nv(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return Imp::subtractUint64Nv(atomic_uint, value);
}

inline Types::Uint64 AtomicOperations::subtractUint64NvAcqRel(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return Imp::subtractUint64NvAcqRel(atomic_uint, value);
}

inline Types::Uint64 AtomicOperations::subtractUint64NvRelaxed(
    AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return Imp::subtractUint64NvRelaxed(atomic_uint, value);
}

// *** atomic functions for pointer ***

inline void* AtomicOperations::getPtr(AtomicTypes::Pointer const* atomic_ptr) {
  return Imp::getPtr(atomic_ptr);
}

inline void* AtomicOperations::getPtrAcquire(
    AtomicTypes::Pointer const* atomic_ptr) {
  return Imp::getPtrAcquire(atomic_ptr);
}

inline void* AtomicOperations::getPtrRelaxed(
    AtomicTypes::Pointer const* atomic_ptr) {
  return Imp::getPtrRelaxed(atomic_ptr);
}

inline void AtomicOperations::initPointer(AtomicTypes::Pointer* atomic_ptr,
                                          void* initial_value) {
  Imp::initPointer(atomic_ptr, initial_value);
}

inline void AtomicOperations::setPtr(AtomicTypes::Pointer* atomic_ptr,
                                     void* value) {
  Imp::setPtr(atomic_ptr, value);
}

inline void AtomicOperations::setPtrRelaxed(AtomicTypes::Pointer* atomic_ptr,
                                            void* value) {
  Imp::setPtrRelaxed(atomic_ptr, value);
}

inline void AtomicOperations::setPtrRelease(AtomicTypes::Pointer* atomic_ptr,
                                            void* value) {
  Imp::setPtrRelease(atomic_ptr, value);
}

inline void* AtomicOperations::swapPtr(AtomicTypes::Pointer* atomic_ptr,
                                       void* swap_value) {
  return Imp::swapPtr(atomic_ptr, swap_value);
}

inline void* AtomicOperations::swapPtrAcqRel(AtomicTypes::Pointer* atomic_ptr,
                                             void* swap_value) {
  return Imp::swapPtrAcqRel(atomic_ptr, swap_value);
}

inline void* AtomicOperations::testAndSwapPtr(AtomicTypes::Pointer* atomic_ptr,
                                              void* compare_value,
                                              void* swap_value) {
  return Imp::testAndSwapPtr(atomic_ptr, compare_value, swap_value);
}

inline void* AtomicOperations::testAndSwapPtrAcqRel(
    AtomicTypes::Pointer* atomic_ptr, void* compare_value, void* swap_value) {
  return Imp::testAndSwapPtrAcqRel(atomic_ptr, compare_value, swap_value);
}

}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_SYSTEM_ATOMICOPERATIONS_H