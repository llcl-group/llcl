#ifndef LLCL_STANDARD_METAFUNCTIONS_VOIDTYPE_H
#define LLCL_STANDARD_METAFUNCTIONS_VOIDTYPE_H

namespace llcl {

namespace standard {

namespace mf {

template <class T1 = void, class T2 = void, class T3 = void, class T4 = void,
          class T5 = void, class T6 = void, class T7 = void, class T8 = void,
          class T9 = void, class T10 = void, class T11 = void, class T12 = void,
          class T13 = void, class T14 = void>
struct VoidType {
  using type = void;
};

template <class T1>
struct VoidType1 {
  using type = void;
};

template <class T1, class T2>
struct VoidType2 {
  using type = void;
};

}  // namespace mf

}  // namespace standard

}  // namespace llcl

#define LLCL_VOIDTYPE(ARG) typename llcl::standard::mf::VoidType1<ARG>::type
#define LLCL_VOIDTYPE2(ARG1, ARG2) \
  typename llcl::standard::mf::VoidType2<ARG1, ARG2>::type
#define LLCL_VOIDTYPES(...) \
  typename llcl::standard::mf::VoidType<__VA_ARGS__>::type

#endif  // LLCL_STANDARD_METAFUNCTIONS_VOIDTYPE_H