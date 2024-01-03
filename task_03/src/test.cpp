#include <gtest/gtest.h>
#include "algo.hpp"

#define INF std::numeric_limits<int>::max()

TEST(JohnsonTest, Simple) {
    Graph graph(5);
    graph.AddEdge(0, 1, 5);  // Add an edge from vertex 0 to vertex 1 with weight 5
    graph.AddEdge(0, 3, 3);  // Add an edge from vertex 0 to vertex 3 with weight 3
    graph.AddEdge(1, 2, 2);  // Add an edge from vertex 1 to vertex 2 with weight 2
    graph.AddEdge(2, 3, 6);  // Add an edge from vertex 2 to vertex 3 with weight 6
    graph.AddEdge(3, 4, 4); // Add an edge from vertex 3 to vertex 4 with weight 4
    graph.AddEdge(4, 1, 1);  // Add an edge from vertex 4 to vertex 1 with weight 1

    std::vector<std::vector<int>> expected_distances = {
        {0, 5, 7, 3, 7},
        {INF, 0, 2, 8, 12},
        {INF, 11, 0, 6, 10},
        {INF, 5, 7, 0, 4},
        {INF, 1, 3, 9, 0}
    };

    std::vector<std::vector<int>> distances = graph.JohnsonsAlgorithm();
    ASSERT_EQ(distances, expected_distances);
}