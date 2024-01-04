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