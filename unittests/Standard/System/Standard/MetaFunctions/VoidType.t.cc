#include "llcl/Standard/MetaFunctions/VoidType.h"

#include <gtest/gtest.h>

namespace llcl {
namespace {

class Incomplete;

enum MyEnum { E0, E1 };

struct MyStruct {
  int d_x;
};

union MyUnion {
  int d_x;
};

template <class Type>
inline bool IsVoidPointer(const Type&) {
  return false;
}

inline bool IsVoidPointer(void*) { return true; }

#define LLCL_VOID_TYPE_TEST(...) \
  ASSERT_TRUE(IsVoidPointer((standard::mf::VoidType<__VA_ARGS__>::type*)0))

TEST(VoidTypeTest, Type14) {
  LLCL_VOID_TYPE_TEST();
  LLCL_VOID_TYPE_TEST(signed long long);
  LLCL_VOID_TYPE_TEST(signed long long,
                      signed long long);  // test for duplicates
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*, MyUnion*);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*, MyUnion*,
                      Incomplete*);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*, MyUnion*,
                      Incomplete*, signed long long&);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*, MyUnion*,
                      Incomplete*, signed long long&, MyEnum&);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*, MyUnion*,
                      Incomplete*, signed long long&, MyEnum&, MyStruct&);
  LLCL_VOID_TYPE_TEST(signed long long, MyEnum, MyStruct, MyUnion, Incomplete,
                      signed long long*, MyEnum*, MyStruct*, MyUnion*,
                      Incomplete*, signed long long&, MyEnum&, MyStruct&,
                      MyUnion&);
}

}  // namespace
}  // namespace llcl