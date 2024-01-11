#include <gtest/gtest.h>

#include "Johnson_alg.hpp"

TEST(Johnson_algorithm, Simple) {
  std::vector<Edge> graph{Edge(1, 2, 1), Edge(0, 1, 2)};
  std::vector<std::vector<int>> result = FindShortestPathes(graph, 3);
  const int inf = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> expected_result{
      {0, 2, 3}, {inf, 0, 1}, {inf, inf, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}

TEST(Johnson_algorithm, Zeros) {
  std::vector<Edge> graph{Edge(1, 2, 0), Edge(0, 1, 0), Edge(2, 0, 0)};
  std::vector<std::vector<int>> result = FindShortestPathes(graph, 3);
  std::vector<std::vector<int>> expected_result{
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}

TEST(Johnson_algorithm, NegativeCycle) {
  std::vector<Edge> graph{Edge(1, 2, -1), Edge(0, 1, -2), Edge(2, 0, -3)};
  ASSERT_ANY_THROW(FindShortestPathes(graph, 3));
}

TEST(Johnson_algorithm, WithPositiveCost) {
  std::vector<Edge> graph{Edge(0, 1, 2), Edge(0, 2, 5), Edge(0, 3, 7),
                          Edge(1, 2, 6), Edge(1, 3, 8), Edge(3, 1, 3),
                          Edge(3, 2, 4), Edge(2, 0, 1)};
  std::vector<std::vector<int>> result = FindShortestPathes(graph, 4);
  const int inf = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> expected_result{
      {0, 2, 5, 7}, {7, 0, 6, 8}, {1, 3, 0, 8}, {5, 3, 4, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}

TEST(Johnson_algorithm, WithNegativeCost) {
  std::vector<Edge> graph{Edge(0, 1, -2), Edge(0, 2, 5), Edge(0, 3, 7),
                          Edge(1, 2, 6),  Edge(1, 3, 8), Edge(3, 1, 3),
                          Edge(3, 2, -4), Edge(2, 0, -1)};
  std::vector<std::vector<int>> result = FindShortestPathes(graph, 4);
  const int inf = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> expected_result{
      {0, -2, 2, 6}, {3, 0, 4, 8}, {-1, -3, 0, 5}, {-5, -7, -4, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}
