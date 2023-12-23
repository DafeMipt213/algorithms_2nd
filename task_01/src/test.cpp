
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  std::vector<std::vector<int>> input = {{1, 2}, {0, 3}, {3, 4}, {}, {}};
  Graph graph(input);
  std::vector<int> res = {0, 2, 4, 1, 3};
  ASSERT_EQ(graph.topologySort(0), res);
}
TEST(TopologySort, Cycle) {
  std::vector<std::vector<int>> input = {{1, 2}, {0, 3}, {3, 4}, {}, {0}};
  Graph graph(input);
  std::vector<int> res = {0, 2, 4, 1, 3};
  ASSERT_EQ(graph.topologySort(0), res);
}
TEST(TopologySort, Hard) {
  std::vector<std::vector<int>> input = {{1, 2}, {2, 3, 4, 5, 6, 8}, {3}, {}, {5}, {}, {7}, {1}, {0}};
  Graph graph(input);
  std::vector<int> res = {0, 1, 8, 6, 7, 4, 5, 2, 3};
  ASSERT_EQ(graph.topologySort(0), res);
}
TEST(TopologySort, Comlex) {
  std::vector<std::vector<int>> input = {{1, 2}, {3}, {3, 4}, {1, 4}, {0}, {}, {7, 8}, {10}, {9, 10}, {6, 11}, {7}, {}, {9, 10, 11}};
  Graph graph(input);
  std::vector<int> res = {5, 12, 9, 11, 6, 8, 7, 10, 0, 2, 1, 3, 4};
  ASSERT_EQ(graph.topologySort(0), res);
}

TEST(TopologySort, Empty) {
  std::vector<std::vector<int>> input = {{0}};
  Graph graph(input);
  std::vector<int> res = {0};
  ASSERT_EQ(graph.topologySort(0), res);
}

TEST(TopologySort, FullGraphLoops) {
  std::vector<std::vector<int>> input = {{0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}};
  Graph graph(input);
  std::vector<int> res = {0, 1, 2, 3, 4};
  ASSERT_EQ(graph.topologySort(0), res);
}

TEST(TopologySort, FullGraphNoLoops) {
  std::vector<std::vector<int>> input = {{1, 2, 3, 4}, {0, 2, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 4}, {0, 1, 2, 3}};
  Graph graph(input);
  std::vector<int> res = {0, 1, 2, 3, 4};
  ASSERT_EQ(graph.topologySort(0), res);
}

TEST(TopologySort, NotConnected_2components) {
  std::vector<std::vector<int>> input = {{1, 2, 3}, {0}, {1}, {2}, {}, {4}};
  Graph graph(input);
  std::vector<int> res = {5, 4, 0, 3, 2, 1};
  ASSERT_EQ(graph.topologySort(0), res);
}

TEST(TopologySort, NotConnected_3components) {
  std::vector<std::vector<int>> input = {{1, 2, 3}, {0}, {1}, {2}, {}, {4}, {7}, {6}};
  Graph graph(input);
  std::vector<int> res = {5, 4, 7, 6, 0, 3, 2, 1};
  ASSERT_EQ(graph.topologySort(0), res);
}

TEST(TopologySort, HugeGraph) {
  std::vector<std::vector<int>> input = {{1, 4}, {0, 2, 3, 4}, {3}, {7}, {3}, {4, 6, 10, 11, 12}, {12}, {8, 5}, {9}, {7, 10}, {11}, {12}, {}};
  Graph graph(input);
  std::vector<int> res = {0, 1, 2, 3, 7, 5, 6, 4, 8, 9, 10, 11, 12};
  ASSERT_EQ(graph.topologySort(0), res);
}