
#include <gtest/gtest.h>

#include <utility>

#include "bridges_and_cutpoints.hpp"

TEST(CutPointsAndBridges, SimpleBridges) {
  std::vector<std::vector<int>> graph = {{1, 2}, {3, 5},       {0, 4, 5}, {1},
                                         {2, 5}, {1, 2, 4, 6}, {5, 7},    {6}};
  std::set<std::pair<int, int>> bridges = findBridges(graph);
  std::set<std::pair<int, int>> bridges_ans;
  bridges_ans.insert(std::pair(3, 1));
  bridges_ans.insert(std::pair(6, 5));
  bridges_ans.insert(std::pair(7, 6));
  ASSERT_EQ(bridges, bridges_ans);
}

TEST(CutPointsAndBridges, SimpleCutPoints) {
  std::vector<std::vector<int>> graph = {{1, 2}, {3, 5},       {0, 4, 5}, {1},
                                         {2, 5}, {1, 2, 4, 6}, {5, 7},    {6}};
  std::set<int> cutpoints = findCutPoints(graph);
  std::set<int> cutpoints_ans;
  cutpoints_ans.insert(1);
  cutpoints_ans.insert(5);
  cutpoints_ans.insert(6);
  ASSERT_EQ(cutpoints, cutpoints_ans);
}

TEST(CutPointsAndBridges, LoopCutpoints) {
  std::vector<std::vector<int>> graph = {{1, 2, 0}, {3, 5, 1}, {0, 4, 5, 2},
                                         {1, 3},    {2, 5},    {1, 2, 4, 6},
                                         {5, 7},    {6}};
  std::set<int> cutpoints = findCutPoints(graph);
  std::set<int> cutpoints_ans;
  cutpoints_ans.insert(1);
  cutpoints_ans.insert(5);
  cutpoints_ans.insert(6);
  ASSERT_EQ(cutpoints, cutpoints_ans);
}

TEST(CutPointsAndBridges, LoopBridges) {
  std::vector<std::vector<int>> graph = {{1, 2, 0}, {3, 5, 1}, {0, 4, 5, 2},
                                         {1},       {2, 5},    {1, 2, 4, 6},
                                         {5, 7},    {6}};
  std::set<std::pair<int, int>> bridges = findBridges(graph);
  std::set<std::pair<int, int>> bridges_ans;
  bridges_ans.insert(std::pair(3, 1));
  bridges_ans.insert(std::pair(6, 5));
  bridges_ans.insert(std::pair(7, 6));
  ASSERT_EQ(bridges, bridges_ans);
}

TEST(CutPointsAndBridges, EmptyBridges) {
  std::vector<std::vector<int>> graph = {};
  std::set<std::pair<int, int>> bridges = findBridges(graph);
  std::set<std::pair<int, int>> bridges_ans;
  ASSERT_EQ(bridges, bridges_ans);
}

TEST(CutPointsAndBridges, EmptyCutpoints) {
  std::vector<std::vector<int>> graph = {};
  std::set<int> cutpoints = findCutPoints(graph);
  std::set<int> cutpoints_ans;
  ASSERT_EQ(cutpoints, cutpoints_ans);
}

TEST(CutPointsAndBridges, NoCutpoints) {
  std::vector<std::vector<int>> graph = {
      {1, 4, 3}, {0, 4, 2}, {1, 4, 3}, {2, 4, 0}, {0, 1, 2, 3}};
  std::set<int> cutpoints = findCutPoints(graph);
  std::set<int> cutpoints_ans;
  ASSERT_EQ(cutpoints, cutpoints_ans);
}

TEST(CutPointsAndBridges, NoBridges) {
  std::vector<std::vector<int>> graph = {
      {1, 4, 3}, {0, 4, 2}, {1, 4, 3}, {2, 4, 0}, {0, 1, 2, 3}};
  std::set<std::pair<int, int>> bridges = findBridges(graph);
  std::set<std::pair<int, int>> bridges_ans;
  ASSERT_EQ(bridges, bridges_ans);
}

TEST(CutPointsAndBridges, ComplexBridges) {
  std::vector<std::vector<int>> graph = {{1, 2},    {0, 2}, {1, 0, 3},
                                         {2, 4, 5}, {3, 5}, {3, 4, 6},
                                         {5, 7, 8}, {6, 8}, {7, 6}};
  std::set<std::pair<int, int>> bridges = findBridges(graph);
  std::set<std::pair<int, int>> bridges_ans;
  bridges_ans.insert(std::pair(3, 2));
  bridges_ans.insert(std::pair(6, 5));
  ASSERT_EQ(bridges, bridges_ans);
}

TEST(CutPointsAndBridges, ComplexCutPoints) {
  std::vector<std::vector<int>> graph = {{1, 2},    {0, 2}, {1, 0, 3},
                                         {2, 4, 5}, {3, 5}, {3, 4, 6},
                                         {5, 7, 8}, {6, 8}, {7, 6}};
  std::set<int> cutpoints = findCutPoints(graph);
  std::set<int> cutpoints_ans;
  cutpoints_ans.insert(2);
  cutpoints_ans.insert(3);
  cutpoints_ans.insert(5);
  cutpoints_ans.insert(6);
  ASSERT_EQ(cutpoints, cutpoints_ans);
}
