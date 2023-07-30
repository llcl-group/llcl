#ifndef LLCL_STANDARD_METAFUNCTIONS_REMOVECONST_H
#define LLCL_STANDARD_METAFUNCTIONS_REMOVECONST_H

namespace llcl {

namespace standard {

template <class Type>
struct remove_const {
  using type = Type;
};

template <class Type>
struct remove_const<Type const> {
  using type = Type;
};

}  // namespace standard

}  // namespace llcl

#endif  // LLCL_STANDARD_METAFUNCTIONS_REMOVECONST_H