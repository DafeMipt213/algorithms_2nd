
#include <gtest/gtest.h>

#include "rmq.hpp"

TEST(TopologySort, Simple) {
  ASSERT_EQ(RMQ({1, 2, 5, 6, -5, 10}, 1, 3), 2);
  ASSERT_EQ(RMQ({1}, 0, 0), 1);
  ASSERT_EQ(RMQ({1}, 0, 1), 1);
}

TEST(TopologySort, Exceptions) {
  EXPECT_ANY_THROW(RMQ({1, 2, 5, 6, -5, 10}, 4, 3));
}
