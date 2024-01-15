#include "algorithm_dijkstra.hpp"

int VertexWithShortestDistance(const std::vector<long long> &dist,
                               const std::vector<bool> &visited) {
  long long min = std::numeric_limits<long long>::max();
  int min_index = 0;
  for (int i = 0; i < visited.size(); i++)
    if (!visited[i] && dist[i] <= min) min = dist[i], min_index = i;
  return min_index;
}

std::vector<long long> Dijkstra(const std::vector<std::vector<int>> &graph,
                                int source) {
  std::vector<long long> distance(graph.size(),
                                  std::numeric_limits<long long>::max());
  std::vector<bool> visited(graph.size(), false);

  distance[source] = 0;

  for (int j = 0; j < graph.size() - 1; j++) {
    int u = VertexWithShortestDistance(distance, visited);
    visited[u] = true;
    for (int i = 0; i < graph.size(); i++)
      if (!visited[i] && graph[u][i] &&
          distance[u] != std::numeric_limits<long long>::max() &&
          distance[u] + graph[u][i] < distance[i])
        distance[i] = distance[u] + graph[u][i];
  }
  return distance;
}