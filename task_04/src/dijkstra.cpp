#include "dijkstra.hpp"
#include <iostream>
#include <limits>
#include <queue>

const int INF = std::numeric_limits<int>::max();

Graph::Graph(int V) : vertices(V), adjacencyList(V) {}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyList[u].emplace_back(v, weight);
    adjacencyList[v].emplace_back(u, weight);
}

void Graph::dijkstra(int source) {
    std::vector<int> distance(vertices, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : adjacencyList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    std::cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        if (distance[i] == INF) {
            std::cout << "INF";
        } else {
            std::cout << distance[i];
        }
        std::cout << "\n";
    }
}
