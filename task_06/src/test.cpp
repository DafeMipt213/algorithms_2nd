
#include <gtest/gtest.h>

#include <graph.hpp>
#include <lca.hpp>

TEST(LCA, Simple) {
  Graph<size_t> tree;
  tree.SetAdjacencyList({{1, 2}, {0}, {0}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(1, 2), 0);
}

TEST(LCA, OneElement) {
  Graph<size_t> tree;
  tree.SetAdjacencyList({{}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(0, 0), 0);
}

TEST(LCA, Middle) {
  Graph<size_t> tree;
  tree.SetAdjacencyList({{1, 2}, {3, 4}, {5}, {}, {6}, {}, {}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(6, 5), 0);
  ASSERT_EQ(lca.GetLCA(6, 3), 1);
  ASSERT_EQ(lca.GetLCA(1, 3), 1);
}

TEST(LCA, Middle2) {
  Graph<size_t> tree;
  tree.SetAdjacencyList(
      {{}, {0}, {1}, {2}, {5, 3}, {8, 6}, {7, 9}, {}, {10, 11}, {}, {}, {}});
  LCA lca(tree, 4);
  ASSERT_EQ(lca.GetLCA(7, 0), 4);
  ASSERT_EQ(lca.GetLCA(9, 8), 5);
  ASSERT_EQ(lca.GetLCA(11, 3), 4);
}

TEST(LCA, Middle3) {
  Graph<size_t> tree;
  tree.SetAdjacencyList({{1, 2, 3}, {4, 5}, {}, {}, {}, {}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(4, 5), 1);
  ASSERT_EQ(lca.GetLCA(4, 3), 0);
  ASSERT_EQ(lca.GetLCA(2, 3), 0);
}

TEST(LCA, Middle4) {
  Graph<size_t> tree;
  tree.SetAdjacencyList(
      {{1, 2, 3, 4, 5, 6, 7, 8}, {}, {}, {}, {}, {}, {}, {}, {}});
  LCA lca(tree, 0);
  ASSERT_EQ(lca.GetLCA(4, 5), 0);
  ASSERT_EQ(lca.GetLCA(4, 3), 0);
  ASSERT_EQ(lca.GetLCA(2, 3), 0);
  ASSERT_EQ(lca.GetLCA(0, 3), 0);
  ASSERT_EQ(lca.GetLCA(1, 8), 0);
}