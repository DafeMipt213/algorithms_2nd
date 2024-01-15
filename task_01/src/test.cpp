
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, SimpleGraph) {
  Graph graph(6);
  graph.FillGraph({{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}});
  std::vector<int> result{5, 4, 2, 3, 1, 0};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, CycleGraph) {
  Graph graph(3);
  graph.FillGraph({{1, 2}, {0, 2}, {0, 0}});
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, WikiGraph) {
  Graph graph(12);
  graph.FillGraph({{3, 8},
                   {3, 10},
                   {5, 11},
                   {7, 11},
                   {7, 8},
                   {8, 9},
                   {11, 2},
                   {11, 9},
                   {11, 10}});
  std::vector<int> result{
      7,  5, 11, 3,
      10, 8, 9,  2};  // wiki version(without {7, 5, 11, 3, 8, 2, 9, 10};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, EmptyGraph) {
  Graph graph(0);
  graph.FillGraph({});
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, TwoPartGraph) {
  Graph graph(7);
  graph.FillGraph({{1, 2}, {2, 3}, {4, 5}, {5, 6}});
  std::vector<int> result{4, 5, 6, 1, 2, 3};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, OneVerticleGraph) {
  Graph graph(1);
  graph.AddVerticle(0);
  std::vector<int> result{0};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, MultipleVerticesNoEdges) {
  Graph graph(5);
  for (int i = 0; i < 5; ++i) {
    graph.AddVerticle(i);
  }
  std::vector<int> result{4, 3, 2, 1, 0};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, MultipleVerticesWithEdges) {
  Graph graph(4);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  std::vector<int> result{0, 1, 2, 3};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, MultipleVerticesWithMultipleEdges) {
  Graph graph(5);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 4);
  std::vector<int> result{0, 2, 4, 1, 3};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, MultipleVerticesWithCycle) {
  Graph graph(3);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 0);
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, TwoVerticesOneEdgeReversed) {
  Graph graph(2);
  graph.AddEdge(1, 0);
  std::vector<int> result{1, 0};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, MultipleVerticesMultipleEdgesNoCycle) {
  Graph graph(4);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(0, 3);
  std::vector<int> result{0, 3, 1, 2};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, DisconnectedGraph) {
  Graph graph(4);
  graph.AddEdge(0, 1);
  graph.AddVerticle(2);
  graph.AddVerticle(3);
  std::vector<int> result{3, 2, 0, 1};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, GraphWithMultipleEdgesBetweenVertices) {
  Graph graph(3);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  std::vector<int> result{0, 1, 2};
  ASSERT_EQ(graph.TopologicalSort(), result);
}

TEST(TopologySort, PythonTest) {
  Graph graph(9);
  graph.FillGraph({{2, 4},
                   {1, 2},
                   {7, 1},
                   {6, 2},
                   {0, 0},
                   {1, 8},
                   {5, 7},
                   {4, 2},
                   {8, 3},
                   {5, 6},
                   {4, 8},
                   {6, 0},
                   {1, 0},
                   {6, 3},
                   {1, 3}});
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologicalSort(), result);
}