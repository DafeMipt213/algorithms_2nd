
#include <gtest/gtest.h>

#include "AllFunc.hpp"
#include "FindBridges.hpp"
#include "FindCutPoints.hpp"

TEST(Bridges_and_CutPoints, Simple_Bridges) {
  std::vector<std::vector<int> > graph = {{0, 1}, {1, 0}};
  std::set<std::pair<int, int> > result;
  std::set<int> cpvector;
  AllFunc(graph, result, cpvector);
  std::set<std::pair<int, int> > k = {{0, 1}};
  ASSERT_EQ(returnBridges(result), k);
}

TEST(Bridges_and_CutPoints, Simple_CutPoints) {
  std::vector<std::vector<int> > graph = {{0, 1}, {1, 0}};
  std::set<std::pair<int, int> > result;
  std::set<int> cpvector;
  AllFunc(graph, result, cpvector);
  std::set<int> k = {};
  ASSERT_EQ(returnCP(cpvector), k);
}

TEST(Bridges_and_CutPoints, Harder_Bridges) {
  std::vector<std::vector<int> > graph = {{1, 2},    {0, 2, 3}, {0, 1},
                                          {1, 4, 5}, {3, 5},    {3, 4}};
  std::set<std::pair<int, int> > result;
  std::set<int> cpvector;
  AllFunc(graph, result, cpvector);
  std::set<std::pair<int, int> > k = {{1, 3}};
  ASSERT_EQ(returnBridges(result), k);
}

TEST(Bridges_and_CutPoints, Harder_CutPoints_ale) {
  std::vector<std::vector<int> > graph = {{1, 2},    {0, 2, 3}, {0, 1},
                                          {1, 4, 5}, {3, 5},    {3, 4}};
  std::vector<int> tin(graph.size());
  std::vector<int> fup(graph.size());
  std::vector<bool> used(graph.size());
  int tm = 0;
  std::set<std::pair<int, int> > result;
  std::set<int> cpvector;
  FindCutPoint(tm, 0, graph, tin, fup, -1, cpvector, used);
  std::set<int> k = {1, 3};
  ASSERT_EQ(returnCP(cpvector), k);
}

TEST(Bridges_and_CutPoints, Most_hard_Bridges) {
  std::vector<std::vector<int> > graph = {
      {1, 3}, {0, 2, 3}, {1, 3}, {0, 1, 2, 4, 5, 6}, {3, 5}, {3, 4, 6}, {3, 5}};
  std::set<std::pair<int, int> > result;
  std::set<int> cpvector;
  AllFunc(graph, result, cpvector);
  std::set<std::pair<int, int> > k = {};
  ASSERT_EQ(returnBridges(result), k);
}

TEST(Bridges_and_CutPoints, Most_hard_CutPoints) {
  std::vector<std::vector<int> > graph = {
      {1, 3}, {0, 2, 3}, {1, 3}, {0, 1, 2, 4, 5, 6}, {3, 5}, {3, 4, 6}, {3, 5}};
  std::vector<int> tin(graph.size());
  std::vector<int> fup(graph.size());
  std::vector<bool> used(graph.size());
  int tm = 0;
  std::set<std::pair<int, int> > result;
  std::set<int> cpvector;
  FindCutPoint(tm, 0, graph, tin, fup, -1, cpvector, used);
  std::set<int> k = {3};
  ASSERT_EQ(returnCP(cpvector), k);
}
