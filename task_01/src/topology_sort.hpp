#pragma once

#include <iostream>
#include <vector>
#include <stack>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void topologicalSort();

private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& stack);
};