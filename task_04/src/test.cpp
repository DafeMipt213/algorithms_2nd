#include <gtest/gtest.h>

#include <iostream>

#include "dijkstra.hpp"

void testDijkstra(std::vector<int> example, Graph& TestGraph, int ind1,
                  int ind2, int weight) {
  Dijkstra ans = Dijkstra(TestGraph, ind1, ind2);
  std::vector<size_t> graph_ans = ans.path;
  for (int i = 0; i < graph_ans.size(); ++i)
    ASSERT_EQ(example[i], graph_ans[i]);
  ASSERT_EQ(ans.length, weight);
}

TEST(Dijkstra, Normal1) {
  std::vector<Node> nodes;
  for (int i = 1; i < 6; ++i) nodes.push_back(Node(i));
  nodes.push_back(Node(1, {Edge(6, 14), Edge(3, 9), Edge(2, 7)}));
  nodes.push_back(Node(2, {Edge(1, 7), Edge(4, 15), Edge(3, 10)}));
  nodes.push_back(Node(3, {Edge(1, 9), Edge(2, 10), Edge(4, 11), Edge(6, 2)}));
  nodes.push_back(Node(4, {Edge(5, 6), Edge(3, 11), Edge(2, 15)}));
  nodes.push_back(Node(5, {Edge(6, 9), Edge(4, 6)}));
  nodes.push_back(Node(6, {Edge(1, 14), Edge(5, 9), Edge(3, 2)}));
  Graph TestGraph = Graph(nodes);
  std::vector<int> ans = {1, 3, 6, 5};
  testDijkstra(ans, TestGraph, 1, 5, 20);
}

TEST(Dijkstra, Simple1) {
  std::vector<Node> nodes;
  nodes.push_back(Node(1, {Edge(2, 10)}));
  nodes.push_back(Node(2, {Edge(1, 10)}));
  std::vector<int> ans = {1, 2};
  Graph TestGraph = Graph(nodes);
  testDijkstra(ans, TestGraph, 1, 2, 10);
}

TEST(Dijkstra, Normal2) {
  std::vector<Node> nodes;
  for (int i = 1; i < 6; ++i) nodes.push_back(Node(i, {}));
  Graph TestGraph = Graph(nodes);
  TestGraph.addEdge(1, 2, 10);
  TestGraph.addEdge(1, 5, 100);
  TestGraph.addEdge(1, 4, 30);
  TestGraph.addEdge(2, 3, 50);
  TestGraph.addEdge(3, 5, 10);
  TestGraph.addEdge(4, 5, 60);
  TestGraph.addEdge(4, 3, 20);
  std::vector<int> ans = {1, 4, 3, 5};
  testDijkstra(ans, TestGraph, 1, 5, 60);
}

TEST(Dijkstra, Normal3) {
  std::vector<Node> nodes;
  nodes.push_back(Node(1, {Edge(2, 2), Edge(3, 1)}));
  nodes.push_back(Node(2, {Edge(1, 2), Edge(4, 4), Edge(3, 1), Edge(5, 5)}));
  nodes.push_back(Node(3, {Edge(1, 1), Edge(2, 1), Edge(4, 4), Edge(5, 6)}));
  nodes.push_back(Node(4, {Edge(2, 4), Edge(3, 4), Edge(5, 2), Edge(6, 6)}));
  nodes.push_back(Node(5, {Edge(2, 5), Edge(3, 6), Edge(4, 2), Edge(6, 3)}));
  nodes.push_back(Node(6, {Edge(4, 6), Edge(5, 3)}));
  Graph TestGraph = Graph(nodes);
  std::vector<int> ans = {1, 3, 5, 6};
  std::vector<size_t> graph_ans = Dijkstra(TestGraph, 1, 6).path;
  testDijkstra(ans, TestGraph, 1, 6, 10);
}