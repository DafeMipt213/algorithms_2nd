#include <gtest/gtest.h>

#include "dijkstra.hpp"

TEST(DijkstraAlgorithm, GraphFromDicreteMath) {
  Graph graph;
  graph.AddEdge(1, 8, 10);
  graph.AddEdge(1, 2, 1);
  graph.AddEdge(2, 3, 2);
  graph.AddEdge(2, 10, 6);
  graph.AddEdge(3, 10, 3);
  graph.AddEdge(4, 3, 4);
  graph.AddEdge(4, 2, 10);
  graph.AddEdge(5, 4, 1);
  graph.AddEdge(5, 9, 1);
  graph.AddEdge(6, 5, 2);
  graph.AddEdge(6, 9, 4);
  graph.AddEdge(7, 6, 1);
  graph.AddEdge(7, 9, 5);
  graph.AddEdge(8, 7, 2);
  graph.AddEdge(9, 8, 4);
  graph.AddEdge(9, 4, 3);
  graph.AddEdge(10, 8, 3);
  graph.AddEdge(10, 1, 1);
  graph.AddEdge(10, 9, 10);

  std::map<int, unsigned long long> result{{1, 0},  {2, 1},  {3, 3},  {4, 15},
                                           {5, 14}, {6, 12}, {7, 11}, {8, 9},
                                           {9, 15}, {10, 6}};
  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, AnotherGraphTest) {
  Graph graph;
  graph.AddEdge(1, 2, 1);
  graph.AddEdge(1, 3, 3);
  graph.AddEdge(2, 3, 1);
  graph.AddEdge(2, 4, 3);
  graph.AddEdge(3, 4, 1);
  graph.AddEdge(3, 5, 5);
  graph.AddEdge(4, 5, 2);
  graph.AddEdge(5, 6, 1);
  graph.AddEdge(6, 7, 1);
  graph.AddEdge(7, 8, 1);
  graph.AddEdge(8, 9, 1);
  graph.AddEdge(9, 10, 1);

  std::map<int, unsigned long long> result{{1, 0}, {2, 1},  {3, 2}, {4, 3},
                                           {5, 5}, {6, 6},  {7, 7}, {8, 8},
                                           {9, 9}, {10, 10}};
  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, SmallGraphTest) {
  Graph graph;
  graph.AddEdge(1, 2, 1);
  graph.AddEdge(2, 3, 2);
  graph.AddEdge(3, 1, 3);

  std::map<int, unsigned long long> result{{1, 0}, {2, 1}, {3, 3}};
  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, MiddleSizedGraphTest) {
  Graph graph;
  graph.AddEdge(1, 2, 1);
  graph.AddEdge(1, 3, 5);
  graph.AddEdge(2, 3, 2);
  graph.AddEdge(2, 4, 1);
  graph.AddEdge(3, 5, 3);
  graph.AddEdge(4, 6, 4);
  graph.AddEdge(5, 6, 1);

  std::map<int, unsigned long long> result{{1, 0}, {2, 1}, {3, 3},
                                           {4, 2}, {5, 6}, {6, 6}};
  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, AnotherMiddleSizedGraphTest) {
  Graph graph;
  graph.AddEdge(1, 2, 2);
  graph.AddEdge(1, 3, 3);
  graph.AddEdge(2, 4, 1);
  graph.AddEdge(3, 5, 2);
  graph.AddEdge(4, 6, 3);
  graph.AddEdge(5, 6, 1);

  std::map<int, unsigned long long> result{{1, 0}, {2, 2}, {3, 3},
                                           {4, 3}, {5, 5}, {6, 6}};
  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, StartFromNode1) {
  Graph graph;
  graph.AddEdge(1, 2, 2);
  graph.AddEdge(1, 3, 3);
  graph.AddEdge(2, 4, 1);
  graph.AddEdge(3, 5, 2);
  graph.AddEdge(4, 6, 3);
  graph.AddEdge(5, 6, 1);

  std::map<int, unsigned long long> result{{1, 0}, {2, 2}, {3, 3},
                                           {4, 3}, {5, 5}, {6, 6}};
  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, StartFromNode2) {
  Graph graph;
  graph.AddEdge(1, 2, 2);
  graph.AddEdge(1, 3, 3);
  graph.AddEdge(2, 1, 2);
  graph.AddEdge(2, 4, 1);
  graph.AddEdge(3, 5, 2);
  graph.AddEdge(4, 6, 3);
  graph.AddEdge(5, 6, 1);

  std::map<int, unsigned long long> result{{1, 2}, {2, 0}, {3, 5},
                                           {4, 1}, {5, 7}, {6, 4}};
  ASSERT_EQ(graph.Dijkstra(2), result);
}

TEST(DijkstraAlgorithm, FullyConnectedGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 3);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(2, 4, 2);
  graph.AddEdge(2, 5, 3);
  graph.AddEdge(3, 6, 1);
  graph.AddEdge(4, 7, 4);
  graph.AddEdge(5, 7, 1);
  graph.AddEdge(6, 7, 5);
  graph.AddEdge(3, 1, 2);
  graph.AddEdge(4, 2, 1);
  graph.AddEdge(5, 4, 2);
  graph.AddEdge(6, 3, 1);
  graph.AddEdge(7, 6, 2);

  std::map<int, unsigned long long> result = {{1, 0}, {2, 3}, {3, 7}, {4, 5},
                                              {5, 6}, {6, 8}, {7, 7}};

  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, ComplexGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 3);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(2, 4, 2);
  graph.AddEdge(2, 5, 3);
  graph.AddEdge(3, 6, 1);
  graph.AddEdge(4, 7, 4);
  graph.AddEdge(5, 7, 1);
  graph.AddEdge(6, 7, 5);
  std::map<int, unsigned long long> result = {{1, 0}, {2, 3}, {3, 7}, {4, 5},
                                              {5, 6}, {6, 8}, {7, 7}};

  ASSERT_EQ(graph.Dijkstra(1), result);
}

TEST(DijkstraAlgorithm, AnotherGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 4);
  graph.AddEdge(1, 3, 1);
  graph.AddEdge(2, 3, 2);
  graph.AddEdge(2, 4, 5);
  graph.AddEdge(3, 4, 8);
  graph.AddEdge(4, 1, 1);

  std::map<int, unsigned long long> result{{1, 0}, {2, 4}, {3, 1}, {4, 9}};

  ASSERT_EQ(graph.Dijkstra(1), result);
}