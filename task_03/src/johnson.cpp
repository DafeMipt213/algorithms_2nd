#include "johnson.hpp"

void Graph::AddEdge(int from, int to, long long weight) {
  if (std::find(vertexes_.begin(), vertexes_.end(), from) == vertexes_.end()) {
    vertexes_.push_back(from);
    distances_[from] = std::numeric_limits<long long>::max();
  }
  if (std::find(vertexes_.begin(), vertexes_.end(), to) == vertexes_.end()) {
    vertexes_.push_back(to);
    distances_[to] = std::numeric_limits<long long>::max();
  }
  edges_.push_back({from, to, weight});

  adjacency_map_[from].push_back({to, weight});
  if (adjacency_map_.find(to) == adjacency_map_.end()) adjacency_map_[to] = {};
}

void Graph::AddVertex(int vertex) {
  if (std::find(vertexes_.begin(), vertexes_.end(), vertex) != vertexes_.end())
    return;
  vertexes_.push_back(vertex);
  distances_[vertex] = std::numeric_limits<long long>::max();
}

void Graph::PrepareGraph() {
  size_t vertexes_count = vertexes_.size();
  for (size_t i = 0; i < vertexes_count; i++) {
    AddEdge(std::numeric_limits<int>::min(), vertexes_[i], 0);
  }
}

bool Graph::BellmanFord(int vertex) {
  distances_[vertex] = 0;

  for (int i = 0; i < vertexes_.size(); i++) {
    for (auto &edge : edges_) {
      if (distances_[edge.from] != std::numeric_limits<long long>::max() &&
          distances_[edge.from] + edge.weight < distances_[edge.to])
        distances_[edge.to] = distances_[edge.from] + edge.weight;
    }
  }

  for (auto &edge : edges_) {
    if (distances_[edge.from] != std::numeric_limits<long long>::max() &&
        distances_[edge.from] + edge.weight < distances_[edge.to])
      is_cycled = true;
  }
  return is_cycled;
}

void Graph::ChangeEdges() {
  if (is_cycled) return;

  for (auto &vertex : vertexes_) values_[vertex] = distances_[vertex];
  for (auto &edge : edges_)
    if (edge.from != std::numeric_limits<int>::min())
      edge.weight = edge.weight + values_[edge.from] - values_[edge.to];

  size_t additional_edges_index = -1;
  for (size_t i = 0; i < edges_.size(); i++) {
    if (edges_[i].from == std::numeric_limits<int>::min()) {
      additional_edges_index = i;
      break;
    }
  }

  edges_.erase(edges_.begin() + additional_edges_index + 1, edges_.end());

  if (vertexes_.back() == std::numeric_limits<int>::min())
    vertexes_.erase(vertexes_.end() - 1);
  else
    for (size_t i = 0; i < vertexes_.size(); i++) {
      if (vertexes_[i] == std::numeric_limits<int>::min()) {
        vertexes_.erase(vertexes_.begin() + i);
        break;
      }
    }
}

std::map<int, long long> Graph::Dijkstra(int root) {
  std::map<int, long long> distances;
  for (auto &vertex : vertexes_)
    distances[vertex] = std::numeric_limits<long long>::max();

  distances[root] = 0;

  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>>
      queue;
  queue.push({0, root});
  while (!queue.empty()) {
    auto [current_distance, vertex] = queue.top();
    queue.pop();

    if (current_distance > distances[vertex]) continue;
    for (auto &[next_vertex, weight] : adjacency_map_[vertex]) {
      if (distances[next_vertex] > distances[vertex] + weight) {
        distances[next_vertex] = distances[vertex] + weight;
        queue.push({distances[next_vertex], next_vertex});
      }
    }
  }
  return distances;
}

std::map<int, std::map<int, long long>> Graph::Johnson() {
  std::map<int, std::map<int, long long>> result;

  PrepareGraph();
  BellmanFord(std::numeric_limits<int>::min());
  if (is_cycled) return {};

  ChangeEdges();
  for (auto &vertex : vertexes_) {
    auto distances = Dijkstra(vertex);
    result[vertex] = distances;
  }
  return result;
}