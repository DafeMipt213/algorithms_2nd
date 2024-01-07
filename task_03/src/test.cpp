#include <gtest/gtest.h>
#include "Jonsons_algorithm.hpp"

TEST(Jonson, Simple) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector <struct edge> edges;
  edges.push_back(edge(1, 2, 2));
  edges.push_back(edge(2, 3, -15));
  edges.push_back(edge(1, 3, -10));
  Johnson(3, graph, edges);

  std::vector<std::vector<long long>> result{{0, 0, 0, 0}, {0, 0, 2, -13}, {0, LLONG_MAX, 0, -15}, {0, LLONG_MAX, LLONG_MAX, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, Cycle) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector <struct edge> edges;
  edges.push_back(edge(1, 2, 1));
  edges.push_back(edge(2, 3, -1));
  edges.push_back(edge(3, 1, 2));
  Johnson(3, graph, edges);

  std::vector<std::vector<long long>> result{{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, -1}, {0, 2, 3, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, Empty) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(0, std::vector<long long>(0, 0));
  std::vector <struct edge> edges;
  Johnson(0, graph, edges);

  std::vector<std::vector<long long>> result{};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, OneVertex) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector <struct edge> edges;
  edges.push_back(edge(1, 1, 1));
  Johnson(3, graph, edges);

  std::vector<std::vector<long long>> result{{0, 0, 0, 0}, {0, 0, LLONG_MAX, LLONG_MAX}, {0, LLONG_MAX, 0, LLONG_MAX}, {0, LLONG_MAX, LLONG_MAX, 0}};
  ASSERT_EQ(graph, result);
}
