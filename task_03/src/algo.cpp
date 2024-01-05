#include "algo.hpp"

// Bellman-Ford algorithm to find shortest path from source to all other vertices
std::vector<int> Graph::BellmanFord(int source) {
    std::vector<int> distance(vertex_count, INF);
    distance[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < vertex_count - 1; ++i) {
            for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            std::cout << "Graph contains negative-weight cycle!\n";
            return {};
        }
    }

    return distance;
}

// Dijkstra's algorithm to find shortest path from given source vertex to all other vertices
std::vector<int> Graph::Dijkstra(int source) {
    std::vector<int> distance(vertex_count, INF);
    distance[source] = 0;

    auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pq(compare);
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();

        for (const auto& edge : edges) {
            if (edge.source == u) {
                int v = edge.destination;
                int w = edge.weight;
                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    pq.push({v, distance[v]});
                }
            }
        }
    }

    return distance;
}

// Johnson's algorithm to find shortest paths between all pairs of vertices
std::vector<std::vector<int>> Graph::JohnsonsAlgorithm() {
    // Add an extra vertex with zero-weight edges to all other vertices
    for (int i = 0; i < vertex_count; ++i)
        edges.push_back({vertex_count, i, 0});

    // Run Bellman-Ford algorithm from the extra vertex
    std::vector<int> phi = BellmanFord(vertex_count);

    std::vector<std::vector<int>> distance_matrix(vertex_count, std::vector<int>(vertex_count, INF));

    // Re-weight the edges
    for (auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;
        if (phi[u] != INF && phi[u] != INF) {
            edge.weight = w + phi[u] - phi[v];
        }
    }

    // Run Dijkstra's algorithm for every vertex
    for (int i = 0; i < vertex_count; ++i) {
        std::vector<int> distance = Dijkstra(i);
        for (int j = 0; j < vertex_count; ++j) {
            if (distance[j] != INF)
                distance_matrix[i][j] = distance[j] + phi[j] - phi[i];
        }
    }

    return distance_matrix;
}