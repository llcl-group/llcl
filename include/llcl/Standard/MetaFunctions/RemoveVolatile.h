#ifndef LLCL_STANDARD_METAFUNCTIONS_REMOVEVOLATILE_H
#define LLCL_STANDARD_METAFUNCTIONS_REMOVEVOLATILE_H

namespace llcl {

namespace standard {

template <class Type>
struct remove_volatile {
  using type = Type;
};

template <class Type>
struct remove_volatile<Type volatile> {
  using type = Type;
};

}  // namespace standard

}  // namespace llcl

#endif  // LLCL_STANDARD_METAFUNCTIONS_REMOVEVOLATILE_H