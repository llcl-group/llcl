#ifndef LLCL_STANDARD_SUPPORT_POINTERLIKETYPETRAITS_H
#define LLCL_STANDARD_SUPPORT_POINTERLIKETYPETRAITS_H

#include <cassert>
#include <type_traits>

#include "llcl/Standard/Support/DataTypes.h"

namespace llcl {

template <typename T>
struct PointerLikeTypeTraits;

namespace detail {

template <size_t N>
struct ConstantLog2
    : std::integral_constant<size_t, ConstantLog2<N / 2>::value + 1> {};
template <>
struct ConstantLog2<1> : std::integral_constant<size_t, 0> {};

template <typename T, typename U = void>
struct HasPointerLikeTypeTraits {
  static const bool value = false;
};

template <typename T>
struct HasPointerLikeTypeTraits<
    T, decltype((sizeof(PointerLikeTypeTraits<T>) + sizeof(T)), void())> {
  static const bool value = true;
};

template <typename T>
struct IsPointerLike {
  static const bool value = HasPointerLikeTypeTraits<T>::value;
};

template <typename T>
struct IsPointerLike<T*> {
  static const bool value = true;
};

}  // namespace detail

template <typename T>
struct PointerLikeTypeTraits<T*> {
  static inline void* getAsVoidPointer(T* P) { return P; }
  static inline T* getFromVoidPointer(void* P) { return static_cast<T*>(P); }

  static constexpr int NumLowBitsAvailable =
      detail::ConstantLog2<alignof(T)>::value;
};

template <>
struct PointerLikeTypeTraits<void*> {
  static inline void* getAsVoidPointer(void* P) { return P; }
  static inline void* getFromVoidPointer(void* P) { return P; }

  /// Note, we assume here that void* is related to raw malloc'ed memory and
  /// that malloc returns objects at least 4-byte aligned. However, this may be
  /// wrong, or pointers may be from something other than malloc. In this case,
  /// you should specify a real typed pointer or avoid this template.
  ///
  /// All clients should use assertions to do a run-time check to ensure that
  /// this is actually true.
  static constexpr int NumLowBitsAvailable = 2;
};

// Provide PointerLikeTypeTraits for const things.
template <typename T>
struct PointerLikeTypeTraits<const T> {
  typedef PointerLikeTypeTraits<T> NonConst;

  static inline const void* getAsVoidPointer(const T P) {
    return NonConst::getAsVoidPointer(P);
  }
  static inline const T getFromVoidPointer(const void* P) {
    return NonConst::getFromVoidPointer(const_cast<void*>(P));
  }
  static constexpr int NumLowBitsAvailable = NonConst::NumLowBitsAvailable;
};

// Provide PointerLikeTypeTraits for const pointers.
template <typename T>
struct PointerLikeTypeTraits<const T*> {
  typedef PointerLikeTypeTraits<T*> NonConst;

  static inline const void* getAsVoidPointer(const T* P) {
    return NonConst::getAsVoidPointer(const_cast<T*>(P));
  }
  static inline const T* getFromVoidPointer(const void* P) {
    return NonConst::getFromVoidPointer(const_cast<void*>(P));
  }
  static constexpr int NumLowBitsAvailable = NonConst::NumLowBitsAvailable;
};

// Provide PointerLikeTypeTraits for uintptr_t.
template <>
struct PointerLikeTypeTraits<uintptr_t> {
  static inline void* getAsVoidPointer(uintptr_t P) {
    return reinterpret_cast<void*>(P);
  }
  static inline uintptr_t getFromVoidPointer(void* P) {
    return reinterpret_cast<uintptr_t>(P);
  }
  // No bits are available!
  static constexpr int NumLowBitsAvailable = 0;
};

/// Provide suitable custom traits struct for function pointers.
///
/// Function pointers can't be directly given these traits as functions can't
/// have their alignment computed with `alignof` and we need different casting.
///
/// To rely on higher alignment for a specialized use, you can provide a
/// customized form of this template explicitly with higher alignment, and
/// potentially use alignment attributes on functions to satisfy that.
template <int Alignment, typename FunctionPointerT>
struct FunctionPointerLikeTypeTraits {
  static constexpr int NumLowBitsAvailable =
      detail::ConstantLog2<Alignment>::value;
  static inline void* getAsVoidPointer(FunctionPointerT P) {
    assert((reinterpret_cast<uintptr_t>(P) &
            ~((uintptr_t)-1 << NumLowBitsAvailable)) == 0 &&
           "Alignment not satisfied for an actual function pointer!");
    return reinterpret_cast<void*>(P);
  }
  static inline FunctionPointerT getFromVoidPointer(void* P) {
    return reinterpret_cast<FunctionPointerT>(P);
  }
};

/// Provide a default specialization for function pointers that assumes 4-byte
/// alignment.
///
/// We assume here that functions used with this are always at least 4-byte
/// aligned. This means that, for example, thumb functions won't work or systems
/// with weird unaligned function pointers won't work. But all practical systems
/// we support satisfy this requirement.
template <typename ReturnT, typename... ParamTs>
struct PointerLikeTypeTraits<ReturnT (*)(ParamTs...)>
    : FunctionPointerLikeTypeTraits<4, ReturnT (*)(ParamTs...)> {};

}  // namespace llcl

#endif  // LLCL_STANDARD_SUPPORT_POINTERLIKETYPETRAITS_H