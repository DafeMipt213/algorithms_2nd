#ifndef topology_sort_hpp
#define topology_sort_hpp

#include <vector>
#include <queue>

class Graph {
    int vertices;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int v);
    void addEdge(int u, int v);
    std::vector<int> topologicalSort();
};

#endif