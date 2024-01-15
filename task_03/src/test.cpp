#include <gtest/gtest.h>

#include <limits>

#include "jonsons_algorithm.hpp"

TEST(Jonson, Simple) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(1, 2, 2));
  edges.push_back(Edge(2, 3, -15));
  edges.push_back(Edge(1, 3, -10));
  Johnson(3, graph, edges);

  std::vector<std::vector<long long>> result{
      {0, 0, 0, 0},
      {0, 0, 2, -13},
      {0, std::numeric_limits<long long>::max(), 0, -15},
      {0, std::numeric_limits<long long>::max(),
       std::numeric_limits<long long>::max(), 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, Cycle) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(1, 2, 1));
  edges.push_back(Edge(2, 3, -1));
  edges.push_back(Edge(3, 1, 2));
  Johnson(3, graph, edges);

  std::vector<std::vector<long long>> result{
      {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, -1}, {0, 2, 3, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, Empty) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(0, std::vector<long long>(0, 0));
  std::vector<Edge> edges;
  Johnson(0, graph, edges);

  std::vector<std::vector<long long>> result{};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, OneVertex) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(1, 1, 1));
  Johnson(3, graph, edges);

  std::vector<std::vector<long long>> result{
      {0, 0, 0, 0},
      {0, 0, std::numeric_limits<long long>::max(),
       std::numeric_limits<long long>::max()},
      {0, std::numeric_limits<long long>::max(), 0,
       std::numeric_limits<long long>::max()},
      {0, std::numeric_limits<long long>::max(),
       std::numeric_limits<long long>::max(), 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, PythonTestFirst) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(3, std::vector<long long>(3, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(0, 1, 46));
  edges.push_back(Edge(0, 2, 20));
  edges.push_back(Edge(1, 0, 60));
  edges.push_back(Edge(1, 1, 73));
  edges.push_back(Edge(2, 1, 76));
  edges.push_back(Edge(2, 2, 48));
  Johnson(2, graph, edges);

  std::vector<std::vector<long long>> result{{0, 0, 0}, {0, 0, 80}, {0, 76, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, PythonTestSecond) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(3, std::vector<long long>(3, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(0, 2, 90));
  edges.push_back(Edge(1, 0, -74));
  edges.push_back(Edge(1, 2, 42));
  edges.push_back(Edge(2, 0, -14));
  edges.push_back(Edge(2, 2, -13));
  Johnson(2, graph, edges);

  std::vector<std::vector<long long>> result{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, PythonTestThird) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(3, std::vector<long long>(3, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(0, 0, -63));
  edges.push_back(Edge(0, 1, -118));
  edges.push_back(Edge(0, 2, -419));
  edges.push_back(Edge(1, 0, 497));
  edges.push_back(Edge(1, 2, 227));
  edges.push_back(Edge(2, 1, -384));
  edges.push_back(Edge(2, 2, 346));
  Johnson(2, graph, edges);

  std::vector<std::vector<long long>> result{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, PythonTestFourth) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(4, std::vector<long long>(4, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(0, 3, 8));
  edges.push_back(Edge(0, 4, 8));
  edges.push_back(Edge(1, 0, -10));
  edges.push_back(Edge(1, 2, 7));
  edges.push_back(Edge(1, 4, 7));
  edges.push_back(Edge(2, 0, 5));
  edges.push_back(Edge(2, 2, -6));
  edges.push_back(Edge(2, 4, 10));
  edges.push_back(Edge(3, 4, 1));
  edges.push_back(Edge(4, 0, 7));

  std::vector<std::vector<long long>> result{
      {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, HandMadeFirst) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(3, std::vector<long long>(3, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(0, 2, -8));
  edges.push_back(Edge(1, 0, -10));
  edges.push_back(Edge(2, 0, 5));

  std::vector<std::vector<long long>> result{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  ASSERT_EQ(graph, result);
}

TEST(Jonson, HandMadeSecond) {
  std::vector<std::vector<long long>> graph =
      std::vector<std::vector<long long>>(3, std::vector<long long>(3, 0));
  std::vector<Edge> edges;
  edges.push_back(Edge(2, 2, -8));
  edges.push_back(Edge(1, 0, -10));
  edges.push_back(Edge(2, 0, 5));
  edges.push_back(Edge(2, 1, 14));

  std::vector<std::vector<long long>> result{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  ASSERT_EQ(graph, result);
}