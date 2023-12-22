#include <gtest/gtest.h>

#include "Johnson_alg.hpp"

TEST(Johnson_alg, Simple) {
  std::vector<edge> graph{edge(1, 2, 1), edge(0, 1, 2)};
  std::vector<std::vector<int>> result = Johnson_algorithm(graph, 3);
  const int inf = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> expected_result{
      {0, 2, 3}, {inf, 0, 1}, {inf, inf, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}

TEST(Johnson_alg, Zeros) {
  std::vector<edge> graph{edge(1, 2, 0), edge(0, 1, 0), edge(2, 0, 0)};
  std::vector<std::vector<int>> result = Johnson_algorithm(graph, 3);
  std::vector<std::vector<int>> expected_result{
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}

TEST(Johnson_alg, NegativeCycle) {
  std::vector<edge> graph{edge(1, 2, -1), edge(0, 1, -2), edge(2, 0, -3)};
  ASSERT_ANY_THROW(Johnson_algorithm(graph, 3));
}

TEST(Johnson_alg, WithPositiveCost) {
  std::vector<edge> graph{edge(0, 1, 2), edge(0, 2, 5), edge(0, 3, 7),
                          edge(1, 2, 6), edge(1, 3, 8), edge(3, 1, 3),
                          edge(3, 2, 4), edge(2, 0, 1)};
  std::vector<std::vector<int>> result = Johnson_algorithm(graph, 4);
  const int inf = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> expected_result{
      {0, 2, 5, 7}, {7, 0, 6, 8}, {1, 3, 0, 8}, {5, 3, 4, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}

TEST(Johnson_alg, WithNegativeCost) {
  std::vector<edge> graph{edge(0, 1, -2), edge(0, 2, 5), edge(0, 3, 7),
                          edge(1, 2, 6),  edge(1, 3, 8), edge(3, 1, 3),
                          edge(3, 2, -4), edge(2, 0, -1)};
  std::vector<std::vector<int>> result = Johnson_algorithm(graph, 4);
  const int inf = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> expected_result{
      {0, -2, 2, 6}, {3, 0, 4, 8}, {-1, -3, 0, 5}, {-5, -7, -4, 0}};
  for (int i = 0; i < result.size(); ++i) {
    std::vector<int> one_vertex_expected = expected_result[i];
    std::vector<int> one_vertex = result[i];
    ASSERT_EQ(one_vertex_expected, one_vertex);
  }
}
