#ifndef LLCL_STANDARD_METAFUNCTIONS_REMOVECV_H
#define LLCL_STANDARD_METAFUNCTIONS_REMOVECV_H

#include "llcl/Standard/MetaFunctions/RemoveConst.h"
#include "llcl/Standard/MetaFunctions/RemoveVolatile.h"

namespace llcl {

namespace standard {

template <class Type>
struct remove_cv {
  using type =
      typename remove_const<typename remove_volatile<Type>::type>::type;
};

}  // namespace standard

}  // namespace llcl

#endif  // LLCL_STANDARD_METAFUNCTIONS_REMOVECV_H