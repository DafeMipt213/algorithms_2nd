#include <gtest/gtest.h>

#include "search_bridges_and_vertices.hpp"

TEST(SearchBridgesAndVertices, Bridges) {
  Graph g(6);
  g.AddEdge(0, 1);
  g.AddEdge(2, 0);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(5, 3);
  g.AddEdge(3, 4);
  g.AddEdge(4, 5);

  g.Dfs(1);

  std::vector<size_t> articulation_points_expected = {3, 2};
  std::vector<size_t> articulation_points = g.GetArticulationPoints();

  ASSERT_EQ(articulation_points, articulation_points_expected);
}

TEST(SearchBridgesAndVertices, ArticulationPoints) {
  Graph g(6);
  g.AddEdge(0, 1);
  g.AddEdge(2, 0);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(5, 3);
  g.AddEdge(3, 4);
  g.AddEdge(4, 5);

  g.Dfs(1);
  std::vector<std::pair<size_t, size_t>> bridges_expected = {
      std::pair<size_t, size_t>{2, 3}};
  std::vector<std::pair<size_t, size_t>> bridges = g.GetBridges();

  ASSERT_EQ(bridges, bridges_expected);
}