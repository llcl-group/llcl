#include "llcl/Standard/MetaFunctions/IsPolymorphic.h"

#include <gtest/gtest.h>

namespace llcl {
namespace {

enum Enum {};

struct Struct {};

union Union {};

class Base {
  int* p;
};

class Derived : public Base {};

class DerivedPoly : public Base {
  virtual ~DerivedPoly();
};

class DerivedPolyThrowSpec : public Base {
  virtual ~DerivedPolyThrowSpec();
};

class Poly {
  virtual ~Poly();
};

class DerivedFromPoly : public Poly {
  ~DerivedFromPoly();
};

class DerivedFromPolyThrowSpec : public Poly {
  ~DerivedFromPolyThrowSpec();
};

class PolyThrowSpec {
  virtual ~PolyThrowSpec();
};

class DerivedFromPolyThrowSpec2 : public PolyThrowSpec {
  ~DerivedFromPolyThrowSpec2();
};

class Base1 : public virtual Base {};

class Base2 : public virtual Base {};

class VirtuallyDerived : public Base1, public Base2 {};

class PolyVirtuallyDerived : public Base1, public Base2 {
  virtual ~PolyVirtuallyDerived();
};

class Poly1 : public virtual Poly {
  ~Poly1();
};

class Poly2 : public virtual Poly {
  ~Poly2();
};

class VirtuallyDerivedFromPoly : public Poly1, public Poly2 {
  ~VirtuallyDerivedFromPoly();
};

class VirtuallyDerivedMixed1 : public Base1, public Poly2 {
  ~VirtuallyDerivedMixed1();
};

class VirtuallyDerivedMixed2 : public Poly1, public Base2 {
  ~VirtuallyDerivedMixed2();
};

class Multi1 : public Base {};

class Multi2 : public Base {};

class MultiplyDerived : public Multi1, public Multi2 {};

struct MyStruct {
  void nonvirtualMethod();
};
struct MyDerivedStruct : public MyStruct {};

class MyClass {
 public:
  MyClass();
  virtual ~MyClass();  // makes 'MyClass' polymorphic
};

class MyDerivedClass : public MyClass {
 public:
  MyDerivedClass();
  virtual ~MyDerivedClass();
};

TEST(IsPolymorphicTest, Basic) {
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyStruct>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyStruct*>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyDerivedStruct&>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyDerivedStruct*>::value);

  EXPECT_TRUE(llcl::standard::is_polymorphic<MyClass>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<const MyClass&>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyClass*>::value);
  EXPECT_TRUE(llcl::standard::is_polymorphic<MyDerivedClass>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyDerivedClass&>::value);
  EXPECT_FALSE(llcl::standard::is_polymorphic<MyDerivedClass*>::value);
}

}  // namespace
}  // namespace llcl