
#include <gtest/gtest.h>
#include "graph.hpp"
#include <iostream>

TEST(Routers, Simple) {
  Graph g(6);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 0);
  g.AddEdge(2, 3);
  g.AddEdge(3, 4);
  g.AddEdge(4, 5);
  g.AddEdge(5, 3);
  std::vector<size_t> answer = {3, 2};
  ASSERT_EQ(FindRouters(g), answer);  // Stack []
}

TEST(Bridges, Simple) {
  Graph g(6);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 0);
  g.AddEdge(2, 3);
  g.AddEdge(3, 4);
  g.AddEdge(4, 5);
  g.AddEdge(5, 3);
  std::vector<std::pair<size_t, size_t>>  answer = {std::pair<size_t, size_t>{2, 3}};
  ASSERT_EQ(FindWires(g), answer);  // Stack []
}