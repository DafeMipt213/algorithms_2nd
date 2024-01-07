
#include <gtest/gtest.h>

#include "lca.hpp"

TEST(LCA, Simple) {
  std::vector<std::vector<int>> graph{{2, 3}, {2}, {0, 1},    {0, 4}, {3, 7},
                                      {6, 7}, {5}, {4, 5, 8}, {8}};
  Solution solution(graph, 4);
  ASSERT_EQ(solution.LCA(6, 8), 7);
  ASSERT_EQ(solution.LCA(1, 6), 4);
}

TEST(LCA, Complex) {
  std::vector<std::vector<int>> graph{
      {1, 2, 3},    {0, 4, 5}, {0, 6, 7},   {0, 8, 9}, {1, 10}, {1, 11, 12},
      {2, 13},      {2, 14},   {3},         {9},       {4},     {5, 15, 16},
      {5},          {6},       {7, 17, 18}, {11},      {11},    {14},
      {14, 19, 20}, {18},      {18}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(15, 12), 5);
  ASSERT_EQ(solution.LCA(13, 17), 2);
}

TEST(LCA, AnotherComplexTest) {
  std::vector<std::vector<int>> graph{
      {1, 2, 3},    {0, 4, 5}, {0, 6, 7},   {0, 8, 9}, {1, 10}, {1, 11, 12},
      {2, 13},      {2, 14},   {3},         {3},       {4},     {5, 15, 16},
      {5},          {6},       {7, 17, 18}, {11},      {11},    {14},
      {14, 19, 20}, {18},      {18}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(10, 12), 1);
  ASSERT_EQ(solution.LCA(13, 19), 2);
}

TEST(LCA, DifferentGraphStructure) {
  std::vector<std::vector<int>> graph{{1, 2},    {0, 3, 4}, {0, 5, 6},  {1},
                                      {1, 7, 8}, {2},       {2, 9, 10}, {4},
                                      {4},       {6},       {6}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(7, 8), 4);
  ASSERT_EQ(solution.LCA(9, 10), 6);
  ASSERT_EQ(solution.LCA(3, 7), 1);
}

TEST(LCA, YetAnotherGraph) {
  std::vector<std::vector<int>> graph{
      {1, 2}, {0, 3, 4}, {0, 5, 6}, {1, 7, 8}, {1, 9, 10}, {2}, {2, 11, 12},
      {3},    {3},       {4},       {4},       {6},        {6}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(7, 8), 3);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 6);
  ASSERT_EQ(solution.LCA(7, 9), 1);
}

TEST(LCA, ComplexGraphStructure) {
  std::vector<std::vector<int>> graph{
      {1, 2, 3},   {0, 4, 5},   {0, 6, 7},   {0, 8, 9},   {1, 10, 11},
      {1, 12, 13}, {2, 14, 15}, {2, 16, 17}, {3, 18, 19}, {3, 20, 21},
      {4},         {4},         {5},         {5},         {6},
      {6},         {7},         {7},         {8},         {8},
      {9},         {9}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(10, 11), 4);
  ASSERT_EQ(solution.LCA(12, 13), 5);
  ASSERT_EQ(solution.LCA(14, 15), 6);
  ASSERT_EQ(solution.LCA(16, 17), 7);
  ASSERT_EQ(solution.LCA(18, 19), 8);
  ASSERT_EQ(solution.LCA(20, 21), 9);
  ASSERT_EQ(solution.LCA(10, 21), 0);
}

TEST(LCA, ExtraGraph1) {
  std::vector<std::vector<int>> graph{
      {1, 2},      {0, 3, 4},   {0, 5, 6}, {1, 7, 8}, {1, 9, 10},
      {2, 11, 12}, {2, 13, 14}, {3},       {3},       {4},
      {4},         {5},         {5},       {6},       {6}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(7, 8), 3);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 5);
  ASSERT_EQ(solution.LCA(13, 14), 6);
  ASSERT_EQ(solution.LCA(7, 14), 0);
}

TEST(LCA, ExtraGraph2) {
  std::vector<std::vector<int>> graph{
      {1, 2},      {0, 3, 4},   {0, 5, 6}, {1, 7, 8}, {1, 9, 10}, {2, 11, 12},
      {2, 13, 14}, {3, 15, 16}, {3},       {4},       {4},        {5},
      {5},         {6},         {6},       {7},       {7}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(15, 16), 7);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 5);
  ASSERT_EQ(solution.LCA(13, 14), 6);
  ASSERT_EQ(solution.LCA(15, 9), 1);
}

TEST(LCA, ExtraGraph3) {
  std::vector<std::vector<int>> graph{
      {1, 2},      {0, 3, 4},   {0, 5, 6},   {1, 7, 8},   {1, 9, 10},
      {2, 11, 12}, {2, 13, 14}, {3, 15, 16}, {3, 17, 18}, {4},
      {4},         {5},         {5},         {6},         {6},
      {7},         {7},         {8},         {8}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(15, 16), 7);
  ASSERT_EQ(solution.LCA(17, 18), 8);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 5);
  ASSERT_EQ(solution.LCA(13, 14), 6);
  ASSERT_EQ(solution.LCA(17, 9), 1);
}

TEST(LCA, EmptyGraph) {
  std::vector<std::vector<int>> graph{};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(1, 2), -1);
}