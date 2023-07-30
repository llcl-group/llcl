#ifndef LLCL_STANDARD_METAFUNCTIONS_ISPOLYMORPHIC_H
#define LLCL_STANDARD_METAFUNCTIONS_ISPOLYMORPHIC_H

#include "llcl/Standard/MetaFunctions/IntegralConstant.h"
#include "llcl/Standard/MetaFunctions/IsClass.h"
#include "llcl/Standard/MetaFunctions/Removecv.h"

namespace llcl {

namespace standard {

namespace mf {

template <class Type, bool IsClass = LLCL_IsClass<Type>::value>
struct IsPolymorphicImp {
  enum { Value = false };
};

template <class Type>
struct IsPolymorphicImp<Type, true> {
  struct IsPoly : public Type {
    IsPoly();
    virtual ~IsPoly();

    char dummy[256];
  };

  struct MaybePoly : public Type {
    MaybePoly();
    ~MaybePoly();

    char dummy[256];
  };

  enum { Value = (sizeof(IsPoly) == sizeof(MaybePoly)) };
};

}  // namespace mf

template <class Type>
struct is_polymorphic
    : integral_constant<
          bool, mf::IsPolymorphicImp<typename remove_cv<Type>::type>::Value> {};

namespace mf {

template <class Type>
struct IsPolymorphic : standard::is_polymorphic<Type>::type {};

}  // namespace mf

}  // namespace standard

}  // namespace llcl

#define LLCL_IsPolymorphic llcl::standard::mf::IsPolymorphic

#endif  // LLCL_STANDARD_METAFUNCTIONS_ISPOLYMORPHIC_H