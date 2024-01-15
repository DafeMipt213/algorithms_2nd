#include <gtest/gtest.h>

#include "lca.hpp"

TEST(LCA, Simple) {
  AllData data;
  data.graph = {{0, {1, 2}}, {1, {0}}, {2, {2}}};
  data.n = 3;
  Precompute(0, data);
  ASSERT_EQ(LCA(1, 2, data), 0);
}

TEST(LCA, MediumGraphFirstTest) {
  AllData data;
  data.graph = {{0, {1, 4}}, {1, {0, 2, 3}}, {2, {1}}, {3, {1}}, {4, {0}}};
  data.n = 5;
  Precompute(0, data);
  ASSERT_EQ(LCA(2, 3, data), 1);
}

TEST(LCA, MediumGraphSecondTest) {
  AllData data;
  data.graph = {{0, {1, 4}}, {1, {0, 2, 3}}, {2, {1}}, {3, {1}}, {4, {0}}};
  data.n = 5;
  Precompute(0, data);
  ASSERT_EQ(LCA(2, 4, data), 0);
}

TEST(LCA, BigGraphFirstTest) {
  AllData data;
  data.graph = {{0, {1, 2}}, {1, {0, 3, 4}}, {2, {0, 6}}, {3, {1, 5}},
                {4, {1}},    {5, {3}},       {6, {2, 7}}, {7, {6, 8, 9}},
                {8, {7}},    {9, {7}}};
  data.n = 10;
  Precompute(0, data);
  ASSERT_EQ(LCA(5, 9, data), 0);
}

TEST(LCA, BigGraphSecondTest) {
  AllData data;
  data.graph = {{0, {1, 2}}, {1, {0, 3, 4}}, {2, {0, 6}}, {3, {1, 5}},
                {4, {1}},    {5, {3}},       {6, {2, 7}}, {7, {6, 8, 9}},
                {8, {7}},    {9, {7}}};
  data.n = 10;
  Precompute(0, data);
  ASSERT_EQ(LCA(8, 9, data), 7);
}

TEST(LCA, BigGraphThirdTest) {
  AllData data;
  data.graph = {{0, {1, 2}}, {1, {0, 3, 4}}, {2, {0, 6}}, {3, {1, 5}},
                {4, {1}},    {5, {3}},       {6, {2, 7}}, {7, {6, 8, 9}},
                {8, {7}},    {9, {7}}};
  data.n = 10;
  Precompute(0, data);
  ASSERT_EQ(LCA(3, 4, data), 1);
}

TEST(LCA, BigGraphTest) {
  AllData data;
  data.graph = {{0, {1, 2}}, {1, {0, 3, 4}}, {2, {0, 6}}, {3, {1, 5}},
                {4, {1}},    {5, {3}},       {6, {2, 7}}, {7, {6, 8, 9}},
                {8, {7}},    {9, {7}}};
  data.n = 10;
  Precompute(0, data);
  ASSERT_EQ(LCA(1, 7, data), 0);
}

TEST(LCA, SamePathTest) {
  AllData data;
  data.graph = {{0, {1}}, {1, {0, 2}}, {2, {1, 3}}, {3, {2}}};
  data.n = 4;
  Precompute(0, data);
  ASSERT_EQ(LCA(1, 3, data), 1);
}

TEST(LCA, UniqueTestNinth) {
  AllData data;
  data.graph = {{0, {1, 2}}, {1, {0, 3, 4}}, {2, {0, 5}}, {3, {1}}, {4, {1}}, {5, {2}}};
  data.n = 6;
  Precompute(0, data);
  ASSERT_EQ(LCA(3, 5, data), 0);
}

TEST(LCA, UniqueTestTenth) {
  AllData data;
  data.graph = {{0, {1}}, {1, {0, 2, 3}}, {2, {1, 4}}, {3, {1}}, {4, {2}}};
  data.n = 5;
  Precompute(0, data);
  ASSERT_EQ(LCA(3, 4, data), 1);
}