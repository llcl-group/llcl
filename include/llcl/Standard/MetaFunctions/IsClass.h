#ifndef LLCL_STANDARD_METAFUNCTIONS_ISCLASS_H
#define LLCL_STANDARD_METAFUNCTIONS_ISCLASS_H

#include "llcl/Standard/MetaFunctions/IntegralConstant.h"

namespace llcl {

namespace standard {

namespace mf {

template <class Type, class = void>
struct IsClassImp : standard::false_type {};

}  // namespace mf

}  // namespace standard

}  // namespace llcl

#endif  // LLCL_STANDARD_METAFUNCTIONS_ISCLASS_H