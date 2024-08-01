#include "llcl/Standard/ADT/PointerIntPair.h"

#include <gtest/gtest.h>

#include <limits>

namespace llcl {
namespace {

TEST(PointerIntPairTest, GetSet) {
  struct S {
    int i;
  };
  S s;

  PointerIntPair<S*, 2> Pair(&s, 1U);
  EXPECT_EQ(&s, Pair.getPointer());
  EXPECT_EQ(1U, Pair.getInt());

  Pair.setInt(2);
  EXPECT_EQ(&s, Pair.getPointer());
  EXPECT_EQ(2U, Pair.getInt());

  Pair.setPointer(nullptr);
  EXPECT_EQ(nullptr, Pair.getPointer());
  EXPECT_EQ(2U, Pair.getInt());

  Pair.setPointerAndInt(&s, 3U);
  EXPECT_EQ(&s, Pair.getPointer());
  EXPECT_EQ(3U, Pair.getInt());

  // Make sure that we can perform all of our operations on enum classes.
  //
  // The concern is that enum classes are only explicitly convertible to
  // integers. This means that if we assume in PointerIntPair this, a
  // compilation error will result. This group of tests exercises the enum class
  // code to make sure that we do not run into such issues in the future.
  enum class E : unsigned {
    Case1,
    Case2,
    Case3,
  };
  PointerIntPair<S*, 2, E> Pair2(&s, E::Case1);
  EXPECT_EQ(&s, Pair2.getPointer());
  EXPECT_EQ(E::Case1, Pair2.getInt());

  Pair2.setInt(E::Case2);
  EXPECT_EQ(&s, Pair2.getPointer());
  EXPECT_EQ(E::Case2, Pair2.getInt());

  Pair2.setPointer(nullptr);
  EXPECT_EQ(nullptr, Pair2.getPointer());
  EXPECT_EQ(E::Case2, Pair2.getInt());

  Pair2.setPointerAndInt(&s, E::Case3);
  EXPECT_EQ(&s, Pair2.getPointer());
  EXPECT_EQ(E::Case3, Pair2.getInt());

  auto [Pointer2, Int2] = Pair2;
  EXPECT_EQ(Pair2.getPointer(), Pointer2);
  EXPECT_EQ(Pair2.getInt(), Int2);

  static_assert(std::is_trivially_copyable_v<PointerIntPair<S*, 2, E>>,
                "trivially copyable");
}

TEST(PointerIntPairTest, DefaultInitialize) {
  PointerIntPair<float*, 2> Pair;
  EXPECT_EQ(nullptr, Pair.getPointer());
  EXPECT_EQ(0U, Pair.getInt());
}

}  // namespace
}  // namespace llcl