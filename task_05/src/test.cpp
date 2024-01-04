#include <gtest/gtest.h>
#include <vector>
#include "rmq.hpp"

TEST(RMQ, HabrTest) {
  std::vector<int> v {3, 8, 6, 4, 2, 5, 9, 0, 7, 1};
  RMQ rmq;
  rmq.build_tree(v);

  int ans1 = rmq.find_ans(0, 0);
  int correct_ans1 = 3;
  
  int ans2 = rmq.find_ans(0, 9);
  int correct_ans2 = 0;
  
  int ans3 = rmq.find_ans(8, 9);
  int correct_ans3 = 1;

  int ans4 = rmq.find_ans(3, 5);
  int correct_ans4 = 2;

  int ans5 = rmq.find_ans(4, 5);
  int correct_ans5 = 2;

  ASSERT_EQ(correct_ans1, ans1);
  ASSERT_EQ(correct_ans2, ans2);
  ASSERT_EQ(correct_ans3, ans3);
  ASSERT_EQ(correct_ans4, ans4);
  ASSERT_EQ(correct_ans5, ans5);
}

TEST(RMQ, EasyTest) {
  std::vector<int> v {3, 7, 2, 5};
  RMQ rmq;
  rmq.build_tree(v);

  int ans = rmq.find_ans(0, 2);
  int correct_ans = 2;

  ASSERT_EQ(correct_ans, ans);
}