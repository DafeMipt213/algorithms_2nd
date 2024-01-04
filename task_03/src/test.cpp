#include <gtest/gtest.h>

#include <iostream>

#include "johnson.hpp"

TEST(JohnsonAlgorithm, GraphFromHabr) {
  Graph graph;
  graph.AddEdge(1, 2, -2);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(1, 4, 5);
  graph.AddEdge(2, 4, 6);
  graph.AddEdge(2, 3, 8);
  graph.AddEdge(3, 4, -4);
  graph.AddEdge(3, 2, 3);
  graph.AddEdge(4, 1, -1);

  std::map<int, std::map<int, long long>> result = {
      {1, {{1, 0}, {2, -2}, {3, 6}, {4, 2}}},
      {2, {{1, 3}, {2, 0}, {3, 8}, {4, 4}}},
      {3, {{1, -5}, {2, -7}, {3, 0}, {4, -4}}},
      {4, {{1, -1}, {2, -3}, {3, 5}, {4, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}
