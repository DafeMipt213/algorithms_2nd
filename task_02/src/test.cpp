#include <gtest/gtest.h>

#include "bridges_and_joints.hpp"

TEST(bridges_and_joints, EmptyResult) {
  std::vector<std::vector<int>> graph = {
      {1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, Simple) {
  std::vector<std::vector<int>> graph = {{2}, {2}, {0, 1}};
  BridgesAndJoints result;
  result.bridges = {{2, 1}, {0, 2}};
  result.joints = {2};
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, GraphWithCycle) {
  std::vector<std::vector<int>> graph = {{3}, {0}, {1}, {2}, {3}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, Cycle) {
  std::vector<std::vector<int>> graph = {{1}, {2}, {3}, {4}, {0, 5}, {}};
  BridgesAndJoints result;
  result.bridges = {{4, 5}};
  result.joints = {4};
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, SeaStar) {
  std::vector<std::vector<int>> graph = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  result.joints = {0};
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, TwoCommponents) {
  std::vector<std::vector<int>> graph = {{1}, {2, 0}, {1}, {4}, {3, 5}, {4}};
  BridgesAndJoints result;
  result.bridges = {{1, 2}, {0, 1}, {4, 5}, {3, 4}};
  result.joints = {1, 4};
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, EmptyGraph) {
  std::vector<std::vector<int>> graph = {{}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, SpiderGraph) {
  std::vector<std::vector<int>> graph = {{1, 2, 3}, {0}, {0},
                                         {0, 4, 5}, {3}, {3}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}, {0, 2}, {3, 4}, {3, 5}, {0, 3}};
  result.joints = {3, 0};
  BridgesAndJoints res1 = Search(graph);
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, OnlySimpleCycles) {
  std::vector<std::vector<int>> graph = {{0}, {1}, {2}};
  BridgesAndJoints result;
  result.bridges = {{1, 2}, {0, 1}, {4, 5}, {3, 4}};
  result.joints = {4, 1};
  result = Search(graph);
  ASSERT_EQ(Search(graph), result);
}