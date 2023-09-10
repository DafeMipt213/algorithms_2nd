
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph graph {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  Vertexes vertexes {5, 4, 2, 3, 1, 0};
  ASSERT_EQ(TopologySort(graph), vertexes);
}


