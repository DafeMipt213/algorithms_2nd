#include <gtest/gtest.h>

#include "bridges_and_joints.hpp"

TEST(BridgesAndJoints, EmptyResult) {
  std::map<int, std::vector<int>> graph = {
      {0, {1, 2, 3}}, {1, {0, 1, 2, 3}}, {2, {0, 1, 2, 3}}, {3, {0, 1, 2, 3}}};
  BridgesAndJoints<int> result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, Simple) {
  std::map<int, std::vector<int>> graph = {{0, {2}}, {1, {2}}, {2, {0, 1}}};
  BridgesAndJoints<int> result;
  result.bridges = {{2, 1}, {0, 2}};
  result.joints = {2};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, GraphWithCycle) {
  std::map<int, std::vector<int>> graph = {
      {0, {3}}, {1, {0}}, {2, {1}}, {3, {2}}, {4, {3}}};
  BridgesAndJoints<int> result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, Cycle) {
  std::map<int, std::vector<int>> graph = {{0, {1}}, {1, {2}},    {2, {3}},
                                           {3, {4}}, {4, {0, 5}}, {5, {}}};
  BridgesAndJoints<int> result;
  result.bridges = {{4, 5}};
  result.joints = {4};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, SeaStar) {
  std::map<int, std::vector<int>> graph = {
      {0, {1, 2, 3, 4, 5}}, {1, {}}, {2, {}}, {3, {}}, {4, {}}, {5, {}}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  result.joints = {0};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, TwoCommponents) {
  std::map<int, std::vector<int>> graph = {{0, {1}}, {1, {2, 0}}, {2, {1}},
                                           {3, {4}}, {4, {3, 5}}, {5, {4}}};
  BridgesAndJoints result;
  result.bridges = {{1, 2}, {0, 1}, {4, 5}, {3, 4}};
  result.joints = {1, 4};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, EmptyGraph) {
  std::map<int, std::vector<int>> graph = {};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, SpiderGraph) {
  std::map<int, std::vector<int>> graph = {{0, {1, 2, 3}}, {1, {0}}, {2, {0}},
                                           {3, {0, 4, 5}}, {4, {3}}, {5, {3}}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}, {0, 2}, {3, 4}, {3, 5}, {0, 3}};
  result.joints = {3, 0};
  BridgesAndJoints res1 = Search(graph);
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, OnlySimpleCycle) {
  std::map<int, std::vector<int>> graph = {{0, {0}}, {1, {1}}, {2, {2}}};
  BridgesAndJoints result;
  result.bridges = {{1, 2}, {0, 1}, {4, 5}, {3, 4}};
  result.joints = {4, 1};
  result = Search(graph);
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, NoBridgesNoJoints) {
  std::map<int, std::vector<int>> graph = {{0, {0}}, {1, {1}}, {2, {2}}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, OneBridgeNoJoints) {
  std::map<int, std::vector<int>> graph = {{0, {1}}, {1, {0}}};
  BridgesAndJoints result;
  result.bridges = {{0, 1}};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, MultipleBridgesAndJoints) {
  std::map<int, std::vector<int>> graph = {{0, {}},
                                           {1, {2, 3, 4, 5, 9, 10}},
                                           {2, {1, 3, 6, 8}},
                                           {3, {1, 2, 8, 9}},
                                           {4, {1, 6, 7, 8, 9, 10}},
                                           {5, {1}},
                                           {6, {2, 4, 7, 9}},
                                           {7, {4, 6, 8}},
                                           {8, {2, 3, 4, 7, 9}},
                                           {9, {1, 3, 4, 6, 8}},
                                           {10, {1, 4}}};
  BridgesAndJoints result;
  result.bridges = {{5, 1}};
  result.joints = {1};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, FishGraph) {
  std::map<int, std::vector<int>> graph = {{0, {1, 2, 3}}, {1, {0, 2, 3}},
                                           {2, {0, 1, 3}}, {3, {0, 1, 2, 4, 5}},
                                           {4, {3, 5}},    {5, {3, 4}}};
  BridgesAndJoints result;
  result.joints = {3};
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, ComplexGraphFirst) {
  std::map<int, std::vector<int>> graph = {{0, {1, 2}},       {1, {0, 2, 3, 4}},
                                           {2, {0, 1, 4}},    {3, {1, 4, 5}},
                                           {4, {1, 2, 3, 5}}, {5, {3, 4}}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}

TEST(BridgesAndJoints, ComplexGraphSecond) {
  std::map<int, std::vector<int>> graph = {
      {0, {1, 2, 3, 4}},    {1, {0, 2, 3, 4}},    {2, {0, 1, 3, 4}},
      {3, {0, 1, 2, 4, 5}}, {4, {0, 1, 2, 3, 5}}, {5, {3, 4}}};
  BridgesAndJoints result;
  ASSERT_EQ(Search(graph), result);
}