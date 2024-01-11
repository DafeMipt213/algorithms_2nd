#include "topology_sort.hpp"

Graph::Graph(int v) : vertices(v), adjList(v) {}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

std::vector<int> Graph::topologicalSort() {
    std::vector<int> inDegree(vertices, 0);
    for (int u = 0; u < vertices; ++u) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }

    std::queue<int> q;
    for (int u = 0; u < vertices; ++u) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    std::vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adjList[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (result.size() != vertices) {
        // Граф содержит цикл
        result.clear();
    }

    return result;
}
