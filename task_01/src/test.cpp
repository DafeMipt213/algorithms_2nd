
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph graph{{1}, {}};
  Vertexes vertexes{0, 1};
  ASSERT_EQ(TopologySort(graph), vertexes);
}

TEST(TopologySort, Main) {
  Graph graph{{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  Vertexes vertexes{5, 4, 2, 3, 1, 0};
  ASSERT_EQ(TopologySort(graph), vertexes);
}

TEST(TopologySort, Continuing) {
  Graph graph{{2}, {0, 4, 6}, {7, 5}, {1, 6}, {2}, {}, {4, 8}, {5}, {4, 7}};
  Vertexes vertexes{3, 1, 6, 8, 4, 0, 2, 7, 5};
  ASSERT_EQ(TopologySort(graph), vertexes);
}

TEST(TopologySort, Additional) {
  Graph graph{{}, {0, 3, 4}, {0}, {2, 4}, {2}};
  Vertexes vertexes{1, 3, 4, 2, 0};
  ASSERT_EQ(TopologySort(graph), vertexes);
}
