#include <gtest/gtest.h>

#include "llcl/Standard/ADT/ilist_base.h"

namespace llcl {
namespace {

// Test fixture.
template <typename T>
class IListBaseTest : public ::testing::Test {};

class Parent;

// Test variants with the same test.
typedef ::testing::Types<ilist_base<false, void>, ilist_base<true, void>,
                         ilist_base<false, Parent*>, ilist_base<true, Parent*>>
    IListBaseTestTypes;
TYPED_TEST_SUITE(IListBaseTest, IListBaseTestTypes, );

TYPED_TEST(IListBaseTest, insertBeforeImpl) {
  typedef TypeParam list_base_type;
  typedef typename list_base_type::node_base_type node_base_type;

  node_base_type S, A, B;

  // [S] <-> [S]
  S.setPrev(&S);
  S.setNext(&S);

  // [S] <-> A <-> [S]
  list_base_type::insertBeforeImpl(S, A);
  EXPECT_EQ(&A, S.getPrev());
  EXPECT_EQ(&S, A.getPrev());
  EXPECT_EQ(&A, S.getNext());
  EXPECT_EQ(&S, A.getNext());

  // [S] <-> A <-> B <-> [S]
  list_base_type::insertBeforeImpl(S, B);
  EXPECT_EQ(&B, S.getPrev());
  EXPECT_EQ(&A, B.getPrev());
  EXPECT_EQ(&S, A.getPrev());
  EXPECT_EQ(&A, S.getNext());
  EXPECT_EQ(&B, A.getNext());
  EXPECT_EQ(&S, B.getNext());
}

}  // namespace
}  // namespace llcl