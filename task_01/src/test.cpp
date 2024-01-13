
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  std::vector< std::vector<int> > graph = {{2, 5, 4},
                                           {3, 5, 6},
                                           {},
                                           {2}, 
                                           {},
                                           {2, 3, 4},
                                           {3},
                                           {5}};
  std::vector<int> ans = {7, 1, 6, 0, 5, 4, 3, 2};
  ASSERT_EQ(top_sort(graph), ans);
}


TEST(TopologySort, Cycle) {
  std::vector< std::vector<int> > graph = {{1},
                                           {2},
                                           {0, 1, 2},
                                           {}};
  std::vector<int> ans = {3, 0, 1, 2};
  ASSERT_EQ(top_sort(graph), ans);
}

TEST(TopologySort, Empty_graph) {
  std::vector< std::vector<int> > graph = {{0}};
  std::vector<int> ans = {0};
  ASSERT_EQ(top_sort(graph), ans);
}

TEST(TopologySort, Full_graph_with_loops) {
  std::vector< std::vector<int> > graph = {{0, 1, 2}, 
                                           {0, 1, 2}, 
                                           {0, 1, 2}};
  std::vector<int> ans = {0, 1, 2};
  ASSERT_EQ(top_sort(graph), ans);
}

TEST(TopologySort, BIK_graph) {
  std::vector< std::vector<int> > graph = {{1, 2, 3}, 
                                           {5}, 
                                           {5}, 
                                           {4, 5},
                                           {6, 8}, 
                                           {4, 6, 7}, 
                                           {9},
                                           {9}, 
                                           {7, 9},
                                           {}};
  std::vector<int> ans = {0, 3, 2, 1, 5, 4, 8, 7, 6, 9};
  ASSERT_EQ(top_sort(graph), ans);
}

TEST(TopologySort, Isolated_verticles) {
  std::vector<std::vector<int>> graph = {{1, 2, 3}, {0}, {1}, {2}, {}, {4}};
  std::vector<int> res = {5, 4, 0, 3, 2, 1};
  ASSERT_EQ(top_sort(graph), res);
}