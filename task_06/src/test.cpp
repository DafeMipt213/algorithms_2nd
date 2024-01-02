
#include <gtest/gtest.h>

#include <graph.hpp>
#include <lca.hpp>

TEST(LCA, Simple) {
  Graph tree({{1, 2}, {0}, {0}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(1, 2), 0);
}

TEST(LCA, Middle) {
  Graph tree({{1, 2}, {3, 4}, {5}, {}, {6}, {}, {}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(6, 5), 0);
  ASSERT_EQ(lca.GetLCA(6, 3), 1);
  ASSERT_EQ(lca.GetLCA(1, 3), 1);
}

TEST(LCA, Middle2) {
  Graph tree(
      {{}, {0}, {1}, {2}, {5, 3}, {8, 6}, {7, 9}, {}, {10, 11}, {}, {}, {}});
  LCA lca(tree, 4);
  ASSERT_EQ(lca.GetLCA(7, 0), 4);
  ASSERT_EQ(lca.GetLCA(9, 8), 5);
  ASSERT_EQ(lca.GetLCA(11, 3), 4);
}