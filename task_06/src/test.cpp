#include <gtest/gtest.h>

#include "lca.hpp"

TEST(TopologySort, Simple) {
  ASSERT_EQ(LCA(BinTree({0, 1, 2, 3, 4, 5, 6, 7, 8}), 4, 8), 1);
}

TEST(TopologySort, Exceptions) {
  EXPECT_ANY_THROW(LCA(BinTree({0, 1, 2, 3, 4, 5, 6, 7, 8}), 4, 3));
}
