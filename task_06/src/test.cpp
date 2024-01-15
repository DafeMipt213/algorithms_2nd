#include <gtest/gtest.h>

#include "lca.hpp"

TEST(LCA, Simple) {
  std::vector<std::vector<int>> adj = {{1, 2},    {0, 3, 4}, {0, 5}, {1},
                                       {1, 6, 7}, {2},       {4},    {4}};
  LCA lca(adj);

  ASSERT_EQ(lca.FindLCA(6, 7), 4);
  ASSERT_EQ(lca.FindLCA(6, 5), 0);
  ASSERT_EQ(lca.FindLCA(2, 5), 2);
  ASSERT_EQ(lca.FindLCA(3, 5), 0);
}
