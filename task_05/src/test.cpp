#include <gtest/gtest.h>

#include <iostream>

#include "rmq.hpp"

TEST(RMQ, Simple) {
  std::vector<int> data{7, 9, 8, 6, 1, 4, 5, 2, 3};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(5, 8), 7);
}

TEST(RMQ, Test2) {
  std::vector<int> data{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 5);
  ASSERT_EQ(solution.RMQ(5, 9), 9);
}

TEST(RMQ, Test3) {
  std::vector<int> data{-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 5);
  ASSERT_EQ(solution.RMQ(5, 9), 9);
}

TEST(RMQ, Test4) {
  std::vector<int> data{-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 0);
  ASSERT_EQ(solution.RMQ(5, 9), 5);
}

TEST(RMQ, Test5) {
  std::vector<int> data{-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 4);
  ASSERT_EQ(solution.RMQ(5, 9), 8);
}

TEST(RMQ, Test6) {
  std::vector<int> data{-10, -20, -30, -40, -50};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 4), 4);
}

TEST(RMQ, Test7) {
  std::vector<int> data{-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 4);
  ASSERT_EQ(solution.RMQ(5, 9), 8);
}

TEST(RMQ, YetAnotherTest) {
  std::vector<int> data{81, 16, -20, 82, 45, 47, 46, 91, 51, 6, -28, -24};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(4, 8), 4);
}

TEST(RMQ, Test9) {
  std::vector<int> data{-17, -97, 80, -16, 80, -37, 25, 61, -16, 27, 39, 3, 41};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(3, 13), 1);
}

TEST(RMQ, Test10) {
  std::vector<int> data{-19, 3, -92, -86, 88, -53, -58,
                        -36, 7, 82,  -52, 90, -57, 48};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(3, 7), 3);
}

TEST(RMQ, Test11) {
  std::vector<int> data{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 0);
  ASSERT_EQ(solution.RMQ(5, 9), 5);
}

TEST(RMQ, Test12) {
  std::vector<int> data{100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 5);
  ASSERT_EQ(solution.RMQ(5, 9), 9);
}

TEST(RMQ, Test13) {
  std::vector<int> data{-10, -20, -30, -40, -50, -60, -70, -80, -90, -100};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 5);
  ASSERT_EQ(solution.RMQ(5, 9), 9);
}

TEST(RMQ, Test14) {
  std::vector<int> data{-100, -90, -80, -70, -60, -50, -40, -30, -20, -10};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 0);
  ASSERT_EQ(solution.RMQ(5, 9), 5);
}

TEST(RMQ, Test15) {
  std::vector<int> data{10, -20, 30, -40, 50, -60, 70, -80, 90, -100};
  Solution solution(data);
  ASSERT_EQ(solution.RMQ(0, 5), 5);
  ASSERT_EQ(solution.RMQ(5, 9), 9);
}
