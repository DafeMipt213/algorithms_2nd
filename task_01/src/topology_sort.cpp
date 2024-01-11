#include "topology_sort.hpp"

Graph::Graph(int vertices) : vertices(vertices), adjList(vertices) {}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

void Graph::topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& stack) {
    visited[v] = true;

    for (const auto& neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, stack);
        }
    }

    stack.push(v);
}

void Graph::topologicalSort() {
    std::stack<int> stack;
    std::vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack);
        }
    }
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}
