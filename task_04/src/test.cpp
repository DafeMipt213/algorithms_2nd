#include <gtest/gtest.h>

#include "dijkstra.hpp"

TEST(Dijkstra, Simple) {
  Graph g(5);
  g.AddEdge(0, 1, 2);
  g.AddEdge(0, 3, 3);
  g.AddEdge(0, 4, 1);
  g.AddEdge(0, 2, 3);
  g.AddEdge(4, 3, 1);
  g.AddEdge(1, 3, 1);

  std::vector<int> vec_distances_expected = {0, 2, 3, 2, 1};
  g.Dijkstra(1);
  std::vector<int> vec_distances = g.Dijkstra(0);

  ASSERT_EQ(vec_distances, vec_distances_expected);
}
