#include <gtest/gtest.h>

#include "connected_graph.hpp"

TEST(SearchBridgesAndCutpoints, Simple) {
  Graph graph({{1}, {0}});
  ASSERT_EQ(graph.FindCriticalEdges(), std::vector<Edge>{Edge(0, 1)});
  std::vector<int> criticalRouters = {};
  ASSERT_EQ(graph.FindCriticalRouters(), criticalRouters);
}