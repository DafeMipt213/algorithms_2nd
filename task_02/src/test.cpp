#include <gtest/gtest.h>

#include "bridges_and_joints.hpp"

TEST(BridgesAndJoints, EmptyResult) {
  std::vector<std::vector<int>> graph = {
      {1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, Simple) {
  std::vector<std::vector<int>> graph = {{2}, {2}, {0, 1}};
  BridgesAndJoints result;
  result.bridges = {{2, 1}, {0, 2}};
  result.joints = {2};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, GraphWithCycle) {
  std::vector<std::vector<int>> graph = {{3}, {0}, {1}, {2}, {3}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, Cycle) {
  std::vector<std::vector<int>> graph = {{1}, {2}, {3}, {4}, {0, 5}, {}};
  BridgesAndJoints result;
  result.bridges = {{4, 5}};
  result.joints = {4};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, SeaStar) {
  std::vector<std::vector<int>> graph = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  result.joints = {0};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, TwoCommponents) {
  std::vector<std::vector<int>> graph = {{1}, {2, 0}, {1}, {4}, {3, 5}, {4}};
  BridgesAndJoints result;
  result.bridges = {{1, 2}, {0, 1}, {4, 5}, {3, 4}};
  result.joints = {1, 4};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, EmptyGraph) {
  std::vector<std::vector<int>> graph = {{}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, SpiderGraph) {
  std::vector<std::vector<int>> graph = {{1, 2, 3}, {0}, {0},
                                         {0, 4, 5}, {3}, {3}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}, {0, 2}, {3, 4}, {3, 5}, {0, 3}};
  result.joints = {3, 0};
  BridgesAndJoints res1 = Search(graph);
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, OnlySimpleCycle) {
  std::vector<std::vector<int>> graph = {{0}, {1}, {2}};
  BridgesAndJoints result;
  result.bridges = {{1, 2}, {0, 1}, {4, 5}, {3, 4}};
  result.joints = {4, 1};
  result = Search(graph);
  ASSERT_EQ(Search(graph), result);
}
TEST(BridgesAndJoints, NoBridgesNoJoints) {
  std::vector<std::vector<int>> graph = {{0}, {1}, {2}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, OneBridgeNoJoints) {
  std::vector<std::vector<int>> graph = {{1}, {0}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, MultipleBridgesAndJoints) {
  std::vector<std::vector<int>> graph = {{},
                                         {2, 3, 4, 5, 9, 10},
                                         {1, 3, 6, 8},
                                         {1, 2, 8, 9},
                                         {1, 6, 7, 8, 9, 10},
                                         {1},
                                         {2, 4, 7, 9},
                                         {4, 6, 8},
                                         {2, 3, 4, 7, 9},
                                         {1, 3, 4, 6, 8},
                                         {1, 4}};
  BridgesAndJoints result;
  result.bridges = {{5, 1}};
  result.joints = {1};
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, FishGraph) {
  std::vector<std::vector<int>> graph = {{1, 2, 3},       {0, 2, 3}, {0, 1, 3},
                                         {0, 1, 2, 4, 5}, {3, 5},    {3, 4}};
  BridgesAndJoints result;
  result.joints = {3};
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, ComplexGraphFirst) {
  std::vector<std::vector<int>> graph = {{1, 2},    {0, 2, 3, 4}, {0, 1, 4},
                                         {1, 4, 5}, {1, 2, 3, 5}, {3, 4}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(bridges_and_joints, ComplexGraphSecond) {
  std::vector<std::vector<int>> graph = {{1, 2, 3, 4},    {0, 2, 3, 4},
                                         {0, 1, 3, 4},    {0, 1, 2, 4, 5},
                                         {0, 1, 2, 3, 5}, {3, 4}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}