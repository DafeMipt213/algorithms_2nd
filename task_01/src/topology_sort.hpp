#pragma once

#include <algorithm>
#include <cstddef>
#include <map>
#include <vector>

template <typename T = int>
class Graph {
  enum class Color { kWhite = 0, kGray = 1, kBlack = 2 };

  std::map<T, std::vector<T>> adjacency_map_;
  std::map<T, Color> colors_;
  std::vector<T> exited_vertexes_;

  bool cycled_;

 public:
  Graph() : cycled_(false){};
  void AddEdge(T from, T to);
  void DFS(T vertex);
  std::vector<T> TopologySort();
};

template <typename T>
void Graph<T>::AddEdge(T from, T to) {
  if (std::find(adjacency_map_[from].begin(), adjacency_map_[from].end(), to) ==
      adjacency_map_[from].end())
    adjacency_map_[from].push_back(to);
  if (adjacency_map_.find(to) == adjacency_map_.end()) adjacency_map_[to] = {};
  colors_[from] = Color::kWhite;
  colors_[to] = Color::kWhite;
}

template <typename T>
void Graph<T>::DFS(T vertex) {
  colors_[vertex] = Color::kGray;
  for (T next_vertex : adjacency_map_[vertex]) {
    if (colors_[next_vertex] == Color::kWhite)
      DFS(next_vertex);
    else if (colors_[next_vertex] == Color::kGray) {
      cycled_ = true;
      return;
    }
  }
  colors_[vertex] = Color::kBlack;
  exited_vertexes_.push_back(vertex);
}

template <typename T>
std::vector<T> Graph<T>::TopologySort() {
  for (auto& [vertex, other_vertexes] : adjacency_map_) {
    if (colors_[vertex] == Color::kWhite) DFS(vertex);
  }

  if (cycled_) return {};
  std::reverse(exited_vertexes_.begin(), exited_vertexes_.end());
  return exited_vertexes_;
}