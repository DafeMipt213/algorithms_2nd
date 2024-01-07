#include <gtest/gtest.h>

#include <iostream>

#include "sparse_table.hpp"

TEST(RMQ, Simple) {
  std::vector<int> data{7, 9, 8, 6, 1, 4, 5, 2, 3, 0};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(1, 5), 1);
  ASSERT_EQ(table.FindMin(2, 3), 6);
  ASSERT_EQ(table.FindMin(0, 2), 7);
  ASSERT_EQ(table.FindMin(0, 10), 0);
}

TEST(RMQ, Test1) {
  std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 1);
  ASSERT_EQ(table.FindMin(5, 9), 6);
}

TEST(RMQ, Test2) {
  std::vector<int> data{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 6);
  ASSERT_EQ(table.FindMin(5, 10), 1);
}

TEST(RMQ, Test3) {
  std::vector<int> data{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 1);
  ASSERT_EQ(table.FindMin(5, 10), 2);
}

TEST(RMQ, Test4) {
  std::vector<int> data{10, 8, 6, 4, 2, 9, 7, 5, 3, 1};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 2);
  ASSERT_EQ(table.FindMin(5, 10), 1);
}

TEST(RMQ, Test5) {
  std::vector<int> data{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 1);
  ASSERT_EQ(table.FindMin(5, 10), 3);
}

TEST(RMQ, Test6) {
  std::vector<int> data{5, 5, 4, 4, 3, 3, 2, 2, 1, 1};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 4);
  ASSERT_EQ(table.FindMin(5, 10), 1);
}

TEST(RMQ, Test7) {
  std::vector<int> data{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 1);
  ASSERT_EQ(table.FindMin(5, 10), 4);
}

TEST(RMQ, Test8) {
  std::vector<int> data{6, 5, 7, 4, 8, 3, 9, 2, 10, 1};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 4);
  ASSERT_EQ(table.FindMin(5, 10), 1);
}

TEST(RMQ, Test9) {
  std::vector<int> data{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 10);
  ASSERT_EQ(table.FindMin(5, 10), 60);
}

TEST(RMQ, Test10) {
  std::vector<int> data{100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
  SparseTable table(data);
  ASSERT_EQ(table.FindMin(0, 5), 60);
  ASSERT_EQ(table.FindMin(5, 10), 10);
}