
#include <gtest/gtest.h>
#include "bridges_and_joints.hpp"

TEST(bridges_and_joints, EmptyResult) {
  std::vector<std::vector<int>> graph = {{1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}};
  BridgesAndJoints res;
  res.Bridges = {};
  res.Joints = {};
  ASSERT_EQ(Search(graph), res);  // Stack []
}


TEST(bridges_and_joints, Simple) {
  std::vector<std::vector<int>> graph = {{2}, {2}, {0, 1}};
  BridgesAndJoints res;
  res.Bridges = { {2, 1}, {0, 2}};
  res.Joints = {2};
  ASSERT_EQ(Search(graph), res);  // Stack []
}