
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph g;
  g.SetQuantity(7, 10);
  g.InsertEdge(1, 2, true);
  g.InsertEdge(1, 3, true);
  g.InsertEdge(2, 3, true);
  g.InsertEdge(7, 1, true);
  g.InsertEdge(2, 4, true);
  g.InsertEdge(2, 3, true);
  g.InsertEdge(3, 6, true);
  g.InsertEdge(7, 6, true);
  g.InsertEdge(6, 5, true);
  g.InsertEdge(5, 4, true);

  std::vector<int> vec_vertex_expected = {7, 1, 2, 3, 6, 5, 4};
  std::vector<int> vec_vertex = g.TopSort();

  ASSERT_EQ(vec_vertex, vec_vertex_expected);
}
