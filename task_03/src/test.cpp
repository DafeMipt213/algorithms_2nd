
#include <gtest/gtest.h>

#include <limits>
#include <vector>

#include "johnson.hpp"

TEST(FordBellman, SimpleDistance) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, 2, 100}, {2, 0, 1}, {100, 1, 0}});
  std::vector<long long> distances;
  FordBellman(graph, 0, distances);
  ASSERT_EQ(distances, (std::vector<long long>{0, 2, 3}));

  std::vector<long long> distances1;
  FordBellman(graph, 1, distances1);
  ASSERT_EQ(distances1, (std::vector<long long>{2, 0, 1}));
}

TEST(FordBellman, SimpleDistanceNegativeWeights) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, -1, 0}, {0, 0, -3}, {0, 0, 0}});
  std::vector<long long> distances;
  FordBellman(graph, 0, distances);
  ASSERT_EQ(distances, (std::vector<long long>{0, -1, -4}));
}

TEST(FordBellman, MediumDistance) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix(
      {{0, 6, 14, 11}, {7, 0, 9, 8}, {7, 0, 0, 10}, {15, 8, 7, 0}});
  std::vector<long long> distances;
  FordBellman(graph, 0, distances);
  ASSERT_EQ(distances, (std::vector<long long>({0, 6, 14, 11})));
}

TEST(FordBellman, BigGraphDistance) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, 8, 14, 6, 5, 0},
                            {5, 0, 13, 9, 11, 18},
                            {15, 1, 0, 5, 13, 18},
                            {7, 12, 1, 0, 4, 6},
                            {6, 1, 19, 14, 0, 10},
                            {17, 3, 16, 8, 6, 0}});
  std::vector<long long> distances;
  FordBellman(graph, 5, distances);
  ASSERT_EQ(distances, (std::vector<long long>{8, 3, 9, 8, 6, 0}));
}

TEST(FordBellman, SimpleNotNegativeCycle) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, 2, 100}, {2, 0, 1}, {100, 1, 0}});
  std::vector<long long> distances;
  ASSERT_EQ(FordBellman(graph, 0, distances), true);
}

TEST(FordBellman, SimpleNegativeCycle) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, -1, -1}, {-1, 0, -1}, {-1, 1, -1}});
  std::vector<long long> distances;
  ASSERT_EQ(FordBellman(graph, 0, distances), false);
}

TEST(Johnson, Simple) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, 2, 100}, {2, 0, 1}, {100, 1, 0}});
  ASSERT_EQ(Johnson(graph), (std::vector<std::vector<long long>>{
                                {0, 2, 3}, {2, 0, 1}, {3, 1, 0}}));
}

TEST(Johnson, NegativeCycle) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, -1, -1}, {-1, 0, -1}, {-1, 1, -1}});
  ASSERT_ANY_THROW(Johnson(graph));
}

TEST(Johnson, NegativeWeights) {
  Graph<VertexWeighted> graph;
  graph.SetAdjacencyMatrix({{0, -1, 0}, {0, 0, -3}, {0, 0, 0}});
  long long INF = std::numeric_limits<long long>::max();
  ASSERT_EQ(Johnson(graph),
            (std::vector<std::vector<long long>>{
                {0, -1, -4}, {INF + 1, 0, -3}, {INF + 4, INF + 3, 0}}));
}