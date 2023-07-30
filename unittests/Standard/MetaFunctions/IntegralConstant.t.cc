#include "llcl/Standard/MetaFunctions/IntegralConstant.h"

#include <gtest/gtest.h>

namespace llcl {
namespace {

struct DummyType {
  int d_x;
};

template <class A, class B>
struct IsSameType {
  enum { VALUE = false };
};

template <class A>
struct IsSameType<A, A> {
  enum { VALUE = true };
};

template <class T>
inline bool IsConst(T&) {
  return false;
}
template <class T>
inline bool IsConst(const T&) {
  return true;
}

template <class Type>
int DoSomethingImp(Type* t, standard::true_type) {
  (void)t;
  return 11;
}

template <class Type>
int DoSomethingImp(Type* t, standard::false_type) {
  (void)t;
  return 55;
}

template <bool IsSlow, class Type>
int DoSomething(Type* t) {
  return DoSomethingImp(t, standard::integral_constant<bool, IsSlow>());
}

TEST(IntegralConstantTest, Full) {
  int i;
  int r = DoSomething<false>(&i);  // select fast version for int
  EXPECT_EQ(55, r);

  double m;
  r = DoSomething<true>(&m);  // select slow version for double
  EXPECT_EQ(11, r);
}

}  // namespace

}  // namespace llcl