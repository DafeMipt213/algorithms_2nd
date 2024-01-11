#pragma once

#include <vector>

class Graph {
public:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

    Graph(int V);

    void addEdge(int u, int v, int weight);

    void dijkstra(int source);
};
