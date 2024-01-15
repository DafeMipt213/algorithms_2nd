#include "johnson.hpp"

#define INF std::numeric_limits<int>::max()

WeightGraph::WeightGraph(int vertices) : weight_adjacency_list_(vertices) {}

void WeightGraph::AddEdge(int from, int to, int weight) {
  weight_adjacency_list_[from].emplace_back(to, weight);
}

std::vector<std::vector<int>> WeightGraph::JohnsonAlgorithm() {
  std::vector<int> bellmanFordDistances;
  if (!BellmanFord(bellmanFordDistances))
    throw std::runtime_error("Graph contains a negative cycle!");

  std::vector<std::vector<int>> result(
      weight_adjacency_list_.size(),
      std::vector<int>(weight_adjacency_list_.size(), INF));

  for (int i = 0; i < weight_adjacency_list_.size(); ++i) {
    std::vector<int> dijkstraDistances = Dijkstra(i);
    result[i] = dijkstraDistances;
  }

  return result;
}

bool WeightGraph::BellmanFord(std::vector<int>& distance) {
  distance.assign(weight_adjacency_list_.size(), INF);
  distance[weight_adjacency_list_.size() - 1] = 0;

  for (int i = 0; i < weight_adjacency_list_.size() - 1; ++i)
    for (int u = 0; u < weight_adjacency_list_.size(); ++u)
      for (const auto& edge : weight_adjacency_list_[u]) {
        int v = edge.first;
        int weight = edge.second;

        if (distance[u] != INF && distance[u] + weight < distance[v])
          distance[v] = distance[u] + weight;
      }

  for (int u = 0; u < weight_adjacency_list_.size(); ++u)
    for (const auto& edge : weight_adjacency_list_[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (distance[u] != INF && distance[u] + weight < distance[v])
        return false;  // Graph contains a negative cycle
    }

  return true;
}

std::vector<int> WeightGraph::Dijkstra(int source) {
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