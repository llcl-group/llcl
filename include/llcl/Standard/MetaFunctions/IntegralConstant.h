#ifndef LLCL_STANDARD_METAFUNCTIONS_INTEGRALCONSTANT_H
#define LLCL_STANDARD_METAFUNCTIONS_INTEGRALCONSTANT_H

namespace llcl {

namespace standard {

namespace mf {

template <int>
struct MetaInt;

}  // namespace mf

template <class Type, Type Value>
struct integral_constant {
  using value_type = Type;
  using type = integral_constant<Type, Value>;
  static constexpr const Type value = Value;
  constexpr operator value_type() const noexcept { return value; }
};

template <bool Value>
struct integral_constant<bool, Value> {
  using value_type = bool;
  using type = integral_constant;
  static constexpr const bool value = Value;
  constexpr operator value_type() const noexcept { return value; }
};

using false_type = integral_constant<bool, false>;

using true_type = integral_constant<bool, true>;

}  // namespace standard

}  // namespace llcl

#endif  // LLCL_STANDARD_METAFUNCTIONS_INTEGRALCONSTANT_H