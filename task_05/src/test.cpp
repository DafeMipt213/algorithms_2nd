#include <gtest/gtest.h>

#include "rmq.hpp"

TEST(TopologySort, Simple) {
  std::vector<int> graph{1, 2, 3, 4, 5, 6, 7, 8, 10};
  ASSERT_EQ(RMQ(0, 5, graph), 0);
}

TEST(RMQ, AllElementsSame) {
  std::vector<int> graph{5, 5, 5, 5, 5, 5, 5, 5, 5};
  ASSERT_EQ(RMQ(0, 8, graph), 8);
}

TEST(RMQ, DecreasingOrder) {
  std::vector<int> graph{9, 8, 7, 6, 5, 4, 3, 2, 1};
  ASSERT_EQ(RMQ(2, 6, graph), 6);
}

TEST(RMQ, RandomElements) {
  std::vector<int> graph{1, 3, 5, 7, 9, 2, 4, 6, 8};
  ASSERT_EQ(RMQ(1, 7, graph), 5);
}

TEST(RMQ, AllElementsNegative) {
  std::vector<int> graph{-5, -5, -5, -5, -5, -5, -5, -5, -5};
  ASSERT_EQ(RMQ(0, 8, graph), 8);
}

TEST(RMQ, NegativeAndPositive) {
  std::vector<int> graph{-1, 2, -3, 4, -5, 6, -7, 8, -9};
  ASSERT_EQ(RMQ(0, 8, graph), 8);
}

TEST(RMQ, NegativeDecreasingOrder) {
  std::vector<int> graph{-1, -2, -3, -4, -5, -6, -7, -8, -9};
  ASSERT_EQ(RMQ(2, 6, graph), 6);
}

TEST(RMQ, FifteenElements) {
  std::vector<int> graph{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  ASSERT_EQ(RMQ(5, 10, graph), 5);
}

TEST(RMQ, FriendTest) {
  std::vector<int> graph{-50, -40, -30, -20, -10};
  ASSERT_EQ(RMQ(0, 5, graph), 0);
}