#pragma once

#include <map>
#include <vector>

template <typename T = int>
class Graph {
  std::map<T, std::vector<T>> adjacency_map_;
  std::map<T, int> depths_;
  std::map<T, bool> visited_;

  std::vector<std::pair<T, T>> connections_;
  std::vector<T> routers_;

 public:
  Graph() = default;
  ~Graph() = default;
  void SetAdjacencyMap(std::map<T, std::vector<T>> adjacency_map);
  void AddEdge(T from, T to);
  void DFS(T vertex, T start_vertex, std::map<T, int> &d, bool is_root);
  void CalculateSolution();
  std::vector<std::pair<T, T>> GetConnections();
  std::vector<T> GetRouters();
};

template <typename T>
void Graph<T>::SetAdjacencyMap(std::map<T, std::vector<T>> adjacency_map) {
  adjacency_map_ = adjacency_map;
}

template <typename T>
std::vector<std::pair<T, T>> Graph<T>::GetConnections() {
  return connections_;
}

template <typename T>
std::vector<T> Graph<T>::GetRouters() {
  return routers_;
}

template <typename T>
void Graph<T>::CalculateSolution() {
  std::map<T, int> d;

  for (auto &[vertex, _] : adjacency_map_) {
    DFS(vertex, vertex, d, true);
    break;
  }
}

template <typename T>
void Graph<T>::AddEdge(T from, T to) {
  if (std::find(adjacency_map_[from].begin(), adjacency_map_[from].end(), to) ==
      adjacency_map_[from].end())
    adjacency_map_[from].push_back(to);
  if (std::find(adjacency_map_[to].begin(), adjacency_map_[to].end(), from) ==
      adjacency_map_[to].end())
    adjacency_map_[to].push_back(from);
  if (adjacency_map_.find(to) == adjacency_map_.end()) adjacency_map_[to] = {};
}

template <typename T>
void Graph<T>::DFS(T vertex, T parent, std::map<T, int> &d, bool is_root) {
  visited_[vertex] = true;

  if (!is_root)
    d[vertex] = depths_[vertex] = depths_[parent] + 1;
  else
    d[vertex] = depths_[vertex] = 0;

  size_t children = 0;
  for (auto &next_vertex : adjacency_map_[vertex]) {
    if (next_vertex != parent) {
      if (visited_[next_vertex])
        d[vertex] = std::min(d[vertex], depths_[next_vertex]);
      else {
        DFS(next_vertex, vertex, d, false);
        d[vertex] = std::min(d[vertex], d[next_vertex]);
        if (depths_[vertex] < d[next_vertex])
          connections_.push_back({vertex, next_vertex});
        if (depths_[vertex] <= d[next_vertex] && !is_root)
          routers_.push_back(vertex);
        children++;
      }
    }
  }
  if (is_root && children > 1) routers_.push_back(vertex);
}