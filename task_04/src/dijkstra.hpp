#pragma once

#include <climits>
#include <map>
#include <queue>
#include <vector>

template <typename T = int>
class Graph {
  std::vector<T> vertexes_;
  std::map<T, unsigned long long> distances_;
  std::map<T, std::vector<std::pair<T, unsigned long long>>> adjacency_map_;

 public:
  Graph() = default;
  ~Graph() = default;

  void AddEdge(T from, T to, unsigned long long weight);
  void AddVertex(T vertex);
  std::map<T, unsigned long long> Dijkstra(T root);
};

template <typename T>
void Graph<T>::AddEdge(T from, T to, unsigned long long weight) {
  if (std::find(vertexes_.begin(), vertexes_.end(), from) == vertexes_.end()) {
    vertexes_.push_back(from);
    distances_[from] = ULONG_LONG_MAX;
  }
  if (std::find(vertexes_.begin(), vertexes_.end(), to) == vertexes_.end()) {
    vertexes_.push_back(to);
    distances_[to] = ULONG_LONG_MAX;
  }

  adjacency_map_[from].push_back({to, weight});
  if (adjacency_map_.find(to) == adjacency_map_.end()) adjacency_map_[to] = {};
}

template <typename T>
void Graph<T>::AddVertex(T vertex) {
  if (std::find(vertexes_.begin(), vertexes_.end(), vertex) != vertexes_.end())
    return;
  vertexes_.push_back(vertex);
  distances_[vertex] = ULONG_LONG_MAX;
}

template <typename T>
std::map<T, unsigned long long> Graph<T>::Dijkstra(T root) {
  for (auto &vertex : vertexes_) distances_[vertex] = LONG_LONG_MAX;

  distances_[root] = 0;

  std::priority_queue<std::pair<unsigned long long, T>,
                      std::vector<std::pair<unsigned long long, T>>,
                      std::greater<std::pair<unsigned long long, T>>>
      queue;
  queue.push({0, root});
  while (!queue.empty()) {
    auto [current_distance, vertex] = queue.top();
    queue.pop();

    if (current_distance > distances_[vertex]) continue;
    for (auto &[next_vertex, weight] : adjacency_map_[vertex]) {
      if (distances_[next_vertex] > distances_[vertex] + weight) {
        distances_[next_vertex] = distances_[vertex] + weight;
        queue.push({distances_[next_vertex], next_vertex});
      }
    }
  }
  return distances_;
}
