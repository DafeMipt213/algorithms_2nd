#include <gtest/gtest.h>

#include "dijkstra.hpp"

#define INF std::numeric_limits<int>::max()

TEST(DijkstraAlgorithm, Simple) {
  WeightGraph graph(3);
  graph.AddEdge(0, 1, 3);
  graph.AddEdge(0, 2, 4);
  std::vector<int> expectedDistances = {0, 3, 4};
  ASSERT_EQ(graph.DijkstraAlgorithm(0), expectedDistances);
  expectedDistances = {INF, 0, INF};
  ASSERT_EQ(graph.DijkstraAlgorithm(1), expectedDistances);
  expectedDistances = {INF, INF, 0};
  ASSERT_EQ(graph.DijkstraAlgorithm(2), expectedDistances);
}

TEST(DijkstraAlgorithm, Medium) {
  WeightGraph graph(5);
  graph.AddEdge(0, 1, 6);
  graph.AddEdge(0, 2, 7);
  graph.AddEdge(1, 2, 8);
  graph.AddEdge(1, 3, 5);
  graph.AddEdge(1, 4, 4);
  graph.AddEdge(2, 3, 3);
  graph.AddEdge(2, 4, 9);
  graph.AddEdge(3, 0, 2);
  graph.AddEdge(4, 3, 7);
  std::vector<int> expectedDistances = {0, 6, 7, 10, 10};
  ASSERT_EQ(graph.DijkstraAlgorithm(0), expectedDistances);
  expectedDistances = {7, 0, 8, 5, 4};
  ASSERT_EQ(graph.DijkstraAlgorithm(1), expectedDistances);
  expectedDistances = {5, 11, 0, 3, 9};
  ASSERT_EQ(graph.DijkstraAlgorithm(2), expectedDistances);
  expectedDistances = {2, 8, 9, 0, 12};
  ASSERT_EQ(graph.DijkstraAlgorithm(3), expectedDistances);
  expectedDistances = {9, 15, 16, 7, 0};
  ASSERT_EQ(graph.DijkstraAlgorithm(4), expectedDistances);
}
