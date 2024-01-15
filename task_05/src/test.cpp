#include <gtest/gtest.h>

#include "RMQ.hpp"

TEST(RMQ, Medium1) {
  std::vector<int> data{4, 9, 15, -3, 7};
  RMQ solver(data);
  ASSERT_EQ(solver.Run(1, 3), -3);
  ASSERT_EQ(solver.Run(3, 5), -3);
  ASSERT_EQ(solver.Run(2, 2), 15);
  ASSERT_EQ(solver.Run(2, 3), -3);
  ASSERT_EQ(solver.Run(0, 1), 4);
  ASSERT_EQ(solver.Run(0, 2), 4);
}

TEST(RMQ, Medium2) {
  std::vector<int> data{2, 4, 0, 0, 0, 0, 11, 18, -1};
  RMQ solver(data);
  ASSERT_EQ(solver.Run(1, 3), 0);
  ASSERT_EQ(solver.Run(0, 1), 2);
  ASSERT_EQ(solver.Run(0, 7), 0);
  ASSERT_EQ(solver.Run(2, 5), 0);
  ASSERT_EQ(solver.Run(5, 8), -1);
  ASSERT_EQ(solver.Run(6, 7), 11);
}