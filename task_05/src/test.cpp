
#include <gtest/gtest.h>

#include <stack>

#include "RMQ.hpp"

TEST(RMQ, Easy) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 7), 1);
}
TEST(RMQ, Medium) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(6, 7), 1);
}
TEST(RMQ, Hard) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(3, 4), 3);
}
TEST(RMQ, Harder) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11, 12};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(7, 8), 11);
}
TEST(RMQ, Comlicated) {
  std::vector<int> vec{1, 10, 7, 6, 3, 2, 1, 11, 12, 1, 1, 1};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 11), 1);
}
TEST(RMQ, One_Element) {
  std::vector<int> vec{1, 10};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 1), 10);
}
TEST(RMQ, Big_Vector) {
  std::vector<int> vec{1, 10, -1, 2, 3, 5, -6, -7, 8, 10, 10, 2,  3, 4, 1,
                       2, 4,  2,  1, 2, 3, 4,  4,  3, 1,  10, -1, 1, 1, -1};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(5, 11), -7);
}

TEST(RMQ, Big_Vector_One_Element) {
  std::vector<int> vec{1, 10, -1, 2, 3, 5, -6, -7, 8, 10, 10, 2,  3, 4, 1,
                       2, 4,  2,  1, 2, 3, 4,  4,  3, 1,  10, -1, 1, 1, -1};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(1, 1), 10);
}

TEST(RMQ, Big_Vector_All_Elements) {
  std::vector<int> vec{1, 10, -1, 2, 3, 5, -6, -7, 8, 10, 10, 2,  3, 4, 1,
                       2, 4,  2,  1, 2, 3, 4,  4,  3, 1,  10, -1, 1, 1, -1};
  RMQ rmq(vec);
  ASSERT_EQ(rmq.findMin(0, 29), -7);
}

TEST(RMQ, Left_Bigger_Than_Right) {
  std::vector<int> vec{1, 10, -1, 2, 3, 5, -6, -7, 8, 10, 10, 2,  3, 4, 1,
                       2, 4,  2,  1, 2, 3, 4,  4,  3, 1,  10, -1, 1, 1, -1};
  RMQ rmq(vec);
  ASSERT_ANY_THROW(rmq.findMin(4, 0));
}

TEST(RMQ, Left_Less_Than_Zero) {
  std::vector<int> vec{1, 10, -1, 2, 3, 5, -6, -7, 8, 10, 10, 2,  3, 4, 1,
                       2, 4,  2,  1, 2, 3, 4,  4,  3, 1,  10, -1, 1, 1, -1};
  RMQ rmq(vec);
  ASSERT_ANY_THROW(rmq.findMin(-12, 11));
}

TEST(RMQ, Right_More_Than_Vector_Size) {
  std::vector<int> vec{1, 10, -1, 2, 3, 5, -6, -7, 8, 10, 10, 2,  3, 4, 1,
                       2, 4,  2,  1, 2, 3, 4,  4,  3, 1,  10, -1, 1, 1, -1};
  RMQ rmq(vec);
  ASSERT_ANY_THROW(rmq.findMin(12, 40));
}