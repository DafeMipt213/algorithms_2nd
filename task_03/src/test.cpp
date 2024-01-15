#include <gtest/gtest.h>

#include "johnson.hpp"

#define INF std::numeric_limits<int>::max()

TEST(JohnsonAlgorithm, Simple) {
  WeightGraph graph(3);
  graph.AddEdge(0, 1, 3);
  graph.AddEdge(0, 2, -4);
  std::vector<std::vector<int>> allPairsShortestPaths =
      graph.JohnsonAlgorithm();
  std::vector<std::vector<int>> expectedDistances = {
      {0, 3, -4}, {INF, 0, INF}, {INF, INF, 0}};
  ASSERT_EQ(allPairsShortestPaths, expectedDistances);
}

TEST(JohnsonAlgorithm, Medium) {
  WeightGraph graph(5);
  graph.AddEdge(0, 1, 6);
  graph.AddEdge(0, 2, 7);
  graph.AddEdge(1, 2, 8);
  graph.AddEdge(1, 3, 5);
  graph.AddEdge(1, 4, -4);
  graph.AddEdge(2, 3, -3);
  graph.AddEdge(2, 4, 9);
  graph.AddEdge(3, 0, 2);
  graph.AddEdge(4, 3, 7);
  std::vector<std::vector<int>> allPairsShortestPaths =
      graph.JohnsonAlgorithm();
  std::vector<std::vector<int>> expectedDistances = {{0, 6, 7, 4, 2},
                                                     {5, 0, 8, 3, -4},
                                                     {-1, 5, 0, -3, 1},
                                                     {2, 8, 9, 0, 4},
                                                     {9, 15, 16, 7, 0}};
  ASSERT_EQ(allPairsShortestPaths, expectedDistances);
}