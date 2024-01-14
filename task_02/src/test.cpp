#include <gtest/gtest.h>

#include "task2.hpp"

TEST(TopologySort, Simple) {
  Graph G;
  G.Add(2, 1);
  G.Add(3, 2);
  G.Add(1, 3);
  G.Add(4, 3);
  G.Add(5, 4);
  G.Add(6, 5);
  G.Add(4, 6);
  std::vector<std::pair<int, int>> b;
  std::vector<int> c;
  ASSERT_EQ(1, 1);  // Stack []
}
