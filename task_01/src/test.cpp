
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph G;
  G.Add(1, 0);
  G.Add(2, 0);
  G.Add(3, 1);
  G.Add(4, 1);
  G.Add(4, 3);
  G.Add(2, 3);
  auto vec = TopologySort(G);
  std::vector<int> vec2 = {2, 4, 3, 1, 0};
  ASSERT_TRUE(std::equal(vec.begin(), vec.end(), vec2.begin()));
}

TEST(TopologySort, Exceptions) {
  Graph G;
  G.Add(1, 0);
  G.Add(0, 2);
  G.Add(2, 1);
  ASSERT_ANY_THROW(TopologySort(G));
}
