
#include <gtest/gtest.h>

#include <vector>

#include "rmq.hpp"

TEST(RMQ, Simple) {
  std::vector<long long> test{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(2, 4), 6);
  ASSERT_EQ(rmq.GetMin(0, 8), 1);
  ASSERT_EQ(rmq.GetMin(4, 5), 3);
}

TEST(RMQ, Simple2) {
  std::vector<long long> test{1, 2, 3};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(1, 2), 2);
  ASSERT_EQ(rmq.GetMin(0, 3), 1);
}

TEST(RMQ, OneElement) {
  std::vector<long long> test{1};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 1), 1);
}

TEST(RMQ, SameElements) {
  std::vector<long long> test{100, 100, 100, 100, 100};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 5), 100);
}

TEST(RMQ, Negative) {
  std::vector<long long> test{-1, -2, -3, -100};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 3), -3);
  ASSERT_EQ(rmq.GetMin(2, 4), -100);
}

TEST(RMQ, Medium) {
  std::vector<long long> test{-14, 8, 3, 7, -8, 6, 10, 13, -13, 14};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 10), -14);
  ASSERT_EQ(rmq.GetMin(1, 2), 8);
}

TEST(RMQ, Empty) {
  std::vector<long long> test{};
  RMQ rmq{test};
  ASSERT_ANY_THROW(rmq.GetMin(0, 1));
}

TEST(RMQ, Exceptions) {
  std::vector<long long> test{-14, 8, 3, 7, -8, 6, 10, 13, -13, 14};
  RMQ rmq{test};
  ASSERT_ANY_THROW(rmq.GetMin(5, 0));
  ASSERT_ANY_THROW(rmq.GetMin(5, 5));
  ASSERT_ANY_THROW(rmq.GetMin(4, 11));
}

TEST(RMQ, Hard) {
  std::vector<long long> test{1,  -10, 6,  -6,  -5,  1, 5, 1, -7, 7,
                              15, 3,   -9, -12, -15, 1, 0, 3, 9,  -10};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 20), -15);
  ASSERT_EQ(rmq.GetMin(19, 20), -10);
  ASSERT_EQ(rmq.GetMin(0, 5), -10);
}

TEST(RMQ, BigVector) {
  std::vector<long long> test{11, 9,   -1, -1, -11, -9,  7, -12, 0,  -13,
                              14, -12, -4, 1,  15,  -15, 2, 7,   12, -6,
                              7,  15,  -5, 7,  -5,  -7,  3, 4,   -5, 2};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 30), -15);
  ASSERT_EQ(rmq.GetMin(2, 6), -11);
  ASSERT_EQ(rmq.GetMin(7, 25), -15);
}