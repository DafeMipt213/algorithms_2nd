#include "lca.hpp"
#include <gtest/gtest.h>

TEST(LCA, Simple) {
  BinaryTree tree(7);
  tree.AddEdge(1, 0);
  tree.AddEdge(2, 0);
  tree.AddEdge(3, 1);
  tree.AddEdge(4, 1);
  tree.AddEdge(5, 4);
  tree.AddEdge(6, 4);

  tree.CalculateDepths(0, 0); 
  tree.InitSparseTable();

  int u = 5;
  int v = 6;
  ASSERT_EQ(tree.findLCA(u, v), 4);
}