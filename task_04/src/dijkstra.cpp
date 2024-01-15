#include "dijkstra.hpp"

#define INF std::numeric_limits<int>::max()

WeightGraph::WeightGraph(int vertices) : weight_adjacency_list_(vertices) {}

void WeightGraph::AddEdge(int from, int to, int weight) {
  weight_adjacency_list_[from].emplace_back(to, weight);
}

std::vector<int> WeightGraph::DijkstraAlgorithm(int source) {
  std::vector<int> distances(weight_adjacency_list_.size(), INF);
  distances[source] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;
  pq.push({0, source});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (const auto& edge : weight_adjacency_list_[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (distances[u] != INF && distances[u] + weight < distances[v]) {
        distances[v] = distances[u] + weight;
        pq.push({distances[v], v});
      }
    }
  }

  return distances;
}