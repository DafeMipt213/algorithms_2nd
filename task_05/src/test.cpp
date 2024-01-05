#include "rmq.hpp"
#include <gtest/gtest.h>

TEST(RMQ, Simple) {
  std::vector<int> data{0, 2, 3, 5, 1, 4, 7};
  RMQ rmq(data);
  ASSERT_EQ(rmq.rmq(1, 4), 1);
  ASSERT_EQ(rmq.rmq(0, 5), 0);
  ASSERT_EQ(rmq.rmq(1, 6), 1);
  ASSERT_EQ(rmq.rmq(5, 6), 4);
  ASSERT_EQ(rmq.rmq(4, 4), 1);
}
