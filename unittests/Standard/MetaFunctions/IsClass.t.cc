#include "llcl/Standard/MetaFunctions/IsClass.h"

#include <gtest/gtest.h>

namespace llcl {
namespace {

enum EnumTestType {};

struct StructTestType {};

union UnionTestType {};

class BaseClassTestType {};

class DerivedClassTestType : public BaseClassTestType {};

typedef int (StructTestType::*MethodPtrTestType)();

typedef void (*FunctionPtrTestType)();

typedef int StructTestType::*PMD;

struct Incomplete;

class MyClass {};

TEST(IsClassTest, Basic) {
  EXPECT_FALSE(LLCL_IsClass<int>::value);
  EXPECT_TRUE(LLCL_IsClass<MyClass>::value);
}

TEST(IsClassTest, CV) {
  EXPECT_FALSE(LLCL_IsClass<int(int)>::value);
  EXPECT_FALSE(LLCL_IsClass<const int(int)>::value);
  EXPECT_FALSE(LLCL_IsClass<volatile int(int)>::value);
  EXPECT_FALSE(LLCL_IsClass<const volatile int(int)>::value);
  EXPECT_TRUE(LLCL_IsClass<StructTestType>::value);
  EXPECT_TRUE(LLCL_IsClass<StructTestType const>::value);
  EXPECT_TRUE(LLCL_IsClass<StructTestType volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<StructTestType const volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<UnionTestType>::value);
  EXPECT_TRUE(LLCL_IsClass<UnionTestType const>::value);
  EXPECT_TRUE(LLCL_IsClass<UnionTestType volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<UnionTestType const volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<Incomplete>::value);
  EXPECT_TRUE(LLCL_IsClass<Incomplete const>::value);
  EXPECT_TRUE(LLCL_IsClass<Incomplete volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<Incomplete const volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<BaseClassTestType>::value);
  EXPECT_TRUE(LLCL_IsClass<BaseClassTestType const>::value);
  EXPECT_TRUE(LLCL_IsClass<BaseClassTestType volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<BaseClassTestType const volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<DerivedClassTestType>::value);
  EXPECT_TRUE(LLCL_IsClass<DerivedClassTestType const>::value);
  EXPECT_TRUE(LLCL_IsClass<DerivedClassTestType volatile>::value);
  EXPECT_TRUE(LLCL_IsClass<DerivedClassTestType const volatile>::value);
  EXPECT_FALSE(LLCL_IsClass<StructTestType&>::value);
  EXPECT_FALSE(LLCL_IsClass<StructTestType const&>::value);
  EXPECT_FALSE(LLCL_IsClass<StructTestType volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<StructTestType const volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<UnionTestType&>::value);
  EXPECT_FALSE(LLCL_IsClass<UnionTestType const&>::value);
  EXPECT_FALSE(LLCL_IsClass<UnionTestType volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<UnionTestType const volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<Incomplete&>::value);
  EXPECT_FALSE(LLCL_IsClass<Incomplete const&>::value);
  EXPECT_FALSE(LLCL_IsClass<Incomplete volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<Incomplete const volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<BaseClassTestType&>::value);
  EXPECT_FALSE(LLCL_IsClass<BaseClassTestType const&>::value);
  EXPECT_FALSE(LLCL_IsClass<BaseClassTestType volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<BaseClassTestType const volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<DerivedClassTestType&>::value);
  EXPECT_FALSE(LLCL_IsClass<DerivedClassTestType const&>::value);
  EXPECT_FALSE(LLCL_IsClass<DerivedClassTestType volatile&>::value);
  EXPECT_FALSE(LLCL_IsClass<DerivedClassTestType const volatile&>::value);
}

}  // namespace
}  // namespace llcl