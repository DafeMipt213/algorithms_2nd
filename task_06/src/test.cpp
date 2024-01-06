#include <gtest/gtest.h>
#include "lca.hpp"

TEST(LCA, Simple) {
  AllData data;
  data.graph = {{1, 2}, {0}, {2}};
  data.n = 3;
  precompute_lca(0, data);
  ASSERT_EQ(lca(1, 2, data), 0);
}

TEST(LCA, MediumGraphFirstTest) {
  AllData data;
  data.graph = {{1, 4}, {0, 2, 3}, {1}, {1}, {0}};
  data.n = 5;
  precompute_lca(0, data);
  ASSERT_EQ(lca(2, 3, data), 1);
}

TEST(LCA, MediumGraphSecondTest) {
  AllData data;
  data.graph = {{1, 4}, {0, 2, 3}, {1}, {1}, {0}};
  data.n = 5;
  precompute_lca(0, data);
  ASSERT_EQ(lca(2, 4, data), 0);
}

TEST(LCA, BigGraphFirstTest) {
  AllData data;
  data.graph = {{1, 2}, {0, 3, 4}, {0, 6}, {1, 5}, {1}, {3}, {2, 7}, {6, 8, 9}, {7}, {7}};
  data.n = 10;
  precompute_lca(0, data);
  ASSERT_EQ(lca(5, 9, data), 0);
}

TEST(LCA, BigGraphSecondTest) {
  AllData data;
  data.graph = {{1, 2}, {0, 3, 4}, {0, 6}, {1, 5}, {1}, {3}, {2, 7}, {6, 8, 9}, {7}, {7}};
  data.n = 10;
  precompute_lca(0, data);
  ASSERT_EQ(lca(8, 9, data), 7);
}

TEST(LCA, BigGraphThirdTest) {
  AllData data;
  data.graph = {{1, 2}, {0, 3, 4}, {0, 6}, {1, 5}, {1}, {3}, {2, 7}, {6, 8, 9}, {7}, {7}};
  data.n = 10;
  precompute_lca(0, data);
  ASSERT_EQ(lca(3, 4, data), 1);
}

TEST(LCA, BigGraphTest) {
  AllData data;
  data.graph = {{1, 2}, {0, 3, 4}, {0, 6}, {1, 5}, {1}, {3}, {2, 7}, {6, 8, 9}, {7}, {7}};
  data.n = 10;
  precompute_lca(0, data);
  ASSERT_EQ(lca(1, 7, data), 0);
}