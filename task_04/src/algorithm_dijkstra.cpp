#include "algorithm_dijkstra.hpp"

int VertexWithShortestDistance(std::vector<long long> &dist,
                               std::vector<bool> &visited) {
  int min = INT_MAX, min_index;
  for (int i = 0; i < visited.size(); i++)
    if (!visited[i] && dist[i] <= min) min = dist[i], min_index = i;
  return min_index;
}

std::vector<long long> Dijkstra(std::vector<std::vector<int>> &graph,
                                int source) {
  std::vector<long long> distance(graph.size(), INT_MAX);
  std::vector<bool> visited(graph.size(), false);

  distance[source] = 0;

  for (int j = 0; j < graph.size() - 1; j++) {
    int u = VertexWithShortestDistance(distance, visited);
    visited[u] = true;
    for (int i = 0; i < graph.size(); i++)
      if (!visited[i] && graph[u][i] && distance[u] != INT_MAX &&
          distance[u] + graph[u][i] < distance[i])
        distance[i] = distance[u] + graph[u][i];
  }
  return distance;
}