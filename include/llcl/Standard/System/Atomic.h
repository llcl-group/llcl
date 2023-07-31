#ifndef LLCL_STANDARD_SYSTEM_ATOMIC_H
#define LLCL_STANDARD_SYSTEM_ATOMIC_H

#include "llcl/Standard/System/AtomicOperations.h"
#include "llcl/Standard/System/Types.h"

namespace llcl {
namespace standard {

class AtomicInt {
  AtomicOperations::AtomicTypes::Int d_value;

 private:
  AtomicInt(const AtomicInt&);             // = delete
  AtomicInt& operator=(const AtomicInt&);  // = delete

 public:
  // Create an atomic integer object having the default value 0.
  AtomicInt();

  // Create an atomic integer object having the specified 'value'.
  AtomicInt(int value);

  // Destroy this atomic integer object.
  //! ~AtomicInt() = default;

  // Atomically assign the specified 'value' to this object, and return a
  // reference offering modifiable access to 'this' object.
  AtomicInt& operator=(int value);

  // Atomically add the specified 'value' to this object, and return the
  // resulting value.
  int operator+=(int value);

  // Atomically subtract the specified 'value' from this object, and
  // return the resulting value.
  int operator-=(int value);

  // Atomically increment the value of this object by 1 and return the
  // resulting value.
  int operator++();

  // Atomically increment the value of this object by 1 and return the
  // value prior to being incremented.
  int operator++(int);

  // Atomically decrement the value of this object by 1 and return the
  // resulting value.
  int operator--();

  // Atomically decrement the value of this object by 1 and return the
  // value prior to being decremented.
  int operator--(int);

  // Atomically add the specified 'value' to this object and return the
  // resulting value.
  int add(int value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  int addAcqRel(int value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the relaxed memory ordering guarantee.
  int addRelaxed(int value);

  // Atomically assign the specified 'value' to this object, providing
  // the sequential consistency memory ordering guarantee.
  void store(int value);

  // Atomically assign the specified 'value' to this object, providing
  // the relaxed memory ordering guarantee.
  void storeRelaxed(int value);

  // Atomically assign the specified 'value' to this object, providing
  // the release memory ordering guarantee.
  void storeRelease(int value);

  // Atomically subtract the specified 'value' to this object and return
  // the resulting value.
  int subtract(int value);

  // Atomically subtract the specified 'value' to this object and return
  // the resulting value, providing the acquire/release memory ordering
  // guarantee.
  int subtractAcqRel(int value);

  // Atomically subtract the specified 'value' to this object and return
  // the resulting value, providing the relaxed memory ordering
  // guarantee.
  int subtractRelaxed(int value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value.
  int swap(int swap_value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value, providing the acquire/release memory
  // ordering guarantee.
  int swapAcqRel(int swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic integer to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic integer, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically.
  int testAndSwap(int compare_value, int swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic integer to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic integer, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically and it provides the acquire/release memory ordering
  // guarantee.
  int testAndSwapAcqRel(int compare_value, int swap_value);

  // Return the current value of this object.
  operator int() const;

  // Return the current value of this object.
  int load() const;

  // Return the current value of this object, providing the acquire
  // memory ordering guarantee.
  int loadAcquire() const;

  // Return the current value of this object, providing the relaxed
  // memory ordering guarantee.
  int loadRelaxed() const;
};

class AtomicInt64 {
  AtomicOperations::AtomicTypes::Int64 d_value;

 private:
  AtomicInt64(const AtomicInt64&);             // = delete
  AtomicInt64& operator=(const AtomicInt64&);  // = delete

 public:
  // Create an atomic 64-bit integer object having the default value 0.
  AtomicInt64();

  // Create an atomic 64-bit integer object having the specified 'value'.
  AtomicInt64(Types::Int64 value);

  // Destroy this atomic 64-bit integer object.
  //! ~AtomicInt64() = default;

  // Atomically assign the specified 'value' to this object, and return a
  // reference offering modifiable access to 'this' object.
  AtomicInt64& operator=(Types::Int64 value);

  // Atomically add the specified 'value' to this object, and return the
  // resulting value.
  Types::Int64 operator+=(Types::Int64 value);

  // Atomically subtract the specified 'value' from this object, and
  // return the resulting value.
  Types::Int64 operator-=(Types::Int64 value);

  // Atomically increment the value of this object by 1 and return the
  // resulting value.
  Types::Int64 operator++();

  // Atomically increment the value of this object by 1 and return the
  // value prior to being incremented.
  Types::Int64 operator++(int);

  // Atomically decrement the value of this object by 1 and return the
  // resulting value.
  Types::Int64 operator--();

  // Atomically decrement the value of this object by 1 and return the
  // value prior to being decremented.
  Types::Int64 operator--(int);

  // Atomically add the specified 'value' to this object and return the
  // resulting value.
  Types::Int64 add(Types::Int64 value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  Types::Int64 addAcqRel(Types::Int64 value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the relaxed memory ordering guarantee.
  Types::Int64 addRelaxed(Types::Int64 value);

  // Atomically assign the specified 'value' to this object, providing
  // the sequential consistency memory ordering guarantee.
  void store(Types::Int64 value);

  // Atomically assign the specified 'value' to this object, providing
  // the relaxed memory ordering guarantee.
  void storeRelaxed(Types::Int64 value);

  // Atomically assign the specified 'value' to this object, providing
  // the release memory ordering guarantee.
  void storeRelease(Types::Int64 value);

  // Atomically subtract the specified 'value' to this object and return
  // the resulting value.
  Types::Int64 subtract(Types::Int64 value);

  // Atomically subtract the specified 'value' to this object and return
  // the resulting value, providing the acquire/release memory ordering
  // guarantee.
  Types::Int64 subtractAcqRel(Types::Int64 value);

  // Atomically subtract the specified 'value' to this object and return
  // the resulting value, providing the relaxed memory ordering
  // guarantee.
  Types::Int64 subtractRelaxed(Types::Int64 value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value.
  Types::Int64 swap(Types::Int64 swap_value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value, providing the acquire/release memory
  // ordering guarantee.
  Types::Int64 swapAcqRel(Types::Int64 swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic integer to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic integer, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically.
  Types::Int64 testAndSwap(Types::Int64 compare_value, Types::Int64 swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic integer to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic integer, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically and it provides the acquire/release memory ordering
  // guarantee.
  Types::Int64 testAndSwapAcqRel(Types::Int64 compare_value,
                                 Types::Int64 swap_value);

  // Return the current value of this object.
  operator Types::Int64() const;

  // Return the current value of this object.
  Types::Int64 load() const;

  // Return the current value of this object, providing the acquire
  // memory ordering guarantee.
  Types::Int64 loadAcquire() const;

  // Return the current value of this object, providing the relaxed
  // memory ordering guarantee.
  Types::Int64 loadRelaxed() const;
};

class AtomicUint {
  AtomicOperations::AtomicTypes::Uint d_value;

 private:
  // NOT IMPLEMENTED
  AtomicUint(const AtomicInt&);             // = delete
  AtomicUint& operator=(const AtomicInt&);  // = delete

 public:
  // Create an atomic unsigned integer object having the default value 0.
  AtomicUint();

  // Create an atomic unsigned integer object having the specified
  // 'value'.
  AtomicUint(unsigned int value);

  // Destroy this atomic unsigned integer object.
  //! ~AtomicUint() = default;

  // Atomically assign the specified 'value' to this object, and return a
  // reference offering modifiable access to 'this' object.
  AtomicUint& operator=(unsigned int value);

  // Atomically add the specified 'value' to this object, and return the
  // resulting value.
  unsigned int operator+=(unsigned int value);

  // Atomically subtract the specified 'value' from this object, and
  // return the resulting value.
  unsigned int operator-=(unsigned int value);

  // Atomically increment the value of this object by 1 and return the
  // resulting value.
  unsigned int operator++();

  // Atomically increment the value of this object by 1 and return the
  // value prior to being incremented.
  unsigned int operator++(int);

  // Atomically decrement the value of this object by 1 and return the
  // resulting value.
  unsigned int operator--();

  // Atomically decrement the value of this object by 1 and return the
  // value prior to being decremented.
  unsigned int operator--(int);

  // Atomically add the specified 'value' to this object and return the
  // resulting value.
  unsigned int add(unsigned int value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  unsigned int addAcqRel(unsigned int value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the relaxed memory ordering guarantee.
  unsigned int addRelaxed(unsigned int value);

  // Atomically assign the specified 'value' to this object, providing
  // the sequential consistency memory ordering guarantee.
  void store(unsigned int value);

  // Atomically assign the specified 'value' to this object, providing
  // the relaxed memory ordering guarantee.
  void storeRelaxed(unsigned int value);

  // Atomically assign the specified 'value' to this object, providing
  // the release memory ordering guarantee.
  void storeRelease(unsigned int value);

  // Atomically subtract the specified 'value' from this object and
  // return the resulting value.
  unsigned int subtract(unsigned int value);

  // Atomically subtract the specified 'value' from this object and
  // return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  unsigned int subtractAcqRel(unsigned int value);

  // Atomically subtract the specified 'value' from this object and
  // return the resulting value, providing the relaxed memory ordering
  // guarantee.
  unsigned int subtractRelaxed(unsigned int value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value.
  unsigned int swap(unsigned int swap_value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value, providing the acquire/release memory
  // ordering guarantee.
  unsigned int swapAcqRel(unsigned int swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic unsigned integer to
  // the specified 'swap_value', otherwise leave this value unchanged.
  // Return the previous value of this atomic unsigned integer, whether
  // or not the swap occurred.  Note that the entire test-and-swap
  // operation is performed atomically.
  unsigned int testAndSwap(unsigned int compare_value, unsigned int swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic unsigned integer to
  // the specified 'swap_value', otherwise leave this value unchanged.
  // Return the previous value of this atomic unsigned integer, whether
  // or not the swap occurred.  Note that the entire test-and-swap
  // operation is performed atomically and it provides the
  // acquire/release memory ordering guarantee.
  unsigned int testAndSwapAcqRel(unsigned int compare_value,
                                 unsigned int swap_value);

  // Return the current value of this object.
  operator unsigned int() const;

  // Return the current value of this object.
  unsigned int load() const;

  // Return the current value of this object, providing the acquire
  // memory ordering guarantee.
  unsigned int loadAcquire() const;

  // Return the current value of this object, providing the relaxed
  // memory ordering guarantee.
  unsigned int loadRelaxed() const;
};

class AtomicUint64 {
  AtomicOperations::AtomicTypes::Uint64 d_value;

 private:
  // NOT IMPLEMENTED
  AtomicUint64(const AtomicUint64&);             // = delete
  AtomicUint64& operator=(const AtomicUint64&);  // = delete

 public:
  // Create an atomic 64-bit unsigned integer object having the default
  // value 0.
  AtomicUint64();

  // Create an atomic 64-bit unsigned integer object having the specified
  // 'value'.
  AtomicUint64(Types::Uint64 value);

  // Destroy this atomic 64-bit unsigned integer object.
  //! ~AtomicUint64() = default;

  // Atomically assign the specified 'value' to this object, and return a
  // reference offering modifiable access to 'this' object.
  AtomicUint64& operator=(Types::Uint64 value);

  // Atomically add the specified 'value' to this object, and return the
  // resulting value.
  Types::Uint64 operator+=(Types::Uint64 value);

  // Atomically subtract the specified 'value' from this object, and
  // return the resulting value.
  Types::Uint64 operator-=(Types::Uint64 value);

  // Atomically increment the value of this object by 1 and return the
  // resulting value.
  Types::Uint64 operator++();

  // Atomically increment the value of this object by 1 and return the
  // value prior to being incremented.
  Types::Uint64 operator++(int);

  // Atomically decrement the value of this object by 1 and return the
  // resulting value.
  Types::Uint64 operator--();

  // Atomically decrement the value of this object by 1 and return the
  // value prior to being decremented.
  Types::Uint64 operator--(int);

  // Atomically add the specified 'value' to this object and return the
  // resulting value.
  Types::Uint64 add(Types::Uint64 value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the relaxed memory ordering guarantee.
  Types::Uint64 addRelaxed(Types::Uint64 value);

  // Atomically add the specified 'value' to this object and return the
  // resulting value, providing the acquire/release memory ordering
  // guarantee.
  Types::Uint64 addAcqRel(Types::Uint64 value);

  // Atomically assign the specified 'value' to this object, providing
  // the sequential consistency memory ordering guarantee.
  void store(Types::Uint64 value);

  // Atomically assign the specified 'value' to this object, providing
  // the relaxed memory ordering guarantee.
  void storeRelaxed(Types::Uint64 value);

  // Atomically assign the specified 'value' to this object, providing
  // the release memory ordering guarantee.
  void storeRelease(Types::Uint64 value);

  // Atomically subtract the specified 'value' from this object and
  // return the resulting value.
  Types::Uint64 subtract(Types::Uint64 value);

  // Atomically subtract the specified 'value' from this object and
  // return the resulting value, providing the acquire/release memory
  // ordering guarantee.
  Types::Uint64 subtractAcqRel(Types::Uint64 value);

  // Atomically subtract the specified 'value' from this object and
  // return the resulting value, providing the relaxed memory ordering
  // guarantee.
  Types::Uint64 subtractRelaxed(Types::Uint64 value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value.
  Types::Uint64 swap(Types::Uint64 swap_value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value, providing the acquire/release memory
  // ordering guarantee.
  Types::Uint64 swapAcqRel(Types::Uint64 swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic 64-bit unsigned
  // integer to the specified 'swap_value', otherwise leave this value
  // unchanged.  Return the previous value of this atomic unsigned
  // integer, whether or not the swap occurred.  Note that the entire
  // test-and-swap operation is performed atomically.
  Types::Uint64 testAndSwap(Types::Uint64 compare_value,
                            Types::Uint64 swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic 64-bit unsigned
  // integer to the specified 'swap_value', otherwise leave this value
  // unchanged.  Return the previous value of this atomic unsigned
  // integer, whether or not the swap occurred.  Note that the entire
  // test-and-swap operation is performed atomically and it provides the
  // acquire/release memory ordering guarantee.
  Types::Uint64 testAndSwapAcqRel(Types::Uint64 compare_value,
                                  Types::Uint64 swap_value);

  // Return the current value of this object.
  operator Types::Uint64() const;

  // Return the current value of this object.
  Types::Uint64 load() const;

  // Return the current value of this object, providing the relaxed
  // memory ordering guarantee.
  Types::Uint64 loadRelaxed() const;

  // Return the current value of this object, providing the acquire
  // memory ordering guarantee.
  Types::Uint64 loadAcquire() const;
};

template <class TYPE>
class AtomicPointer {
  typedef char
      AtomicPointerPointerSizeCheck[sizeof(TYPE*) == sizeof(void*) ? 1 : -1];

  template <class TYPE1>
  struct RemoveConst {
    typedef TYPE1 Type;
  };
  template <class TYPE1>
  struct RemoveConst<TYPE1 const> {
    typedef TYPE1 Type;
  };

  typedef typename RemoveConst<TYPE>::Type NcType;

  AtomicOperations::AtomicTypes::Pointer d_value;

 private:
  // NOT IMPLEMENTED
  AtomicPointer(const AtomicPointer<TYPE>&);                   // = delete
  AtomicPointer<TYPE>& operator=(const AtomicPointer<TYPE>&);  // = delete

 public:
  // Create an atomic pointer object having the default value NULL.
  AtomicPointer();

  // Create an atomic pointer object having the specified 'value'.
  AtomicPointer(TYPE* value);

  // Destroy this atomic pointer.
  //! ~AtomicPointer() = default;

  // Atomically assign the specified 'value' to this object, and return a
  // reference offering modifiable access to 'this' object.
  AtomicPointer<TYPE>& operator=(TYPE* value);

  // Atomically assign the specified 'value' to this object, providing
  // the sequential consistency memory ordering guarantee.
  void store(TYPE* value);

  // Atomically assign the specified 'value' to this object, providing
  // the relaxed memory ordering guarantee.
  void storeRelaxed(TYPE* value);

  // Atomically assign the specified 'value' to this object, providing
  // the release memory ordering guarantee.
  void storeRelease(TYPE* value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value.
  TYPE* swap(TYPE* swap_value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value, providing the acquire/release memory
  // ordering guarantee.
  TYPE* swapAcqRel(TYPE* swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic pointer to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic pointer, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically.
  TYPE* testAndSwap(const TYPE* compare_value, TYPE* swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic pointer to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic pointer, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically and it provides the acquire/release memory ordering
  // guarantee.
  TYPE* testAndSwapAcqRel(const TYPE* compare_value, TYPE* swap_value);

  // Return a reference to the value currently pointed to by this object.
  // The behavior is undefined if this pointer has a value of 0.
  TYPE& operator*() const;

  // Return the current value of this object.
  TYPE* operator->() const;

  // Return the current value of this object.
  operator TYPE*() const;

  // Return the current value of this object.
  TYPE* load() const;

  // Return the current value of this object, providing the relaxed
  // memory ordering guarantee.
  TYPE* loadRelaxed() const;

  // Return the current value of this object, providing the acquire
  // memory ordering guarantee.
  TYPE* loadAcquire() const;
};

class AtomicBool {
  enum { e_FALSE, e_TRUE };
  AtomicOperations::AtomicTypes::Int d_value;

 private:
  // NOT IMPLEMENTED
  AtomicBool(const AtomicBool&);             // = delete
  AtomicBool& operator=(const AtomicBool&);  // = delete

 public:
  // Create an atomic boolean object having the default value 'false'.
  AtomicBool();

  // Create an atomic boolean object having the specified 'value'.
  AtomicBool(bool value);

  // Destroy this atomic boolean object.
  //! ~AtomicBool() = default;

  // Atomically assign the specified 'value' to this object, and return a
  // reference offering modifiable access to 'this' object.
  AtomicBool& operator=(bool value);

  // Atomically assign the specified 'value' to this object, providing
  // the sequential consistency memory ordering guarantee.
  void store(bool value);

  // Atomically assign the specified 'value' to this object, providing
  // the relaxed memory ordering guarantee.
  void storeRelaxed(bool value);

  // Atomically assign the specified 'value' to this object, providing
  // the release memory ordering guarantee.
  void storeRelease(bool value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value.
  bool swap(bool swap_value);

  // Atomically set the value of this object to the specified 'swap_value'
  // and return its previous value, providing the acquire/release memory
  // ordering guarantee.
  bool swapAcqRel(bool swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic boolean to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic boolean, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically.
  bool testAndSwap(bool compare_value, bool swap_value);

  // Compare the value of this object to the specified 'compare_value'.
  // If they are equal, set the value of this atomic boolean to the
  // specified 'swap_value', otherwise leave this value unchanged.  Return
  // the previous value of this atomic boolean, whether or not the swap
  // occurred.  Note that the entire test-and-swap operation is performed
  // atomically and it provides the acquire/release memory ordering
  // guarantee.
  bool testAndSwapAcqRel(bool compare_value, bool swap_value);

  // Return the current value of this object.
  operator bool() const;

  // Return the current value of this object.
  bool load() const;

  // Return the current value of this object, providing the relaxed
  // memory ordering guarantee.
  bool loadRelaxed() const;

  // Return the current value of this object, providing the acquire
  // memory ordering guarantee.
  bool loadAcquire() const;
};

inline AtomicInt::AtomicInt() { AtomicOperationsImpl::initInt(&d_value, 0); }

inline AtomicInt::AtomicInt(int value) {
  AtomicOperationsImpl::initInt(&d_value, value);
}

// MANIPULATORS
inline AtomicInt& AtomicInt::operator=(int value) {
  AtomicOperationsImpl::setInt(&d_value, value);
  return *this;
}

inline int AtomicInt::operator+=(int value) {
  return AtomicOperationsImpl::addIntNv(&d_value, value);
}

inline int AtomicInt::operator-=(int value) {
  return AtomicOperationsImpl::subtractIntNv(&d_value, value);
}

inline int AtomicInt::operator++() {
  return AtomicOperationsImpl::incrementIntNv(&d_value);
}

inline int AtomicInt::operator++(int) {
  return static_cast<int>(static_cast<unsigned int>(
                              AtomicOperationsImpl::incrementIntNv(&d_value)) -
                          1);
}

inline int AtomicInt::operator--() {
  return AtomicOperationsImpl::decrementIntNv(&d_value);
}

inline int AtomicInt::operator--(int) {
  return static_cast<int>(static_cast<unsigned int>(
                              AtomicOperationsImpl::decrementIntNv(&d_value)) +
                          1);
}

inline int AtomicInt::add(int value) {
  return AtomicOperationsImpl::addIntNv(&d_value, value);
}

inline int AtomicInt::addAcqRel(int value) {
  return AtomicOperationsImpl::addIntNvAcqRel(&d_value, value);
}

inline int AtomicInt::addRelaxed(int value) {
  return AtomicOperationsImpl::addIntNvRelaxed(&d_value, value);
}

inline void AtomicInt::store(int value) {
  AtomicOperationsImpl::setInt(&d_value, value);
}

inline void AtomicInt::storeRelaxed(int value) {
  AtomicOperationsImpl::setIntRelaxed(&d_value, value);
}

inline void AtomicInt::storeRelease(int value) {
  AtomicOperationsImpl::setIntRelease(&d_value, value);
}

inline int AtomicInt::subtract(int value) {
  return AtomicOperationsImpl::subtractIntNv(&d_value, value);
}

inline int AtomicInt::subtractAcqRel(int value) {
  return AtomicOperationsImpl::subtractIntNvAcqRel(&d_value, value);
}

inline int AtomicInt::subtractRelaxed(int value) {
  return AtomicOperationsImpl::subtractIntNvRelaxed(&d_value, value);
}

inline int AtomicInt::swap(int swap_value) {
  return AtomicOperationsImpl::swapInt(&d_value, swap_value);
}

inline int AtomicInt::swapAcqRel(int swap_value) {
  return AtomicOperationsImpl::swapIntAcqRel(&d_value, swap_value);
}

inline int AtomicInt::testAndSwap(int compare_value, int swap_value) {
  return AtomicOperationsImpl::testAndSwapInt(&d_value, compare_value,
                                              swap_value);
}

inline int AtomicInt::testAndSwapAcqRel(int compare_value, int swap_value) {
  return AtomicOperationsImpl::testAndSwapIntAcqRel(&d_value, compare_value,
                                                    swap_value);
}

// ACCESSORS

inline AtomicInt::operator int() const {
  return AtomicOperationsImpl::getInt(&d_value);
}

inline int AtomicInt::load() const { return this->operator int(); }

inline int AtomicInt::loadAcquire() const {
  return AtomicOperationsImpl::getIntAcquire(&d_value);
}

inline int AtomicInt::loadRelaxed() const {
  return AtomicOperationsImpl::getIntRelaxed(&d_value);
}

// -----------------
// class AtomicInt64
// -----------------

// CREATORS
inline AtomicInt64::AtomicInt64() {
  AtomicOperationsImpl::initInt64(&d_value, 0);
}

inline AtomicInt64::AtomicInt64(Types::Int64 value) {
  AtomicOperationsImpl::initInt64(&d_value, value);
}

// MANIPULATORS
inline AtomicInt64& AtomicInt64::operator=(Types::Int64 value) {
  AtomicOperationsImpl::setInt64(&d_value, value);
  return *this;
}

inline Types::Int64 AtomicInt64::operator+=(Types::Int64 value) {
  return AtomicOperationsImpl::addInt64Nv(&d_value, value);
}

inline Types::Int64 AtomicInt64::operator-=(Types::Int64 value) {
  return AtomicOperationsImpl::subtractInt64Nv(&d_value, value);
}

inline Types::Int64 AtomicInt64::operator++() {
  return AtomicOperationsImpl::incrementInt64Nv(&d_value);
}

inline Types::Int64 AtomicInt64::operator++(int) {
  return static_cast<Types::Int64>(
      static_cast<Types::Uint64>(
          AtomicOperationsImpl::incrementInt64Nv(&d_value)) -
      1);
}

inline Types::Int64 AtomicInt64::operator--() {
  return AtomicOperationsImpl::decrementInt64Nv(&d_value);
}

inline Types::Int64 AtomicInt64::operator--(int) {
  return static_cast<Types::Int64>(
      static_cast<Types::Uint64>(
          AtomicOperationsImpl::decrementInt64Nv(&d_value)) +
      1);
}

inline Types::Int64 AtomicInt64::add(Types::Int64 value) {
  return AtomicOperationsImpl::addInt64Nv(&d_value, value);
}

inline Types::Int64 AtomicInt64::addAcqRel(Types::Int64 value) {
  return AtomicOperationsImpl::addInt64NvAcqRel(&d_value, value);
}

inline Types::Int64 AtomicInt64::addRelaxed(Types::Int64 value) {
  return AtomicOperationsImpl::addInt64NvRelaxed(&d_value, value);
}

inline void AtomicInt64::store(Types::Int64 value) {
  AtomicOperationsImpl::setInt64(&d_value, value);
}

inline void AtomicInt64::storeRelaxed(Types::Int64 value) {
  AtomicOperationsImpl::setInt64Relaxed(&d_value, value);
}

inline void AtomicInt64::storeRelease(Types::Int64 value) {
  AtomicOperationsImpl::setInt64Release(&d_value, value);
}

inline Types::Int64 AtomicInt64::subtract(Types::Int64 value) {
  return AtomicOperationsImpl::subtractInt64Nv(&d_value, value);
}

inline Types::Int64 AtomicInt64::subtractAcqRel(Types::Int64 value) {
  return AtomicOperationsImpl::subtractInt64NvAcqRel(&d_value, value);
}

inline Types::Int64 AtomicInt64::subtractRelaxed(Types::Int64 value) {
  return AtomicOperationsImpl::subtractInt64NvRelaxed(&d_value, value);
}

inline Types::Int64 AtomicInt64::swap(Types::Int64 swap_value) {
  return AtomicOperationsImpl::swapInt64(&d_value, swap_value);
}

inline Types::Int64 AtomicInt64::swapAcqRel(Types::Int64 swap_value) {
  return AtomicOperationsImpl::swapInt64AcqRel(&d_value, swap_value);
}

inline Types::Int64 AtomicInt64::testAndSwap(Types::Int64 compare_value,
                                             Types::Int64 swap_value) {
  return AtomicOperationsImpl::testAndSwapInt64(&d_value, compare_value,
                                                swap_value);
}

inline Types::Int64 AtomicInt64::testAndSwapAcqRel(Types::Int64 compare_value,
                                                   Types::Int64 swap_value) {
  return AtomicOperationsImpl::testAndSwapInt64AcqRel(&d_value, compare_value,
                                                      swap_value);
}

// ACCESSORS
inline AtomicInt64::operator Types::Int64() const {
  return AtomicOperationsImpl::getInt64(&d_value);
}

inline Types::Int64 AtomicInt64::load() const {
  return this->operator Types::Int64();
}

inline Types::Int64 AtomicInt64::loadAcquire() const {
  return AtomicOperationsImpl::getInt64Acquire(&d_value);
}

inline Types::Int64 AtomicInt64::loadRelaxed() const {
  return AtomicOperationsImpl::getInt64Relaxed(&d_value);
}

// ---------------
// class AtomicUint
// ---------------

// CREATORS
inline AtomicUint::AtomicUint() { AtomicOperationsImpl::initUint(&d_value, 0); }

inline AtomicUint::AtomicUint(unsigned int value) {
  AtomicOperationsImpl::initUint(&d_value, value);
}

// MANIPULATORS
inline AtomicUint& AtomicUint::operator=(unsigned int value) {
  AtomicOperationsImpl::setUint(&d_value, value);
  return *this;
}

inline unsigned int AtomicUint::operator+=(unsigned int value) {
  return AtomicOperationsImpl::addUintNv(&d_value, value);
}

inline unsigned int AtomicUint::operator-=(unsigned int value) {
  return AtomicOperationsImpl::subtractUintNv(&d_value, value);
}

inline unsigned int AtomicUint::operator++() {
  return AtomicOperationsImpl::incrementUintNv(&d_value);
}

inline unsigned int AtomicUint::operator++(int) {
  return AtomicOperationsImpl::incrementUintNv(&d_value) - 1;
}

inline unsigned int AtomicUint::operator--() {
  return AtomicOperationsImpl::decrementUintNv(&d_value);
}

inline unsigned int AtomicUint::operator--(int) {
  return AtomicOperationsImpl::decrementUintNv(&d_value) + 1;
}

inline unsigned int AtomicUint::add(unsigned int value) {
  return AtomicOperationsImpl::addUintNv(&d_value, value);
}

inline unsigned int AtomicUint::addAcqRel(unsigned int value) {
  return AtomicOperationsImpl::addUintNvAcqRel(&d_value, value);
}

inline unsigned int AtomicUint::addRelaxed(unsigned int value) {
  return AtomicOperationsImpl::addUintNvRelaxed(&d_value, value);
}

inline void AtomicUint::store(unsigned int value) {
  AtomicOperationsImpl::setUint(&d_value, value);
}

inline void AtomicUint::storeRelaxed(unsigned int value) {
  AtomicOperationsImpl::setUintRelaxed(&d_value, value);
}

inline void AtomicUint::storeRelease(unsigned int value) {
  AtomicOperationsImpl::setUintRelease(&d_value, value);
}

inline unsigned int AtomicUint::subtract(unsigned int value) {
  return AtomicOperationsImpl::subtractUintNv(&d_value, value);
}

inline unsigned int AtomicUint::subtractAcqRel(unsigned int value) {
  return AtomicOperationsImpl::subtractUintNvAcqRel(&d_value, value);
}

inline unsigned int AtomicUint::subtractRelaxed(unsigned int value) {
  return AtomicOperationsImpl::subtractUintNvRelaxed(&d_value, value);
}

inline unsigned int AtomicUint::swap(unsigned int swap_value) {
  return AtomicOperationsImpl::swapUint(&d_value, swap_value);
}

inline unsigned int AtomicUint::swapAcqRel(unsigned int swap_value) {
  return AtomicOperationsImpl::swapUintAcqRel(&d_value, swap_value);
}

inline unsigned int AtomicUint::testAndSwap(unsigned int compare_value,
                                            unsigned int swap_value) {
  return AtomicOperationsImpl::testAndSwapUint(&d_value, compare_value,
                                               swap_value);
}

inline unsigned int AtomicUint::testAndSwapAcqRel(unsigned int compare_value,
                                                  unsigned int swap_value) {
  return AtomicOperationsImpl::testAndSwapUintAcqRel(&d_value, compare_value,
                                                     swap_value);
}

// ACCESSORS

inline AtomicUint::operator unsigned int() const {
  return AtomicOperationsImpl::getUint(&d_value);
}

inline unsigned int AtomicUint::load() const {
  return this->operator unsigned int();
}

inline unsigned int AtomicUint::loadAcquire() const {
  return AtomicOperationsImpl::getUintAcquire(&d_value);
}

inline unsigned int AtomicUint::loadRelaxed() const {
  return AtomicOperationsImpl::getUintRelaxed(&d_value);
}

// -----------------
// class AtomicUint64
// -----------------

// CREATORS
inline AtomicUint64::AtomicUint64() {
  AtomicOperationsImpl::initUint64(&d_value, 0);
}

inline AtomicUint64::AtomicUint64(Types::Uint64 value) {
  AtomicOperationsImpl::initUint64(&d_value, value);
}

// MANIPULATORS
inline AtomicUint64& AtomicUint64::operator=(Types::Uint64 value) {
  AtomicOperationsImpl::setUint64(&d_value, value);
  return *this;
}

inline Types::Uint64 AtomicUint64::operator+=(Types::Uint64 value) {
  return AtomicOperationsImpl::addUint64Nv(&d_value, value);
}

inline Types::Uint64 AtomicUint64::operator-=(Types::Uint64 value) {
  return AtomicOperationsImpl::subtractUint64Nv(&d_value, value);
}

inline Types::Uint64 AtomicUint64::operator++() {
  return AtomicOperationsImpl::incrementUint64Nv(&d_value);
}

inline Types::Uint64 AtomicUint64::operator++(int) {
  return AtomicOperationsImpl::incrementUint64Nv(&d_value) - 1;
}

inline Types::Uint64 AtomicUint64::operator--() {
  return AtomicOperationsImpl::decrementUint64Nv(&d_value);
}

inline Types::Uint64 AtomicUint64::operator--(int) {
  return AtomicOperationsImpl::decrementUint64Nv(&d_value) + 1;
}

inline Types::Uint64 AtomicUint64::add(Types::Uint64 value) {
  return AtomicOperationsImpl::addUint64Nv(&d_value, value);
}

inline Types::Uint64 AtomicUint64::addAcqRel(Types::Uint64 value) {
  return AtomicOperationsImpl::addUint64NvAcqRel(&d_value, value);
}

inline Types::Uint64 AtomicUint64::addRelaxed(Types::Uint64 value) {
  return AtomicOperationsImpl::addUint64NvRelaxed(&d_value, value);
}

inline void AtomicUint64::store(Types::Uint64 value) {
  AtomicOperationsImpl::setUint64(&d_value, value);
}

inline void AtomicUint64::storeRelaxed(Types::Uint64 value) {
  AtomicOperationsImpl::setUint64Relaxed(&d_value, value);
}

inline void AtomicUint64::storeRelease(Types::Uint64 value) {
  AtomicOperationsImpl::setUint64Release(&d_value, value);
}

inline Types::Uint64 AtomicUint64::subtract(Types::Uint64 value) {
  return AtomicOperationsImpl::subtractUint64Nv(&d_value, value);
}

inline Types::Uint64 AtomicUint64::subtractAcqRel(Types::Uint64 value) {
  return AtomicOperationsImpl::subtractUint64NvAcqRel(&d_value, value);
}

inline Types::Uint64 AtomicUint64::subtractRelaxed(Types::Uint64 value) {
  return AtomicOperationsImpl::subtractUint64NvRelaxed(&d_value, value);
}

inline Types::Uint64 AtomicUint64::swap(Types::Uint64 swap_value) {
  return AtomicOperationsImpl::swapUint64(&d_value, swap_value);
}

inline Types::Uint64 AtomicUint64::swapAcqRel(Types::Uint64 swap_value) {
  return AtomicOperationsImpl::swapUint64AcqRel(&d_value, swap_value);
}

inline Types::Uint64 AtomicUint64::testAndSwap(Types::Uint64 compare_value,
                                               Types::Uint64 swap_value) {
  return AtomicOperationsImpl::testAndSwapUint64(&d_value, compare_value,
                                                 swap_value);
}

inline Types::Uint64 AtomicUint64::testAndSwapAcqRel(Types::Uint64 compare_value,
                                                     Types::Uint64 swap_value) {
  return AtomicOperationsImpl::testAndSwapUint64AcqRel(&d_value, compare_value,
                                                       swap_value);
}

// ACCESSORS
inline AtomicUint64::operator Types::Uint64() const {
  return AtomicOperationsImpl::getUint64(&d_value);
}

inline Types::Uint64 AtomicUint64::load() const {
  return this->operator Types::Uint64();
}

inline Types::Uint64 AtomicUint64::loadAcquire() const {
  return AtomicOperationsImpl::getUint64Acquire(&d_value);
}

inline Types::Uint64 AtomicUint64::loadRelaxed() const {
  return AtomicOperationsImpl::getUint64Relaxed(&d_value);
}

// -------------------
// class AtomicPointer
// -------------------

// CREATORS
template <class TYPE>
inline AtomicPointer<TYPE>::AtomicPointer() {
  AtomicOperationsImpl::initPointer(&d_value, 0);
}

template <class TYPE>
inline AtomicPointer<TYPE>::AtomicPointer(TYPE* value) {
  AtomicOperationsImpl::initPointer(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(value)));
}

// MANIPULATORS
template <class TYPE>
inline AtomicPointer<TYPE>& AtomicPointer<TYPE>::operator=(TYPE* value) {
  AtomicOperationsImpl::setPtr(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(value)));
  return *this;
}

template <class TYPE>
inline void AtomicPointer<TYPE>::store(TYPE* value) {
  AtomicOperationsImpl::setPtr(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(value)));
}

template <class TYPE>
inline void AtomicPointer<TYPE>::storeRelaxed(TYPE* value) {
  AtomicOperationsImpl::setPtrRelaxed(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(value)));
}

template <class TYPE>
inline void AtomicPointer<TYPE>::storeRelease(TYPE* value) {
  AtomicOperationsImpl::setPtrRelease(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(value)));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::swap(TYPE* swap_value) {
  return reinterpret_cast<TYPE*>(AtomicOperationsImpl::swapPtr(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(swap_value))));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::swapAcqRel(TYPE* swap_value) {
  return reinterpret_cast<TYPE*>(AtomicOperationsImpl::swapPtrAcqRel(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(swap_value))));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::testAndSwap(const TYPE* compare_value,
                                              TYPE* swap_value) {
  return reinterpret_cast<TYPE*>(AtomicOperationsImpl::testAndSwapPtr(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(compare_value)),
      reinterpret_cast<void*>(const_cast<NcType*>(swap_value))));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::testAndSwapAcqRel(const TYPE* compare_value,
                                                    TYPE* swap_value) {
  return reinterpret_cast<TYPE*>(AtomicOperationsImpl::testAndSwapPtrAcqRel(
      &d_value, reinterpret_cast<void*>(const_cast<NcType*>(compare_value)),
      reinterpret_cast<void*>(const_cast<NcType*>(swap_value))));
}

// ACCESSORS
template <class TYPE>
inline AtomicPointer<TYPE>::operator TYPE*() const {
  return static_cast<TYPE*>(AtomicOperationsImpl::getPtr(&d_value));
}

template <class TYPE>
inline TYPE& AtomicPointer<TYPE>::operator*() const {
  return *(static_cast<TYPE*>(AtomicOperationsImpl::getPtr(&d_value)));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::operator->() const {
  return static_cast<TYPE*>(AtomicOperationsImpl::getPtr(&d_value));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::load() const {
  return this->operator TYPE*();
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::loadAcquire() const {
  return static_cast<TYPE*>(AtomicOperationsImpl::getPtrAcquire(&d_value));
}

template <class TYPE>
inline TYPE* AtomicPointer<TYPE>::loadRelaxed() const {
  return static_cast<TYPE*>(AtomicOperationsImpl::getPtrRelaxed(&d_value));
}

// ----------------
// class AtomicBool
// ----------------

// CREATORS
inline AtomicBool::AtomicBool() {
  AtomicOperationsImpl::initInt(&d_value, AtomicBool::e_FALSE);
}

inline AtomicBool::AtomicBool(bool value) {
  AtomicOperationsImpl::initInt(
      &d_value, value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE);
}

// MANIPULATORS
inline AtomicBool& AtomicBool::operator=(bool value) {
  AtomicOperationsImpl::setInt(
      &d_value, value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE);
  return *this;
}

inline void AtomicBool::store(bool value) {
  AtomicOperationsImpl::setInt(
      &d_value, value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE);
}

inline void AtomicBool::storeRelaxed(bool value) {
  AtomicOperationsImpl::setIntRelaxed(
      &d_value, value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE);
}

inline void AtomicBool::storeRelease(bool value) {
  AtomicOperationsImpl::setIntRelease(
      &d_value, value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE);
}

inline bool AtomicBool::swap(bool swap_value) {
  return AtomicOperationsImpl::swapInt(
             &d_value, swap_value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE) ==
         AtomicBool::e_TRUE;
}

inline bool AtomicBool::swapAcqRel(bool swap_value) {
  return AtomicOperationsImpl::swapIntAcqRel(
             &d_value, swap_value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE) ==
         AtomicBool::e_TRUE;
}

inline bool AtomicBool::testAndSwap(bool compare_value, bool swap_value) {
  return AtomicOperationsImpl::testAndSwapInt(
             &d_value, compare_value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE,
             swap_value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE) ==
         AtomicBool::e_TRUE;
}

inline bool AtomicBool::testAndSwapAcqRel(bool compare_value, bool swap_value) {
  return AtomicOperationsImpl::testAndSwapIntAcqRel(
             &d_value, compare_value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE,
             swap_value ? AtomicBool::e_TRUE : AtomicBool::e_FALSE) ==
         AtomicBool::e_TRUE;
}

// ACCESSORS

inline AtomicBool::operator bool() const {
  return AtomicOperationsImpl::getInt(&d_value) == AtomicBool::e_TRUE;
}

inline bool AtomicBool::load() const { return this->operator bool(); }

inline bool AtomicBool::loadAcquire() const {
  return AtomicOperationsImpl::getIntAcquire(&d_value) == AtomicBool::e_TRUE;
}

inline bool AtomicBool::loadRelaxed() const {
  return AtomicOperationsImpl::getIntRelaxed(&d_value) == AtomicBool::e_TRUE;
}

}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_SYSTEM_ATOMIC_H