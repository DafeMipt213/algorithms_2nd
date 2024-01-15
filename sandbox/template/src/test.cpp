
#include <gtest/gtest.h>

#include <stack>

#include "utils.hpp"

TEST(Template, Easy) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 7), 1);
}
TEST(Template, Medium) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(6, 7), 1);
}
TEST(Template, Hard) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(3, 4), 3);
}
TEST(Template, Harder) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11, 12};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(7, 8), 11);
}
TEST(Template, Comlicated) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11, 12, 1, 1, 1};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 11), 1);
}
TEST(Template, Zero) {
  std::vector<int> vec{1, 10};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 1), 10);
}
