
#include <gtest/gtest.h>

#include "LCA.hpp"

TEST(LCA, Simple) {
  graph g = {{1, 2}, {0}, {0}};
  lca_prepare(g, 0);
  ASSERT_EQ(lca(1, 2), 0);
}

TEST(LCA, Difiicult) {
  graph g = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1, 6, 7}, {2, 8}, {4}, {4}, {5}};
  lca_prepare(g, 0);
  ASSERT_EQ(lca(3, 7), 1);
}

TEST(LCA, Difiicult_2) {
  graph g = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1, 6, 7}, {2, 8}, {4}, {4}, {5}};
  lca_prepare(g, 0);
  ASSERT_EQ(lca(1, 8), 0);
}

TEST(LCA, Hard) {
  graph g = {{1, 14},     {0, 2, 3}, {1, 4, 5},   {1, 6, 7}, {2},
             {2},         {3, 9, 8}, {3, 10, 13}, {6},       {6},
             {7, 11, 12}, {10},      {10},        {7},       {1}};
  lca_prepare(g, 0);
  ASSERT_EQ(lca(9, 13), 3);
}

TEST(LCA, Empty) {
  graph g = {};
  lca_prepare(g, 0);
  ASSERT_ANY_THROW(lca(1, 4));
}

TEST(LCA, Only_Root) {
  graph g = {{}};
  lca_prepare(g, 0);
  ASSERT_ANY_THROW(lca(1, 4));
}