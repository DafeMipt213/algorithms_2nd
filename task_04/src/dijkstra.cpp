#include "dijkstra.hpp"

std::vector<int> Graph::Dijkstra(int start) {
  std::vector<int> distance(vertices_, INF);
  distance[start] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int u = pq.top().second;
    int distU = pq.top().first;
    pq.pop();

    if (distU > distance[u]) {
      continue;
    }

    for (const auto& neighbor : adjacency_list_[u]) {
      int v = neighbor.first;
      int weightUV = neighbor.second;

      if (distU != INF && distU + weightUV < distance[v]) {
        distance[v] = distU + weightUV;
        pq.push({distance[v], v});
      }
    }
  }
  return distance;
}