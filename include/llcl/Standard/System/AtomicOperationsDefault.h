#ifndef LLCL_STANDARD_SYSTEM_ATOMICOPERATIONSDEFAULT_H
#define LLCL_STANDARD_SYSTEM_ATOMICOPERATIONSDEFAULT_H

#include "llcl/Standard/System/Types.h"

namespace llcl {
namespace standard {

template <class IMP>
struct AtomicTypeTraits;

// This class provides default implementations of non-essential atomic
// operations for the 32-bit integer type independent on any specific
// platform.
template <class IMP>
struct AtomicOperationsDefaultInt {
 public:
  using AtomicTypes = AtomicTypeTraits<IMP>;

 private:
  // NOT IMPLEMENTED

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, providing the sequential consistency
  // memory ordering guarantee.
  static int addIntNv(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically retrieve the value of the specified 'atomic_int',
  // providing the sequential consistency memory ordering guarantee.
  static int getInt(typename AtomicTypes::Int const* atomic_int);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', providing the sequential consistency memory
  // ordering guarantee.
  static void setInt(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'swap_value', and return its previous value, providing the
  // sequential consistency memory ordering guarantee.
  static int swapInt(typename AtomicTypes::Int* atomic_int, int swap_value);

  // Conditionally set the value of the specified 'atomic_int' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_int', providing the sequential consistency memory
  // ordering guarantee.  The whole operation is performed atomically.
  static int testAndSwapInt(typename AtomicTypes::Int* atomic_int,
                            int compare_value, int swap_value);

 public:
  // Atomically retrieve the value of the specified 'atomic_int',
  // providing the acquire memory ordering guarantee.
  static int getIntAcquire(typename AtomicTypes::Int const* atomic_int);

  // Atomically retrieve the value of the specified 'atomic_int', without
  // providing any memory ordering guarantees.
  static int getIntRelaxed(typename AtomicTypes::Int const* atomic_int);

  // Initialize the specified 'atomic_int' and set its value to the
  // optionally specified 'initial_value'.
  static void initInt(typename AtomicTypes::Int* atomic_int,
                      int initial_value = 0);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', without providing any memory ordering guarantees.
  static void setIntRelaxed(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'value', providing the release memory ordering guarantee.
  static void setIntRelease(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically set the value of the specified 'atomic_int' to the
  // specified 'swap_value', and return its previous value, providing the
  // acquire/release memory ordering guarantee.
  static int swapIntAcqRel(typename AtomicTypes::Int* atomic_int,
                           int swap_value);

  // Conditionally set the value of the specified 'atomic_int' to the
  // specified 'swap_value' if and only if the value of 'atomic_int' equals
  // the value of the specified 'compare_value', and return the initial
  // value of 'atomic_int', providing the acquire/release memory ordering
  // guarantee.  The whole operation is performed atomically.
  static int testAndSwapIntAcqRel(typename AtomicTypes::Int* atomic_int,
                                  int compare_value, int swap_value);

  // Arithmetic
  // Atomically add to the specified 'atomic_int' the specified 'value',
  // providing the sequential consistency memory ordering guarantee.
  static void addInt(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // providing the acquire/release memory ordering guarantee.
  static void addIntAcqRel(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value',
  // without providing any memory ordering guarantees.
  static void addIntRelaxed(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  static int addIntNvAcqRel(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically add to the specified 'atomic_int' the specified 'value'
  // and return the resulting value, without providing any memory
  // ordering guarantees.
  static int addIntNvRelaxed(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically decrement the value of the specified 'atomic_int' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void decrementInt(typename AtomicTypes::Int* atomic_int);

  // Atomically decrement the value of the specified 'atomic_int' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void decrementIntAcqRel(typename AtomicTypes::Int* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static int decrementIntNv(typename AtomicTypes::Int* atomic_int);

  // Atomically decrement the specified 'atomic_int' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static int decrementIntNvAcqRel(typename AtomicTypes::Int* atomic_int);

  // Atomically increment the value of the specified 'atomic_int' by 1,
  // providing the sequential consistency memory ordering guarantee.
  static void incrementInt(typename AtomicTypes::Int* atomic_int);

  // Atomically increment the value of the specified 'atomic_int' by 1,
  // providing the acquire/release memory ordering guarantee.
  static void incrementIntAcqRel(typename AtomicTypes::Int* atomic_int);

  // Atomically increment the specified 'atomic_int' by 1 and return the
  // resulting value, providing the sequential consistency memory
  // ordering guarantee.
  static int incrementIntNv(typename AtomicTypes::Int* atomic_int);

  // Atomically increment the specified 'atomic_int' by 1 and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  static int incrementIntNvAcqRel(typename AtomicTypes::Int* atomic_int);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, providing the sequential
  // consistency memory ordering guarantee.
  static int subtractIntNv(typename AtomicTypes::Int* atomic_int, int value);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, providing the
  // acquire/release memory ordering guarantee.
  static int subtractIntNvAcqRel(typename AtomicTypes::Int* atomic_int,
                                 int value);

  // Atomically subtract from the specified 'atomic_int' the specified
  // 'value' and return the resulting value, without providing any memory
  // ordering guarantees.
  static int subtractIntNvRelaxed(typename AtomicTypes::Int* atomic_int,
                                  int value);
};

template <class IMP>
struct AtomicOperationsDefaultInt64 {
 public:
  using AtomicTypes = AtomicTypeTraits<IMP>;

 private:
  // NOT IMPLEMENTED
  static Types::Int64 addInt64Nv(typename AtomicTypes::Int64* atomic_int,
                                 Types::Int64 value);

  static Types::Int64 getInt64(typename AtomicTypes::Int64 const* atomic_int);

  static void setInt64(typename AtomicTypes::Int64* atomic_int,
                       Types::Int64 value);

  static Types::Int64 swapInt64(typename AtomicTypes::Int64* atomic_int,
                                Types::Int64 swap_value);

  static Types::Int64 testAndSwapInt64(typename AtomicTypes::Int64* atomic_int,
                                       Types::Int64 compare_value,
                                       Types::Int64 swap_value);

 public:
  static Types::Int64 getInt64Acquire(
      typename AtomicTypes::Int64 const* atomic_int);

  static Types::Int64 getInt64Relaxed(
      typename AtomicTypes::Int64 const* atomic_int);

  static void initInt64(typename AtomicTypes::Int64* atomic_int,
                        Types::Int64 initial_value = 0);

  static void setInt64Relaxed(typename AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  static void setInt64Release(typename AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  static Types::Int64 swapInt64AcqRel(typename AtomicTypes::Int64* atomic_int,
                                      Types::Int64 swap_value);

  static Types::Int64 testAndSwapInt64AcqRel(
      typename AtomicTypes::Int64* atomic_int, Types::Int64 compare_value,
      Types::Int64 swap_value);

  // Arithmetic
  static void addInt64(typename AtomicTypes::Int64* atomic_int,
                       Types::Int64 value);

  static void addInt64AcqRel(typename AtomicTypes::Int64* atomic_int,
                             Types::Int64 value);

  static void addInt64Relaxed(typename AtomicTypes::Int64* atomic_int,
                              Types::Int64 value);

  static Types::Int64 addInt64NvAcqRel(typename AtomicTypes::Int64* atomic_int,
                                       Types::Int64 value);

  static Types::Int64 addInt64NvRelaxed(typename AtomicTypes::Int64* atomic_int,
                                        Types::Int64 value);

  static void decrementInt64(typename AtomicTypes::Int64* atomic_int);

  static void decrementInt64AcqRel(typename AtomicTypes::Int64* atomic_int);

  static Types::Int64 decrementInt64Nv(typename AtomicTypes::Int64* atomic_int);

  static Types::Int64 decrementInt64NvAcqRel(
      typename AtomicTypes::Int64* atomic_int);

  static void incrementInt64(typename AtomicTypes::Int64* atomic_int);

  static void incrementInt64AcqRel(typename AtomicTypes::Int64* atomic_int);

  static Types::Int64 incrementInt64Nv(typename AtomicTypes::Int64* atomic_int);

  static Types::Int64 incrementInt64NvAcqRel(
      typename AtomicTypes::Int64* atomic_int);

  static Types::Int64 subtractInt64Nv(typename AtomicTypes::Int64* atomic_int,
                                      Types::Int64 value);

  static Types::Int64 subtractInt64NvAcqRel(
      typename AtomicTypes::Int64* atomic_int, Types::Int64 value);

  static Types::Int64 subtractInt64NvRelaxed(
      typename AtomicTypes::Int64* atomic_int, Types::Int64 value);
};

template <class IMP>
struct AtomicTypeTraits;

template <class IMP>
struct AtomicOperationsDefaultUint {
 public:
  using AtomicTypes = AtomicTypeTraits<IMP>;

  static unsigned int getUint(typename AtomicTypes::Uint const* atomic_uint);

  static unsigned int getUintAcquire(
      typename AtomicTypes::Uint const* atomic_uint);

  static unsigned int getUintRelaxed(
      typename AtomicTypes::Uint const* atomic_uint);

  static void initUint(typename AtomicTypes::Uint* atomic_uint,
                       unsigned int initial_value = 0);

  static void setUint(typename AtomicTypes::Uint* atomic_uint,
                      unsigned int value);

  static void setUintRelaxed(typename AtomicTypes::Uint* atomic_uint,
                             unsigned int value);

  static void setUintRelease(typename AtomicTypes::Uint* atomic_uint,
                             unsigned int value);

  static unsigned int swapUint(typename AtomicTypes::Uint* atomic_uint,
                               unsigned int swap_value);

  static unsigned int swapUintAcqRel(typename AtomicTypes::Uint* atomic_uint,
                                     unsigned int swap_value);

  static unsigned int testAndSwapUint(typename AtomicTypes::Uint* atomic_uint,
                                      unsigned int compare_value,
                                      unsigned int swap_value);

  static unsigned int testAndSwapUintAcqRel(
      typename AtomicTypes::Uint* atomic_uint, unsigned int compare_value,
      unsigned int swap_value);

  // Arithmetic
  static void addUint(typename AtomicTypes::Uint* atomic_uint,
                      unsigned int value);

  static void addUintAcqRel(typename AtomicTypes::Uint* atomic_uint,
                            unsigned int value);

  static void addUintRelaxed(typename AtomicTypes::Uint* atomic_uint,
                             unsigned int value);

  static unsigned int addUintNv(typename AtomicTypes::Uint* atomic_uint,
                                unsigned int value);

  static unsigned int addUintNvAcqRel(typename AtomicTypes::Uint* atomic_uint,
                                      unsigned int value);

  static unsigned int addUintNvRelaxed(typename AtomicTypes::Uint* atomic_uint,
                                       unsigned int value);

  static void decrementUint(typename AtomicTypes::Uint* atomic_uint);

  static void decrementUintAcqRel(typename AtomicTypes::Uint* atomic_uint);

  static unsigned int decrementUintNv(typename AtomicTypes::Uint* atomic_uint);

  static unsigned int decrementUintNvAcqRel(
      typename AtomicTypes::Uint* atomic_uint);

  static void incrementUint(typename AtomicTypes::Uint* atomic_uint);

  static void incrementUintAcqRel(typename AtomicTypes::Uint* atomic_uint);

  static unsigned int incrementUintNv(typename AtomicTypes::Uint* atomic_uint);

  static unsigned int incrementUintNvAcqRel(
      typename AtomicTypes::Uint* atomic_uint);

  static unsigned int subtractUintNv(typename AtomicTypes::Uint* atomic_uint,
                                     unsigned int value);

  static unsigned int subtractUintNvAcqRel(
      typename AtomicTypes::Uint* atomic_uint, unsigned int value);

  static unsigned int subtractUintNvRelaxed(
      typename AtomicTypes::Uint* atomic_uint, unsigned int value);
};

template <class IMP>
struct AtomicOperationsDefaultUint64 {
 public:
  typedef AtomicTypeTraits<IMP> AtomicTypes;

  static Types::Uint64 getUint64(
      typename AtomicTypes::Uint64 const* atomic_uint);

  static Types::Uint64 getUint64Acquire(
      typename AtomicTypes::Uint64 const* atomic_uint);

  static Types::Uint64 getUint64Relaxed(
      typename AtomicTypes::Uint64 const* atomic_uint);

  static void initUint64(typename AtomicTypes::Uint64* atomic_uint,
                         Types::Uint64 initial_value = 0);

  static void setUint64(typename AtomicTypes::Uint64* atomic_uint,
                        Types::Uint64 value);

  static void setUint64Relaxed(typename AtomicTypes::Uint64* atomic_uint,
                               Types::Uint64 value);

  static void setUint64Release(typename AtomicTypes::Uint64* atomic_uint,
                               Types::Uint64 value);

  static Types::Uint64 swapUint64(typename AtomicTypes::Uint64* atomic_uint,
                                  Types::Uint64 swap_value);

  static Types::Uint64 swapUint64AcqRel(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 swap_value);

  static Types::Uint64 testAndSwapUint64(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 compare_value,
      Types::Uint64 swap_value);

  static Types::Uint64 testAndSwapUint64AcqRel(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 compare_value,
      Types::Uint64 swap_value);

  // Arithmetic
  static void addUint64(typename AtomicTypes::Uint64* atomic_uint,
                        Types::Uint64 value);

  static void addUint64AcqRel(typename AtomicTypes::Uint64* atomic_uint,
                              Types::Uint64 value);

  static void addUint64Relaxed(typename AtomicTypes::Uint64* atomic_uint,
                               Types::Uint64 value);

  static Types::Uint64 addUint64Nv(typename AtomicTypes::Uint64* atomic_uint,
                                   Types::Uint64 value);

  static Types::Uint64 addUint64NvAcqRel(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);

  static Types::Uint64 addUint64NvRelaxed(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);

  static void decrementUint64(typename AtomicTypes::Uint64* atomic_uint);

  static void decrementUint64AcqRel(typename AtomicTypes::Uint64* atomic_uint);

  static Types::Uint64 decrementUint64Nv(
      typename AtomicTypes::Uint64* atomic_uint);

  static Types::Uint64 decrementUint64NvAcqRel(
      typename AtomicTypes::Uint64* atomic_uint);

  static void incrementUint64(typename AtomicTypes::Uint64* atomic_uint);

  static void incrementUint64AcqRel(typename AtomicTypes::Uint64* atomic_uint);

  static Types::Uint64 incrementUint64Nv(
      typename AtomicTypes::Uint64* atomic_uint);

  static Types::Uint64 incrementUint64NvAcqRel(
      typename AtomicTypes::Uint64* atomic_uint);

  static Types::Uint64 subtractUint64Nv(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);

  static Types::Uint64 subtractUint64NvAcqRel(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);

  static Types::Uint64 subtractUint64NvRelaxed(
      typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value);
};

template <class IMP>
struct AtomicOperationsDefaultPointer32 {
  typedef AtomicTypeTraits<IMP> AtomicTypes;

  // CLASS METHODS
  static void* getPtr(typename AtomicTypes::Pointer const* atomic_ptr);

  static void* getPtrAcquire(typename AtomicTypes::Pointer const* atomic_ptr);

  static void* getPtrRelaxed(typename AtomicTypes::Pointer const* atomic_ptr);

  static void initPointer(typename AtomicTypes::Pointer* atomic_ptr,
                          void* initial_value = 0);

  static void setPtr(typename AtomicTypes::Pointer* atomic_ptr, void* value);

  static void setPtrRelaxed(typename AtomicTypes::Pointer* atomic_ptr,
                            void* value);

  static void setPtrRelease(typename AtomicTypes::Pointer* atomic_ptr,
                            void* value);

  static void* swapPtr(typename AtomicTypes::Pointer* atomic_ptr,
                       void* swap_value);

  static void* swapPtrAcqRel(typename AtomicTypes::Pointer* atomic_ptr,
                             void* swap_value);

  static void* testAndSwapPtr(typename AtomicTypes::Pointer* atomic_ptr,
                              void* compare_value, void* swap_value);

  static void* testAndSwapPtrAcqRel(typename AtomicTypes::Pointer* atomic_ptr,
                                    void* compare_value, void* swap_value);
};

template <class IMP>
struct AtomicOperationsDefaultPointer64 {
  typedef AtomicTypeTraits<IMP> AtomicTypes;

  static void* getPtr(typename AtomicTypes::Pointer const* atomic_ptr);

  static void* getPtrAcquire(typename AtomicTypes::Pointer const* atomic_ptr);

  static void* getPtrRelaxed(typename AtomicTypes::Pointer const* atomic_ptr);

  static void initPointer(typename AtomicTypes::Pointer* atomic_ptr,
                          void* initial_value = 0);

  static void setPtr(typename AtomicTypes::Pointer* atomic_ptr, void* value);

  static void setPtrRelaxed(typename AtomicTypes::Pointer* atomic_ptr,
                            void* value);

  static void setPtrRelease(typename AtomicTypes::Pointer* atomic_ptr,
                            void* value);

  static void* swapPtr(typename AtomicTypes::Pointer* atomic_ptr,
                       void* swap_value);

  static void* swapPtrAcqRel(typename AtomicTypes::Pointer* atomic_ptr,
                             void* swap_value);

  static void* testAndSwapPtr(typename AtomicTypes::Pointer* atomic_ptr,
                              void* compare_value, void* swap_value);

  static void* testAndSwapPtrAcqRel(typename AtomicTypes::Pointer* atomic_ptr,
                                    void* compare_value, void* swap_value);
};

template <class IMP>
struct AtomicOperationsDefault32 : AtomicOperationsDefaultInt<IMP>,
                                   AtomicOperationsDefaultInt64<IMP>,
                                   AtomicOperationsDefaultUint<IMP>,
                                   AtomicOperationsDefaultUint64<IMP>,
                                   AtomicOperationsDefaultPointer32<IMP> {};

template <class IMP>
struct AtomicOperationsDefault64 : AtomicOperationsDefaultInt<IMP>,
                                   AtomicOperationsDefaultInt64<IMP>,
                                   AtomicOperationsDefaultUint<IMP>,
                                   AtomicOperationsDefaultUint64<IMP>,
                                   AtomicOperationsDefaultPointer64<IMP> {};

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::getIntAcquire(
    typename AtomicTypes::Int const* atomic_int) {
  return IMP::getInt(atomic_int);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::getIntRelaxed(
    typename AtomicTypes::Int const* atomic_int) {
  return atomic_int->d_value;
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::initInt(
    typename AtomicTypes::Int* atomic_int, int initial_value) {
  atomic_int->d_value = initial_value;
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::setIntRelaxed(
    typename AtomicTypes::Int* atomic_int, int value) {
  atomic_int->d_value = value;
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::setIntRelease(
    typename AtomicTypes::Int* atomic_int, int value) {
  IMP::setInt(atomic_int, value);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::swapIntAcqRel(
    typename AtomicTypes::Int* atomic_int, int swap_value) {
  return IMP::swapInt(atomic_int, swap_value);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::testAndSwapIntAcqRel(
    typename AtomicTypes::Int* atomic_int, int compare_value, int swap_value) {
  return IMP::testAndSwapInt(atomic_int, compare_value, swap_value);
}

// Arithmetic
template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::addInt(
    typename AtomicTypes::Int* atomic_int, int value) {
  IMP::addIntNv(atomic_int, value);
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::addIntAcqRel(
    typename AtomicTypes::Int* atomic_int, int value) {
  IMP::addIntNvAcqRel(atomic_int, value);
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::addIntRelaxed(
    typename AtomicTypes::Int* atomic_int, int value) {
  IMP::addIntNvRelaxed(atomic_int, value);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::addIntNvAcqRel(
    typename AtomicTypes::Int* atomic_int, int value) {
  return IMP::addIntNv(atomic_int, value);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::addIntNvRelaxed(
    typename AtomicTypes::Int* atomic_int, int value) {
  return IMP::addIntNvAcqRel(atomic_int, value);
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::decrementInt(
    typename AtomicTypes::Int* atomic_int) {
  IMP::addInt(atomic_int, -1);
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::decrementIntAcqRel(
    typename AtomicTypes::Int* atomic_int) {
  IMP::addIntAcqRel(atomic_int, -1);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::decrementIntNv(
    typename AtomicTypes::Int* atomic_int) {
  return IMP::addIntNv(atomic_int, -1);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::decrementIntNvAcqRel(
    typename AtomicTypes::Int* atomic_int) {
  return IMP::addIntNvAcqRel(atomic_int, -1);
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::incrementInt(
    typename AtomicTypes::Int* atomic_int) {
  IMP::addInt(atomic_int, 1);
}

template <class IMP>
inline void AtomicOperationsDefaultInt<IMP>::incrementIntAcqRel(
    typename AtomicTypes::Int* atomic_int) {
  IMP::addIntAcqRel(atomic_int, 1);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::incrementIntNv(
    typename AtomicTypes::Int* atomic_int) {
  return IMP::addIntNv(atomic_int, 1);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::incrementIntNvAcqRel(
    typename AtomicTypes::Int* atomic_int) {
  return IMP::addIntNvAcqRel(atomic_int, 1);
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::subtractIntNv(
    typename AtomicTypes::Int* atomic_int, int value) {
  return static_cast<int>(IMP::subtractUintNv(
      reinterpret_cast<typename AtomicTypes::Uint*>(atomic_int),
      static_cast<unsigned int>(value)));
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::subtractIntNvAcqRel(
    typename AtomicTypes::Int* atomic_int, int value) {
  return static_cast<int>(IMP::subtractUintNvAcqRel(
      reinterpret_cast<typename AtomicTypes::Uint*>(atomic_int),
      static_cast<unsigned int>(value)));
}

template <class IMP>
inline int AtomicOperationsDefaultInt<IMP>::subtractIntNvRelaxed(
    typename AtomicTypes::Int* atomic_int, int value) {
  return static_cast<int>(IMP::subtractUintNvRelaxed(
      reinterpret_cast<typename AtomicTypes::Uint*>(atomic_int),
      static_cast<unsigned int>(value)));
}

// ------------------------------------
// struct AtomicOperationsDefaultInt64
// ------------------------------------

// CLASS METHODS
template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::getInt64Acquire(
    typename AtomicTypes::Int64 const* atomic_int) {
  return IMP::getInt64(atomic_int);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::getInt64Relaxed(
    typename AtomicTypes::Int64 const* atomic_int) {
  return atomic_int->d_value;
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::initInt64(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 initial_value) {
  atomic_int->d_value = initial_value;
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::setInt64Relaxed(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  atomic_int->d_value = value;
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::setInt64Release(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  IMP::setInt64(atomic_int, value);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::swapInt64AcqRel(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 swap_value) {
  return IMP::swapInt64(atomic_int, swap_value);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::testAndSwapInt64AcqRel(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 compare_value,
    Types::Int64 swap_value) {
  return IMP::testAndSwapInt64(atomic_int, compare_value, swap_value);
}

// Arithmetic
template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::addInt64(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  IMP::addInt64Nv(atomic_int, value);
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::addInt64AcqRel(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  IMP::addInt64NvAcqRel(atomic_int, value);
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::addInt64Relaxed(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  IMP::addInt64NvRelaxed(atomic_int, value);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::addInt64NvAcqRel(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return IMP::addInt64Nv(atomic_int, value);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::addInt64NvRelaxed(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return IMP::addInt64NvAcqRel(atomic_int, value);
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::decrementInt64(
    typename AtomicTypes::Int64* atomic_int) {
  IMP::addInt64(atomic_int, -1);
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::decrementInt64AcqRel(
    typename AtomicTypes::Int64* atomic_int) {
  IMP::addInt64AcqRel(atomic_int, -1);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::decrementInt64Nv(
    typename AtomicTypes::Int64* atomic_int) {
  return IMP::addInt64Nv(atomic_int, -1);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::decrementInt64NvAcqRel(
    typename AtomicTypes::Int64* atomic_int) {
  return IMP::addInt64NvAcqRel(atomic_int, -1);
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::incrementInt64(
    typename AtomicTypes::Int64* atomic_int) {
  IMP::addInt64(atomic_int, 1);
}

template <class IMP>
inline void AtomicOperationsDefaultInt64<IMP>::incrementInt64AcqRel(
    typename AtomicTypes::Int64* atomic_int) {
  IMP::addInt64AcqRel(atomic_int, 1);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::incrementInt64Nv(
    typename AtomicTypes::Int64* atomic_int) {
  return IMP::addInt64Nv(atomic_int, 1);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::incrementInt64NvAcqRel(
    typename AtomicTypes::Int64* atomic_int) {
  return IMP::addInt64NvAcqRel(atomic_int, 1);
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::subtractInt64Nv(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return static_cast<Types::Int64>(IMP::subtractUint64Nv(
      reinterpret_cast<typename AtomicTypes::Uint64*>(atomic_int),
      static_cast<Types::Uint64>(value)));
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::subtractInt64NvAcqRel(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return static_cast<Types::Int64>(IMP::subtractUint64NvAcqRel(
      reinterpret_cast<typename AtomicTypes::Uint64*>(atomic_int),
      static_cast<Types::Uint64>(value)));
}

template <class IMP>
inline Types::Int64 AtomicOperationsDefaultInt64<IMP>::subtractInt64NvRelaxed(
    typename AtomicTypes::Int64* atomic_int, Types::Int64 value) {
  return static_cast<Types::Int64>(IMP::subtractUint64NvRelaxed(
      reinterpret_cast<typename AtomicTypes::Uint64*>(atomic_int),
      static_cast<Types::Uint64>(value)));
}

// ----------------------------------
// struct AtomicOperationsDefaultUint
// ----------------------------------

// CLASS METHODS
template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::getUint(
    typename AtomicTypes::Uint const* atomic_uint) {
  return static_cast<unsigned int>(IMP::getInt(
      reinterpret_cast<typename AtomicTypes::Int const*>(atomic_uint)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::getUintAcquire(
    typename AtomicTypes::Uint const* atomic_uint) {
  return static_cast<unsigned int>(IMP::getIntAcquire(
      reinterpret_cast<typename AtomicTypes::Int const*>(atomic_uint)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::getUintRelaxed(
    typename AtomicTypes::Uint const* atomic_uint) {
  return atomic_uint->d_value;
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::initUint(
    typename AtomicTypes::Uint* atomic_uint, unsigned int initial_value) {
  atomic_uint->d_value = initial_value;
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::setUint(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  IMP::setInt(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
              static_cast<int>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::setUintRelaxed(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  atomic_uint->d_value = value;
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::setUintRelease(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  IMP::setIntRelease(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                     static_cast<int>(value));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::swapUint(
    typename AtomicTypes::Uint* atomic_uint, unsigned int swap_value) {
  return static_cast<unsigned int>(
      IMP::swapInt(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                   static_cast<int>(swap_value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::swapUintAcqRel(
    typename AtomicTypes::Uint* atomic_uint, unsigned int swap_value) {
  return static_cast<unsigned int>(IMP::swapIntAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(swap_value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::testAndSwapUint(
    typename AtomicTypes::Uint* atomic_uint, unsigned int compare_value,
    unsigned int swap_value) {
  return static_cast<unsigned int>(IMP::testAndSwapInt(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(compare_value), static_cast<int>(swap_value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::testAndSwapUintAcqRel(
    typename AtomicTypes::Uint* atomic_uint, unsigned int compare_value,
    unsigned int swap_value) {
  return static_cast<unsigned int>(IMP::testAndSwapIntAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(compare_value), static_cast<int>(swap_value)));
}

// Arithmetic
template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::addUint(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  IMP::addInt(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
              static_cast<int>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::addUintAcqRel(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  IMP::addIntAcqRel(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                    static_cast<int>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::addUintRelaxed(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  IMP::addIntRelaxed(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                     static_cast<int>(value));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::addUintNv(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return static_cast<unsigned int>(
      IMP::addIntNv(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                    static_cast<int>(value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::addUintNvAcqRel(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return static_cast<unsigned int>(IMP::addIntNvAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::addUintNvRelaxed(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return static_cast<unsigned int>(IMP::addIntNvRelaxed(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(value)));
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::decrementUint(
    typename AtomicTypes::Uint* atomic_uint) {
  IMP::addInt(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint), -1);
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::decrementUintAcqRel(
    typename AtomicTypes::Uint* atomic_uint) {
  IMP::addIntAcqRel(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                    -1);
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::decrementUintNv(
    typename AtomicTypes::Uint* atomic_uint) {
  return IMP::subtractUintNv(atomic_uint, 1);
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::decrementUintNvAcqRel(
    typename AtomicTypes::Uint* atomic_uint) {
  return static_cast<unsigned int>(IMP::addIntNvAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint), -1));
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::incrementUint(
    typename AtomicTypes::Uint* atomic_uint) {
  IMP::addUint(atomic_uint, 1);
}

template <class IMP>
inline void AtomicOperationsDefaultUint<IMP>::incrementUintAcqRel(
    typename AtomicTypes::Uint* atomic_uint) {
  IMP::addUintAcqRel(atomic_uint, 1);
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::incrementUintNv(
    typename AtomicTypes::Uint* atomic_uint) {
  return IMP::addUintNv(atomic_uint, 1);
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::incrementUintNvAcqRel(
    typename AtomicTypes::Uint* atomic_uint) {
  return IMP::addUintNvAcqRel(atomic_uint, 1);
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::subtractUintNv(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return static_cast<unsigned int>(
      IMP::addIntNv(reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
                    static_cast<int>(1 + ~value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::subtractUintNvAcqRel(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return static_cast<unsigned int>(IMP::addIntNvAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(1 + ~value)));
}

template <class IMP>
inline unsigned int AtomicOperationsDefaultUint<IMP>::subtractUintNvRelaxed(
    typename AtomicTypes::Uint* atomic_uint, unsigned int value) {
  return static_cast<unsigned int>(IMP::addIntNvRelaxed(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_uint),
      static_cast<int>(1 + ~value)));
}

// ------------------------------------
// struct AtomicOperationsDefaultUint64
// ------------------------------------

// CLASS METHODS
template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::getUint64(
    typename AtomicTypes::Uint64 const* atomic_uint) {
  return static_cast<Types::Uint64>(IMP::getInt64(
      reinterpret_cast<typename AtomicTypes::Int64 const*>(atomic_uint)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::getUint64Acquire(
    typename AtomicTypes::Uint64 const* atomic_uint) {
  return static_cast<Types::Uint64>(IMP::getInt64Acquire(
      reinterpret_cast<typename AtomicTypes::Int64 const*>(atomic_uint)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::getUint64Relaxed(
    typename AtomicTypes::Uint64 const* atomic_uint) {
  return atomic_uint->d_value;
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::initUint64(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 initial_value) {
  atomic_uint->d_value = initial_value;
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::setUint64(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  IMP::setInt64(reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
                static_cast<Types::Int64>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::setUint64Relaxed(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  atomic_uint->d_value = value;
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::setUint64Release(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  IMP::setInt64Release(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(value));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::swapUint64(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 swap_value) {
  return static_cast<Types::Uint64>(IMP::swapInt64(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(swap_value)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::swapUint64AcqRel(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 swap_value) {
  return static_cast<Types::Uint64>(IMP::swapInt64AcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(swap_value)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::testAndSwapUint64(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 compare_value,
    Types::Uint64 swap_value) {
  return static_cast<Types::Uint64>(IMP::testAndSwapInt64(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(compare_value),
      static_cast<Types::Int64>(swap_value)));
}

template <class IMP>
inline Types::Uint64
AtomicOperationsDefaultUint64<IMP>::testAndSwapUint64AcqRel(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 compare_value,
    Types::Uint64 swap_value) {
  return static_cast<Types::Uint64>(IMP::testAndSwapInt64AcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(compare_value),
      static_cast<Types::Int64>(swap_value)));
}

// Arithmetic
template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::addUint64(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  IMP::addInt64(reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
                static_cast<Types::Int64>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::addUint64AcqRel(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  IMP::addInt64AcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::addUint64Relaxed(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  IMP::addInt64Relaxed(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(value));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::addUint64Nv(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return static_cast<Types::Uint64>(IMP::addInt64Nv(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(value)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::addUint64NvAcqRel(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return static_cast<Types::Uint64>(IMP::addInt64NvAcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(value)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::addUint64NvRelaxed(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return static_cast<Types::Uint64>(IMP::addInt64NvRelaxed(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(value)));
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::decrementUint64(
    typename AtomicTypes::Uint64* atomic_uint) {
  IMP::addInt64(reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
                -1);
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::decrementUint64AcqRel(
    typename AtomicTypes::Uint64* atomic_uint) {
  IMP::addInt64AcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint), -1);
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::decrementUint64Nv(
    typename AtomicTypes::Uint64* atomic_uint) {
  return IMP::subtractUint64Nv(atomic_uint, 1);
}

template <class IMP>
inline Types::Uint64
AtomicOperationsDefaultUint64<IMP>::decrementUint64NvAcqRel(
    typename AtomicTypes::Uint64* atomic_uint) {
  return static_cast<Types::Uint64>(IMP::addInt64NvAcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint), -1));
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::incrementUint64(
    typename AtomicTypes::Uint64* atomic_uint) {
  IMP::addUint64(atomic_uint, 1);
}

template <class IMP>
inline void AtomicOperationsDefaultUint64<IMP>::incrementUint64AcqRel(
    typename AtomicTypes::Uint64* atomic_uint) {
  IMP::addUint64AcqRel(atomic_uint, 1);
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::incrementUint64Nv(
    typename AtomicTypes::Uint64* atomic_uint) {
  return IMP::addUint64Nv(atomic_uint, 1);
}

template <class IMP>
inline Types::Uint64
AtomicOperationsDefaultUint64<IMP>::incrementUint64NvAcqRel(
    typename AtomicTypes::Uint64* atomic_uint) {
  return IMP::addUint64NvAcqRel(atomic_uint, 1);
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::subtractUint64Nv(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return static_cast<Types::Uint64>(IMP::addInt64Nv(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(1 + ~value)));
}

template <class IMP>
inline Types::Uint64 AtomicOperationsDefaultUint64<IMP>::subtractUint64NvAcqRel(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return static_cast<Types::Uint64>(IMP::addInt64NvAcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(1 + ~value)));
}

template <class IMP>
inline Types::Uint64
AtomicOperationsDefaultUint64<IMP>::subtractUint64NvRelaxed(
    typename AtomicTypes::Uint64* atomic_uint, Types::Uint64 value) {
  return static_cast<Types::Uint64>(IMP::addInt64NvRelaxed(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_uint),
      static_cast<Types::Int64>(1 + ~value)));
}

// ----------------------------------------
// struct AtomicOperationsDefaultPointer32
// ----------------------------------------

// CLASS METHODS
template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::getPtr(
    typename AtomicTypes::Pointer const* atomic_ptr) {
  return reinterpret_cast<void*>(IMP::getInt(
      reinterpret_cast<typename AtomicTypes::Int const*>(atomic_ptr)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::getPtrAcquire(
    typename AtomicTypes::Pointer const* atomic_ptr) {
  return reinterpret_cast<void*>(IMP::getIntAcquire(
      reinterpret_cast<typename AtomicTypes::Int const*>(atomic_ptr)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::getPtrRelaxed(
    typename AtomicTypes::Pointer const* atomic_ptr) {
  return reinterpret_cast<void*>(IMP::getIntRelaxed(
      reinterpret_cast<typename AtomicTypes::Int const*>(atomic_ptr)));
}

template <class IMP>
inline void AtomicOperationsDefaultPointer32<IMP>::initPointer(
    typename AtomicTypes::Pointer* atomic_ptr, void* initial_value) {
  atomic_ptr->d_value = initial_value;
}

template <class IMP>
inline void AtomicOperationsDefaultPointer32<IMP>::setPtr(
    typename AtomicTypes::Pointer* atomic_ptr, void* value) {
  IMP::setInt(reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
              reinterpret_cast<Types::IntPtr>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultPointer32<IMP>::setPtrRelaxed(
    typename AtomicTypes::Pointer* atomic_ptr, void* value) {
  IMP::setIntRelaxed(reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
                     reinterpret_cast<Types::IntPtr>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultPointer32<IMP>::setPtrRelease(
    typename AtomicTypes::Pointer* atomic_ptr, void* value) {
  IMP::setIntRelease(reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
                     reinterpret_cast<Types::IntPtr>(value));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::swapPtr(
    typename AtomicTypes::Pointer* atomic_ptr, void* swap_value) {
  return reinterpret_cast<void*>(
      IMP::swapInt(reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
                   reinterpret_cast<Types::IntPtr>(swap_value)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::swapPtrAcqRel(
    typename AtomicTypes::Pointer* atomic_ptr, void* swap_value) {
  return reinterpret_cast<void*>(IMP::swapIntAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(swap_value)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::testAndSwapPtr(
    typename AtomicTypes::Pointer* atomic_ptr, void* compare_value,
    void* swap_value) {
  return reinterpret_cast<void*>(IMP::testAndSwapInt(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(compare_value),
      reinterpret_cast<Types::IntPtr>(swap_value)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer32<IMP>::testAndSwapPtrAcqRel(
    typename AtomicTypes::Pointer* atomic_ptr, void* compare_value,
    void* swap_value) {
  return reinterpret_cast<void*>(IMP::testAndSwapIntAcqRel(
      reinterpret_cast<typename AtomicTypes::Int*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(compare_value),
      reinterpret_cast<Types::IntPtr>(swap_value)));
}

// ----------------------------------------
// struct AtomicOperationsDefaultPointer64
// ----------------------------------------

// CLASS METHODS
template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::getPtr(
    typename AtomicTypes::Pointer const* atomic_ptr) {
  return reinterpret_cast<void*>(IMP::getInt64(
      reinterpret_cast<typename AtomicTypes::Int64 const*>(atomic_ptr)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::getPtrAcquire(
    typename AtomicTypes::Pointer const* atomic_ptr) {
  return reinterpret_cast<void*>(IMP::getInt64Acquire(
      reinterpret_cast<typename AtomicTypes::Int64 const*>(atomic_ptr)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::getPtrRelaxed(
    typename AtomicTypes::Pointer const* atomic_ptr) {
  return reinterpret_cast<void*>(IMP::getInt64Relaxed(
      reinterpret_cast<typename AtomicTypes::Int64 const*>(atomic_ptr)));
}

template <class IMP>
inline void AtomicOperationsDefaultPointer64<IMP>::initPointer(
    typename AtomicTypes::Pointer* atomic_ptr, void* initial_value) {
  atomic_ptr->d_value = initial_value;
}

template <class IMP>
inline void AtomicOperationsDefaultPointer64<IMP>::setPtr(
    typename AtomicTypes::Pointer* atomic_ptr, void* value) {
  IMP::setInt64(reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
                reinterpret_cast<Types::IntPtr>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultPointer64<IMP>::setPtrRelaxed(
    typename AtomicTypes::Pointer* atomic_ptr, void* value) {
  IMP::setInt64Relaxed(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(value));
}

template <class IMP>
inline void AtomicOperationsDefaultPointer64<IMP>::setPtrRelease(
    typename AtomicTypes::Pointer* atomic_ptr, void* value) {
  IMP::setInt64Release(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(value));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::swapPtr(
    typename AtomicTypes::Pointer* atomic_ptr, void* swap_value) {
  return reinterpret_cast<void*>(
      IMP::swapInt64(reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
                     reinterpret_cast<Types::IntPtr>(swap_value)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::swapPtrAcqRel(
    typename AtomicTypes::Pointer* atomic_ptr, void* swap_value) {
  return reinterpret_cast<void*>(IMP::swapInt64AcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(swap_value)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::testAndSwapPtr(
    typename AtomicTypes::Pointer* atomic_ptr, void* compare_value,
    void* swap_value) {
  return reinterpret_cast<void*>(IMP::testAndSwapInt64(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(compare_value),
      reinterpret_cast<Types::IntPtr>(swap_value)));
}

template <class IMP>
inline void* AtomicOperationsDefaultPointer64<IMP>::testAndSwapPtrAcqRel(
    typename AtomicTypes::Pointer* atomic_ptr, void* compare_value,
    void* swap_value) {
  return reinterpret_cast<void*>(IMP::testAndSwapInt64AcqRel(
      reinterpret_cast<typename AtomicTypes::Int64*>(atomic_ptr),
      reinterpret_cast<Types::IntPtr>(compare_value),
      reinterpret_cast<Types::IntPtr>(swap_value)));
}

}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_SYSTEM_ATOMICOPERATIONSDEFAULT_H