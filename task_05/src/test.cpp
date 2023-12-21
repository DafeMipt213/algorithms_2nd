
#include <gtest/gtest.h>

#include "RMQ.hpp"

TEST(RMQ, Simple) {
  std::vector<int> data{1, 2, 3};
  SolveRMQ solver(data);
  ASSERT_EQ(solver.GitMinimum(0, 2), 1);
  ASSERT_EQ(solver.GitMinimum(0, 1), 1);
  ASSERT_EQ(solver.GitMinimum(1, 2), 2);
  ASSERT_EQ(solver.GitMinimum(1, 1), 2);
  ASSERT_EQ(solver.GitMinimum(0, 0), 1);
  ASSERT_EQ(solver.GitMinimum(1, 1), 2);
  ASSERT_EQ(solver.GitMinimum(2, 2), 3);
}

TEST(RMQ, Middle1) {
  std::vector<int> data{2, 9, 15, -3, 8};
  SolveRMQ solver(data);
  ASSERT_EQ(solver.GitMinimum(1, 3), -3);
  ASSERT_EQ(solver.GitMinimum(0, 1), 2);
  ASSERT_EQ(solver.GitMinimum(0, 2), 2);
  ASSERT_EQ(solver.GitMinimum(3, 5), -3);
  ASSERT_EQ(solver.GitMinimum(4, 5), 8);
  ASSERT_EQ(solver.GitMinimum(4, 4), 8);
  ASSERT_EQ(solver.GitMinimum(2, 2), 15);
  ASSERT_EQ(solver.GitMinimum(2, 3), -3);
}

TEST(RMQ, Middle2) {
  std::vector<int> data{4, 6, 13, 98, -1, 0, 0, 0};
  SolveRMQ solver(data);
  ASSERT_EQ(solver.GitMinimum(1, 3), 6);
  ASSERT_EQ(solver.GitMinimum(0, 7), -1);
  ASSERT_EQ(solver.GitMinimum(2, 5), -1);
  ASSERT_EQ(solver.GitMinimum(0, 5), -1);
}

TEST(RMQ, Middle3) {
  std::vector<int> data{4, 6, 13, 98, -1, 0, 0, 0, -3, 10};
  SolveRMQ solver(data);
  ASSERT_EQ(solver.GitMinimum(1, 3), 6);
  ASSERT_EQ(solver.GitMinimum(4, 9), -3);
}

TEST(RMQ, Middle4) {
  std::vector<int> data{1, -1, 2, -3, 7, 90};
  SolveRMQ solver(data);
  ASSERT_EQ(solver.GitMinimum(0, 3), -3);
  ASSERT_EQ(solver.GitMinimum(2, 5), -3);
}
