
#include <gtest/gtest.h>

#include <stack>

#include "prim.hpp"

TEST(Prim, BigGraph) {
  std::vector<std::vector<Vertex>> graph{
      {{1, 1}, {2, 7}, {3, 3}, {4, 7}, {5, 10}, {6, 1}},
      {{0, 1}, {2, 3}, {3, 1}},
      {{0, 7}, {1, 3}, {3, 4}},
      {{0, 3}, {1, 1}, {2, 4}, {4, 2}},
      {{3, 2}, {0, 7}, {5, 3}},
      {{4, 3}, {0, 10}, {6, 4}},
      {{0, 1}, {5, 4}}};
  std::vector<std::vector<Vertex>> res{
      {{1, 1}, {6, 1}}, {{0, 1}, {3, 1}, {2, 3}}, {{1, 3}},
      {{1, 1}, {4, 2}}, {{3, 2}, {5, 3}},         {{4, 3}},
      {{0, 1}}};
  std::vector<std::vector<Vertex>> primres = prim(graph);
  ASSERT_EQ(prim(graph), res);
}

TEST(Prim, SimpleGraph) {
  std::vector<std::vector<Vertex>> graph{
      {{1, 3}, {2, 1000}}, {{0, 3}, {2, 3}}, {{1, 3}, {0, 1000}}};
  std::vector<std::vector<Vertex>> res{{{1, 3}}, {{0, 3}, {2, 3}}, {{1, 3}}};
  std::vector<std::vector<Vertex>> primres = prim(graph);
  ASSERT_EQ(prim(graph), res);
}

TEST(Prim, EmptyGraph) {
  std::vector<std::vector<Vertex>> graph{};
  std::vector<std::vector<Vertex>> res{};
  std::vector<std::vector<Vertex>> primres = prim(graph);
  ASSERT_EQ(prim(graph), res);
}
