
#include <gtest/gtest.h>

#include <vector>

#include "rmq.hpp"

TEST(RMQ, Simple) {
  std::vector<long long> test1{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq1{test1};
  ASSERT_EQ(rmq1.GetMin(2, 4), 6);
  ASSERT_EQ(rmq1.GetMin(0, 8), 1);
  ASSERT_EQ(rmq1.GetMin(4, 5), 3);

  std::vector<long long> test2{1, 2, 3};
  RMQ rmq2{test2};
  ASSERT_EQ(rmq2.GetMin(1, 2), 2);
  ASSERT_EQ(rmq2.GetMin(0, 3), 1);
}

TEST(RMQ, Medium) {
  std::vector<long long> test{-14, 8, 3, 7, -8, 6, 10, 13, -13, 14};
  RMQ rmq{test};
  ASSERT_EQ(rmq.GetMin(0, 10), -14);
  ASSERT_EQ(rmq.GetMin(1, 2), 8);
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
