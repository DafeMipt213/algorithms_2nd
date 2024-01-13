#include <gtest/gtest.h>

#include <iostream>

#include "topology_sort.hpp"

void testTopSort(std::vector<int> example, std::vector<Node> nodes) {
  Graph TestGraph = Graph(nodes);
  std::vector<size_t> graph_ans = topologySort(TestGraph);
  for (int i = 0; i < graph_ans.size(); ++i)
    ASSERT_EQ(example[i], graph_ans[i]);
}

TEST(TopologySort, Simple1) {
  std::vector<Node> nodes;
  nodes.push_back(Node(1, {2, 4, 5}));
  nodes.push_back(Node(2, {3}));
  nodes.push_back(Node(3, {}));
  nodes.push_back(Node(4, {3}));
  nodes.push_back(Node(5, {3, 4}));
  std::vector<int> ans = {1, 2, 5, 4, 3};
  testTopSort(ans, nodes);
}

TEST(TopologySort, Simple2) {
  std::vector<Node> nodes;
  nodes.push_back(Node(1, {4}));
  nodes.push_back(Node(2, {}));
  nodes.push_back(Node(3, {2}));
  nodes.push_back(Node(4, {2, 3}));
  std::vector<int> ans = {1, 4, 3, 2};
  Graph TestGraph = Graph(nodes);
  testTopSort(ans, nodes);
}

TEST(TopologySort, Simple3) {
  std::vector<Node> nodes;
  nodes.push_back(Node(1, {2, 3}));
  nodes.push_back(Node(2, {4}));
  nodes.push_back(Node(3, {5}));
  nodes.push_back(Node(4, {5, 6}));
  nodes.push_back(Node(5, {}));
  nodes.push_back(Node(6, {}));
  std::vector<int> ans = {1, 2, 3, 4, 5, 6};
  testTopSort(ans, nodes);
}

TEST(TopologySort, Simple5) {
  std::vector<Node> nodes;
  nodes.push_back(Node(1, {}));
  nodes.push_back(Node(2, {}));
  nodes.push_back(Node(3, {}));
  nodes.push_back(Node(4, {}));
  std::vector<int> ans = {4, 3, 2, 1};
  testTopSort(ans, nodes);
}

TEST(TopologySort, Advanced1) {
  std::vector<Node> nodes;
  nodes.push_back(Node(2, {}));
  nodes.push_back(Node(3, {8, 10}));
  nodes.push_back(Node(5, {11}));
  nodes.push_back(Node(7, {8, 11}));
  nodes.push_back(Node(8, {9}));
  nodes.push_back(Node(9, {}));
  nodes.push_back(Node(10, {}));
  nodes.push_back(Node(11, {2, 9, 10}));
  std::vector<int> ans = {7, 5, 3, 11, 8, 2, 10, 9};
  testTopSort(ans, nodes);
}

TEST(TopologySort, Advanced2) {
  std::vector<Node> nodes;
  nodes.push_back(Node(0, {5, 3, 1, 2, 6}));
  nodes.push_back(Node(1, {}));
  nodes.push_back(Node(2, {3}));
  nodes.push_back(Node(3, {5, 4}));
  nodes.push_back(Node(4, {9}));
  nodes.push_back(Node(5, {}));
  nodes.push_back(Node(6, {4, 9}));
  nodes.push_back(Node(7, {6}));
  nodes.push_back(Node(8, {7}));
  nodes.push_back(Node(9, {10, 11, 12}));
  nodes.push_back(Node(10, {}));
  nodes.push_back(Node(11, {12}));
  nodes.push_back(Node(12, {}));
  std::vector<int> ans = {8, 0, 7, 1, 2, 6, 3, 5, 4, 9, 10, 11, 12};

  testTopSort(ans, nodes);
}
