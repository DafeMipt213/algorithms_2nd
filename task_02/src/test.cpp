
#include <gtest/gtest.h>

#include "task.hpp"

TEST(Task, ComplexGraph) {
  Graph graph;
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 4);
  graph.AddEdge(2, 5);
  graph.AddEdge(4, 5);
  graph.AddEdge(3, 8);
  graph.AddEdge(3, 9);
  graph.AddEdge(8, 9);
  graph.AddEdge(8, 7);
  graph.AddEdge(9, 6);
  graph.AddEdge(7, 6);

  graph.CalculateSolution();

  std::vector<std::pair<int, int>> connections{{1, 2}, {1, 3}};
  std::vector<int> routers{2, 3, 1};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}

TEST(Task, EmptyGraph) {
  Graph graph;
  graph.CalculateSolution();

  std::vector<std::pair<int, int>> connections{};
  std::vector<int> routers{};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}

TEST(Task, SimpleGraph) {
  Graph<char> graph;
  graph.AddEdge('a', 'b');
  graph.AddEdge('b', 'c');
  graph.CalculateSolution();

  std::vector<std::pair<char, char>> connections{{'b', 'c'}, {'a', 'b'}};
  std::vector<char> routers{'b'};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}

TEST(Task, FullConnectedGraph) {
  Graph graph;
  graph.SetAdjacencyMap({{1, {2, 3, 4, 5}},
                         {2, {1, 3, 4, 5}},
                         {3, {1, 2, 4, 5}},
                         {4, {1, 2, 3, 5}},
                         {5, {1, 2, 3, 4}}});

  graph.CalculateSolution();
  std::vector<std::pair<int, int>> connections{};
  std::vector<int> routers{};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}
