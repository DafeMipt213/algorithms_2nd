#include <gtest/gtest.h>

#include "Johnson.hpp"

TEST(Johnson, Simple) {
  Graph g(5);
  g.AddEdge(0, 3, 3);
  g.AddEdge(0, 1, 5);
  g.AddEdge(4, 1, 1);
  g.AddEdge(1, 2, 2);
  g.AddEdge(2, 3, 6);
  g.AddEdge(3, 4, 4);

  std::vector<std::vector<int>> expected_distances = {{0, 5, 7, 3, 7},
                                                      {INF, 0, 2, 8, 12},
                                                      {INF, 11, 0, 6, 10},
                                                      {INF, 5, 7, 0, 4},
                                                      {INF, 1, 3, 9, 0}};

  std::vector<std::vector<int>> distances = g.Johnson();
  ASSERT_EQ(distances, expected_distances);
}
