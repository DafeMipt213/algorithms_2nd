
#include <climits>
#include <gtest/gtest.h>
#include "Jonsons_algorithm.hpp"

TEST(Jonson, Simple) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector <struct edge> E;
  E.push_back(edge(1, 2, 2));
  E.push_back(edge(2, 3, -15));
  E.push_back(edge(1, 3, -10));
  johnson(3, graph, E);

  std::vector<std::vector<long long>> result{{0, 0, 0, 0}, {0, 0, 2, -13}, {0, LLONG_MAX, 0, -15}, {0, LLONG_MAX, LLONG_MAX, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, Cycle) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector <struct edge> E;
  E.push_back(edge(1, 2, 1));
  E.push_back(edge(2, 3, -1));
  E.push_back(edge(3, 1, 2));
  johnson(3, graph, E);

  std::vector<std::vector<long long>> result{{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, -1}, {0, 2, 3, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, Empty) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(0, std::vector<long long>(0, 0));
  std::vector <struct edge> E;
  johnson(0, graph, E);

  std::vector<std::vector<long long>> result{};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, OneVertex) {
  std::vector<std::vector<long long>> graph = std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector <struct edge> E;
  E.push_back(edge(1, 1, 1));
  johnson(3, graph, E);

  std::vector<std::vector<long long>> result{{0, 0, 0, 0}, {0, 0, LLONG_MAX, LLONG_MAX}, {0, LLONG_MAX, 0, LLONG_MAX}, {0, LLONG_MAX, LLONG_MAX, 0}};
  ASSERT_EQ(graph, result);
}
