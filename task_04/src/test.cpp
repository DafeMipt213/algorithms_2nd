#include <gtest/gtest.h>
#include "algorithm_dijkstra.hpp"

TEST(algorithm_dijkstra, Simple) {
  std::vector<std::vector<int>> graph{{0, 1}, {1, 2}};
  std::vector<long long> res{0, 1};
  ASSERT_EQ(Dijkstra(graph, 0), res);
}

TEST(algorithm_dijkstra, Medium) {
  std::vector<std::vector<int>> graph {{0, 5, 2, 6}, {0, 0, 4, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  std::vector<long long> res{0, 5, 2, 3};
  ASSERT_EQ(Dijkstra(graph, 0), res);
}

TEST(algorithm_dijkstra, Empty) {
  std::vector<std::vector<int>> graph {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  std::vector<long long> res{0, INT_MAX, INT_MAX, INT_MAX};
  ASSERT_EQ(Dijkstra(graph, 0), res);
}

TEST(algorithm_dijkstra, Full) {
  std::vector<std::vector<int>> graph {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  std::vector<long long> res{13, 14, 15, 0};
  ASSERT_EQ(Dijkstra(graph, 3), res);
}

TEST(algorithm_dijkstra, SimpleCycle) {
  std::vector<std::vector<int>> graph {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 0}};
  std::vector<long long> res{0, 1, 2, 3};
  ASSERT_EQ(Dijkstra(graph, 0), res);
}

TEST(algorithm_dijkstra, Cycle) {
  std::vector<std::vector<int>> graph {{0, 10, 10, 1}, {10, 1, 1, 1}, {1, 10, 1, 1}, {1, 1, 9, 10}};
  std::vector<long long> res{0, 2, 3, 1};
  ASSERT_EQ(Dijkstra(graph, 0), res);
}

TEST(algorithm_dijkstra, BigNumbers) {
  std::vector<std::vector<int>> graph {{1034, 9487, 6744, 0}, {5439, 5383, 0, 5273}, {8294, 9264, 2947, 0}, {2474, 2894, 3857, 3946}};
  std::vector<long long> res{0, 9487, 6744, 14760};
  ASSERT_EQ(Dijkstra(graph, 0), res);
}