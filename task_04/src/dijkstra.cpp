#include "dijkstra.hpp"

// Dijkstra's algorithm to find shortest path from given source vertex to all other vertices
std::vector<int> Graph::Dijkstra_(int source) {
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

std::vector<std::vector<int>> Graph::Dijkstra()
{
    std::vector<std::vector<int>> distance_matrix(vertex_count, std::vector<int>(vertex_count, INF));

    for (int i = 0; i < vertex_count; ++i)
        distance_matrix[i] = Dijkstra_(i);
        
    return distance_matrix;
}