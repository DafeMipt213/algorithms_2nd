
#include <gtest/gtest.h>
#include "Jonson.hpp"

TEST(FordBellman, NoNegativeGraph) {
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, -1}}};
  std::vector<int> d(6, 0);
  ASSERT_EQ(fordBellman(5, graph, d), 1);
}

TEST(FordBellman, WithNegativeGraph) {
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, -10}}};
  std::vector<int> d(6, 0);
  ASSERT_EQ(fordBellman(5, graph, d), 0);
}

TEST(FordBellman, NoNegativeGraphDistances) {
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, 3}}};
  std::vector<int> d(6, 0);
  fordBellman(5, graph, d);
  std::vector<int> res{5, 4, 3, 4, 5, 0};
  ASSERT_EQ(d, res);
}

TEST(FordBellman, HarderGraphDistances) {
  std::vector<std::vector<std::pair<int, int>>> graph{{{7, 1}, {5, 2}, {3, 3}, {2, 4}}, {{2, -5}}, {{3, 1}}, {{4, 5}}, {{5, 7}}, {{6, 8}}, {{7, 1}}, {{1, 0}}};
  std::vector<int> d(8, 0);
  ASSERT_EQ(fordBellman(0, graph, d), 1);
}

TEST(Dijkstra, NoNegativeGraphDistances) {
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, 3}}};
  std::vector<int> d(6, 0);
  dijkstra(graph, 5, d);
  std::vector<int> res{5, 4, 3, 4, 5, 0};
  ASSERT_EQ(d, res);
}

TEST(Dijkstra, HarderGraphDistances) {
  std::vector<std::vector<std::pair<int, int>>> graph{{{7, 1}, {5, 2}, {3, 3}, {2, 4}}, {{2, -5}}, {{3, 1}}, {{4, 5}}, {{5, 7}}, {{6, 8}}, {{7, 1}}, {{1, 0}}};
  std::vector<int> d(8, 0);
  dijkstra(graph, 0, d);
  std::vector<int> res{0, 1, -4, -3, 2, 2, 10, 1};
  ASSERT_EQ(d, res);
}

TEST(Jonson, SimpleGraphNoNegativeCycle){
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, 3}}};
  std::vector<std::vector<int>> d = jonson(graph);
  std::vector<std::vector<int>> result = {{0, 5, 4, 5, 6, 1}, 
                                          {1, 0, 5, 6, 7, 2},
                                          {2, 1, 0, 1, 2, 3},
                                          {7, 6, 5, 0, 1, 2},
                                          {6, 5, 4, 5, 0, 1},
                                          {5, 4, 3, 4, 5, 0}};
  ASSERT_EQ(d, result);
}

TEST(Jonson, NegativeCycle){
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, -10}}};
  ASSERT_THROW(jonson(graph), std::runtime_error);
}

TEST(Jonson, NegativeLoop){
  std::vector<std::vector<std::pair<int, int>>> graph{{{5, 1}}, {{0, 1}}, {{1, 1}, {3, 1}}, {{4, 1}}, {{5, 1}}, {{2, 3}, {5, -10}}};
  ASSERT_THROW(jonson(graph), std::runtime_error);
}

TEST(Jonson, BigGraphNoNegativeCycle){
  std::vector<std::vector<std::pair<int, int>>> graph{{{1, -1}}, {{2, 3}, {4, 5}}, {{3, -2}}, {{4, 7}}, {{1, -2}, {5, 4}, {7, 0}, {8, 11}}, {{0, 3}}, {{9, 10}}, {{6, -3}, {8, -3}}, {{3, 1}}, {{7, -1}, {8, 2}}};
  std::vector<std::vector<int>> d = jonson(graph);
  std::vector<std::vector<int>> result = {{ 0, -1, 2, 0, 4, 8, 1, 4, 1, 11 }, 
                                          { 12, 0, 3, 1, 5, 9, 2, 5, 2, 12 },
                                          { 12, 3, 0, -2, 5, 9, 2, 5, 2, 12 },
                                          { 14, 5, 8, 0, 7, 11, 4, 7, 4, 14 },
                                          { 7, -2, 1, -2, 0, 4, -3, 0, -3, 7 },
                                          { 3, 2, 5, 3, 7, 0, 4, 7, 4, 14 },
                                          { 21, 12, 15, 7, 14, 18, 0, 9, 6, 10 },
                                          { 12, 3, 6, -2, 5, 9, -3, 0, -3, 7 },
                                          { 15, 6, 9, 1, 8, 12, 5, 8, 0, 15 },
                                          { 11, 2, 5, -3, 4, 8, -4, -1, -4, 0 }};
  ASSERT_EQ(d, result);
}

TEST(Jonson, LittleGraphNoNegativeCycle){
  std::vector<std::vector<std::pair<int, int>>> graph{{{1, 1}}, {{2, 1}}, {{0, 1}}};
  std::vector<std::vector<int>> d = jonson(graph);
  std::vector<std::vector<int>> result = {{0, 1, 2},
                                          {2, 0, 1},
                                          {1, 2, 0}};
  ASSERT_EQ(d, result);
}