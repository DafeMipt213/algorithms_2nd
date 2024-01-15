#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  int vertices = 4;
  Graph graph(vertices);

  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 3);

  std::vector<int> result = graph.TopologicalSort();
  ASSERT_EQ(result[0], 0);
  ASSERT_EQ(result[1], 2);
  ASSERT_EQ(result[2], 1);
  ASSERT_EQ(result[3], 3);
}

TEST(TopologySort, SimpleCycle) {
  int vertices = 4;
  Graph graph(vertices);

  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(3, 0);

  ASSERT_ANY_THROW(graph.TopologicalSort());
}

TEST(TopologySort, Medium) {
  int vertices = 6;
  Graph graph(vertices);

  graph.AddEdge(2, 3);
  graph.AddEdge(3, 1);
  graph.AddEdge(4, 0);
  graph.AddEdge(4, 1);
  graph.AddEdge(5, 2);
  graph.AddEdge(5, 0);

  std::vector<int> result = graph.TopologicalSort();

  ASSERT_EQ(result[0], 5);
  ASSERT_EQ(result[1], 4);
  ASSERT_EQ(result[2], 2);
  ASSERT_EQ(result[3], 3);
  ASSERT_EQ(result[4], 1);
  ASSERT_EQ(result[5], 0);
}

TEST(TopologySort, Hard) {
  int vertices = 9;
  Graph graph(vertices);

  graph.AddEdge(3, 1);
  graph.AddEdge(3, 6);
  graph.AddEdge(1, 6);
  graph.AddEdge(1, 0);
  graph.AddEdge(1, 4);
  graph.AddEdge(0, 2);
  graph.AddEdge(6, 4);
  graph.AddEdge(6, 8);
  graph.AddEdge(8, 4);
  graph.AddEdge(8, 7);
  graph.AddEdge(4, 2);
  graph.AddEdge(2, 7);
  graph.AddEdge(2, 5);
  graph.AddEdge(7, 5);

  std::vector<int> result = graph.TopologicalSort();

  ASSERT_EQ(result[0], 3);
  ASSERT_EQ(result[1], 1);
  ASSERT_EQ(result[2], 6);
  ASSERT_EQ(result[3], 8);
  ASSERT_EQ(result[4], 4);
  ASSERT_EQ(result[5], 0);
  ASSERT_EQ(result[6], 2);
  ASSERT_EQ(result[7], 7);
  ASSERT_EQ(result[8], 5);
}