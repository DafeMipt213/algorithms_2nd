
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
   Vertex v0(0);
   Vertex v1(1);
   Vertex v2(2);
   Vertex v3(3);
   AddEdge(&v1, &v0);
   AddEdge(&v2, &v0);
   AddEdge(&v3, &v0);

    Graph graph;
    graph.AddRoot(&v1);
    graph.AddRoot(&v2);
    graph.AddRoot(&v3);

    std::vector<int> answer = {1, 0, 2, 3};
    ASSERT_EQ(graph.TopologySort(), answer); 
}
