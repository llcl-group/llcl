#ifndef LLCL_STANDARD_METAFUNCTIONS_ISCLASS_H
#define LLCL_STANDARD_METAFUNCTIONS_ISCLASS_H

#include "llcl/Standard/MetaFunctions/IntegralConstant.h"
#include "llcl/Standard/MetaFunctions/VoidType.h"

namespace llcl {

namespace standard {

namespace mf {

template <class Type, class = void>
struct IsClassImp : standard::false_type {};

template <class Type>
struct IsClassImp<Type, LLCL_VOIDTYPE(int Type::*)> : standard::true_type {};

}  // namespace mf

template <class Type>
struct is_class : mf::IsClassImp<Type>::type {};

template <class Type>
constexpr bool is_class_v = is_class<Type>::value;

namespace mf {

template <class Type>
struct IsClass : standard::is_class<Type>::type {};

}  // namespace mf

}  // namespace standard

}  // namespace llcl

#define LLCL_IsClass llcl::standard::mf::IsClass

#endif  // LLCL_STANDARD_METAFUNCTIONS_ISCLASS_H