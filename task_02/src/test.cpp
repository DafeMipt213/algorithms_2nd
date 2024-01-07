
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

TEST(Task, AnotherGraph) {
  Graph graph;
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.CalculateSolution();
  std::vector<std::pair<int, int>> connections{{3, 4}};
  std::vector<int> routers{3};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}

TEST(Task, YetAnotherGraph) {
  Graph graph;
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(2, 5);
  graph.AddEdge(3, 6);
  graph.AddEdge(4, 7);
  graph.CalculateSolution();
  std::vector<std::pair<int, int>> connections{{2, 5}, {1, 2}, {3, 6},
                                               {1, 3}, {4, 7}, {1, 4}};
  std::vector<int> routers{2, 3, 4, 1};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}

TEST(Task, AnotherGraphTest) {
  Graph graph;
  graph.AddEdge(5, 6);
  graph.AddEdge(5, 7);
  graph.AddEdge(6, 8);
  graph.AddEdge(7, 9);
  graph.AddEdge(8, 10);
  graph.CalculateSolution();
  std::vector<std::pair<int, int>> connections{
      {8, 10}, {6, 8}, {5, 6}, {7, 9}, {5, 7}};
  std::vector<int> routers{8, 6, 7, 5};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}

TEST(Task, HandGraph) {
  Graph graph;
  graph.SetAdjacencyMap({{0, {1, 6, 2}},
                         {1, {0, 3, 5, 6}},
                         {2, {0, 6, 7}},
                         {3, {4, 5, 1}},
                         {4, {3, 5}},
                         {5, {3, 4, 1}},
                         {6, {0, 1, 2, 7, 9}},
                         {7, {2, 6, 11}},
                         {8, {9, 10}},
                         {9, {6, 8, 10, 11}},
                         {10, {8, 9, 11}},
                         {11, {7, 9, 10}}});
  graph.CalculateSolution();
  std::vector<std::pair<int, int>> connections{};
  std::vector<int> routers{1};

  ASSERT_EQ(graph.GetConnections(), connections);
  ASSERT_EQ(graph.GetRouters(), routers);
}