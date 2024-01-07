#include <gtest/gtest.h>
#include "algorithm_dijkstra.hpp"

TEST(algorithm_dijkstra, Simple) {
  std::vector<std::vector<int>> graph{{0, 1}, {1, 2}};
  std::vector<long long> result{0, 1};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}

TEST(algorithm_dijkstra, Medium) {
  std::vector<std::vector<int>> graph {{0, 5, 2, 6}, {0, 0, 4, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  std::vector<long long> result{0, 5, 2, 3};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}

TEST(algorithm_dijkstra, Empty) {
  std::vector<std::vector<int>> graph {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  std::vector<long long> result{0, INT_MAX, INT_MAX, INT_MAX};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}

TEST(algorithm_dijkstra, Full) {
  std::vector<std::vector<int>> graph {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  std::vector<long long> result{13, 14, 15, 0};
  ASSERT_EQ(Dijkstra(graph, 3), result);
}

TEST(algorithm_dijkstra, SimpleCycle) {
  std::vector<std::vector<int>> graph {{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 0}};
  std::vector<long long> result{0, 1, 2, 3};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}

TEST(algorithm_dijkstra, Cycle) {
  std::vector<std::vector<int>> graph {{0, 10, 10, 1}, {10, 1, 1, 1}, {1, 10, 1, 1}, {1, 1, 9, 10}};
  std::vector<long long> result{0, 2, 3, 1};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}

TEST(algorithm_dijkstra, BigNumbers) {
  std::vector<std::vector<int>> graph {{1034, 9487, 6744, 0}, {5439, 5383, 0, 5273}, {8294, 9264, 2947, 0}, {2474, 2894, 3857, 3946}};
  std::vector<long long> result{0, 9487, 6744, 14760};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}

TEST(algorithm_dijkstra, BigMatrix) {
  std::vector<std::vector<int>> graph {{35, 83, 80, 18, 81, 18, 61, 41, 22, 49},
                                      {75, 49, 82, 48, 55, 6, 96, 54, 95, 98},
                                      {10, 11, 16, 13, 70, 13, 24, 43, 66, 21},
                                      {50, 85, 89, 26, 100, 57, 73, 58, 66, 79},
                                      {2, 7, 62, 54, 76, 13, 71, 23, 36, 23},
                                      {4, 79, 33, 35, 15, 18, 78, 9, 14, 24},
                                      {36, 8, 56, 88, 91, 45, 70, 70, 84, 54},
                                      {38, 47, 35, 31, 85, 15, 9, 39, 1, 74},
                                      {34, 75, 41, 79, 21, 41, 80, 25, 97, 58},
                                      {36, 92, 7, 87, 35, 90, 17, 26, 65, 95}};
  std::vector<long long> result {0, 40, 49, 18, 33, 18, 36, 27, 22, 42};
  ASSERT_EQ(Dijkstra(graph, 0), result);
}