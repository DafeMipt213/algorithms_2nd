
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph<std::string> graph;
  graph.AddEdge("a", "b");
  graph.AddEdge("a", "c");
  graph.AddEdge("a", "d");
  graph.AddEdge("a", "e");
  graph.AddEdge("b", "d");
  graph.AddEdge("c", "d");
  graph.AddEdge("c", "e");
  graph.AddEdge("d", "e");

  std::vector<std::string> result{"a", "c", "b", "d", "e"};

  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, SimpleCycled) {
  Graph<std::string> graph;
  graph.AddEdge("a", "b");
  graph.AddEdge("b", "a");
  graph.AddEdge("a", "c");
  graph.AddEdge("a", "d");
  graph.AddEdge("a", "e");
  graph.AddEdge("b", "d");
  graph.AddEdge("c", "d");
  graph.AddEdge("c", "e");
  graph.AddEdge("d", "e");

  std::vector<std::string> result = {};

  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, SimpleGraph) {
  Graph<int> graph;
  graph.AddEdge(5, 2);
  graph.AddEdge(5, 0);
  graph.AddEdge(4, 0);
  graph.AddEdge(4, 1);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 1);
  std::vector<int> result{5, 4, 2, 3, 1, 0};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithCycleInOneVertex) {
  Graph<int> graph;
  graph.AddEdge(0, 0);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 2);
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithTwoComponents) {
  Graph<int> graph;
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(4, 5);
  graph.AddEdge(5, 6);
  graph.AddEdge(5, 7);
  std::vector<int> result{4, 5, 7, 6, 0, 1, 3, 2};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithThreeComponents) {
  Graph<int> graph;
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(4, 5);
  graph.AddEdge(5, 6);
  graph.AddEdge(5, 7);
  graph.AddEdge(8, 9);
  graph.AddEdge(9, 10);
  graph.AddEdge(9, 11);
  std::vector<int> result{8, 9, 11, 10, 4, 5, 7, 6, 0, 1, 3, 2};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, EmptyGraph) {
  Graph graph;
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologySort(), result);
}