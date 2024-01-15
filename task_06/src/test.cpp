
#include <gtest/gtest.h>

#include "lca.hpp"

TEST(LCA, Simple) {
  std::map<int, std::vector<int>> graph{
      {0, {2, 3}}, {1, {2}}, {2, {0, 1}},    {3, {0, 4}}, {4, {3, 7}},
      {5, {6, 7}}, {6, {5}}, {7, {4, 5, 8}}, {8, {8}}};
  Solution solution(graph, 4);
  ASSERT_EQ(solution.LCA(6, 8), 7);
  ASSERT_EQ(solution.LCA(1, 6), 4);
}

TEST(LCA, Complex) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2, 3}}, {1, {0, 4, 5}},   {2, {0, 6, 7}},     {3, {0, 8, 9}},
      {4, {1, 10}},   {5, {1, 11, 12}}, {6, {2, 13}},       {7, {2, 14}},
      {8, {3}},       {9, {9}},         {10, {4}},          {11, {5, 15, 16}},
      {12, {5}},      {13, {6}},        {14, {7, 17, 18}},  {15, {11}},
      {16, {11}},     {17, {14}},       {18, {14, 19, 20}}, {19, {18}},
      {20, {18}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(15, 12), 5);
  ASSERT_EQ(solution.LCA(13, 17), 2);
}

TEST(LCA, AnotherComplexTest) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2, 3}}, {1, {0, 4, 5}},   {2, {0, 6, 7}},     {3, {0, 8, 9}},
      {4, {1, 10}},   {5, {1, 11, 12}}, {6, {2, 13}},       {7, {2, 14}},
      {8, {3}},       {9, {3}},         {10, {4}},          {11, {5, 15, 16}},
      {12, {5}},      {13, {6}},        {14, {7, 17, 18}},  {15, {11}},
      {16, {11}},     {17, {14}},       {18, {14, 19, 20}}, {19, {18}},
      {20, {18}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(10, 12), 1);
  ASSERT_EQ(solution.LCA(13, 19), 2);
}

TEST(LCA, DifferentGraphStructure) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2}},    {1, {0, 3, 4}}, {2, {0, 5, 6}},  {3, {1}},
      {4, {1, 7, 8}}, {5, {2}},       {6, {2, 9, 10}}, {7, {4}},
      {8, {4}},       {9, {6}},       {10, {6}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(7, 8), 4);
  ASSERT_EQ(solution.LCA(9, 10), 6);
  ASSERT_EQ(solution.LCA(3, 7), 1);
}

TEST(LCA, YetAnotherGraph) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2}},     {1, {0, 3, 4}}, {2, {0, 5, 6}},   {3, {1, 7, 8}},
      {4, {1, 9, 10}}, {5, {2}},       {6, {2, 11, 12}}, {7, {3}},
      {8, {3}},        {9, {4}},       {10, {4}},        {11, {6}},
      {12, {6}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(7, 8), 3);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 6);
  ASSERT_EQ(solution.LCA(7, 9), 1);
}

TEST(LCA, ComplexGraphStructure) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2, 3}},   {1, {0, 4, 5}},   {2, {0, 6, 7}},   {3, {0, 8, 9}},
      {4, {1, 10, 11}}, {5, {1, 12, 13}}, {6, {2, 14, 15}}, {7, {2, 16, 17}},
      {8, {3, 18, 19}}, {9, {3, 20, 21}}, {10, {4}},        {11, {4}},
      {12, {5}},        {13, {5}},        {14, {6}},        {15, {6}},
      {16, {7}},        {17, {7}},        {18, {8}},        {19, {8}},
      {20, {9}},        {21, {9}}};
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
  std::map<int, std::vector<int>> graph{
      {0, {1, 2}},     {1, {0, 3, 4}},   {2, {0, 5, 6}},   {3, {1, 7, 8}},
      {4, {1, 9, 10}}, {5, {2, 11, 12}}, {6, {2, 13, 14}}, {7, {3}},
      {8, {3}},        {9, {4}},         {10, {4}},        {11, {5}},
      {12, {5}},       {13, {6}},        {14, {6}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(7, 8), 3);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 5);
  ASSERT_EQ(solution.LCA(13, 14), 6);
  ASSERT_EQ(solution.LCA(7, 14), 0);
}

TEST(LCA, ExtraGraph2) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2}},     {1, {0, 3, 4}},   {2, {0, 5, 6}},   {3, {1, 7, 8}},
      {4, {1, 9, 10}}, {5, {2, 11, 12}}, {6, {2, 13, 14}}, {7, {3, 15, 16}},
      {8, {3}},        {9, {4}},         {10, {4}},        {11, {5}},
      {12, {5}},       {13, {6}},        {14, {6}},        {15, {7}},
      {16, {7}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(15, 16), 7);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 5);
  ASSERT_EQ(solution.LCA(13, 14), 6);
  ASSERT_EQ(solution.LCA(15, 9), 1);
}

TEST(LCA, ExtraGraph3) {
  std::map<int, std::vector<int>> graph{
      {0, {1, 2}},      {1, {0, 3, 4}},   {2, {0, 5, 6}},   {3, {1, 7, 8}},
      {4, {1, 9, 10}},  {5, {2, 11, 12}}, {6, {2, 13, 14}}, {7, {3, 15, 16}},
      {8, {3, 17, 18}}, {9, {4}},         {10, {4}},        {11, {5}},
      {12, {5}},        {13, {6}},        {14, {6}},        {15, {7}},
      {16, {7}},        {17, {8}},        {18, {8}}};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(15, 16), 7);
  ASSERT_EQ(solution.LCA(17, 18), 8);
  ASSERT_EQ(solution.LCA(9, 10), 4);
  ASSERT_EQ(solution.LCA(11, 12), 5);
  ASSERT_EQ(solution.LCA(13, 14), 6);
  ASSERT_EQ(solution.LCA(17, 9), 1);
}

TEST(LCA, EmptyGraph) {
  std::map<int, std::vector<int>> graph{};
  Solution solution(graph, 0);
  ASSERT_EQ(solution.LCA(1, 2), -1);
}