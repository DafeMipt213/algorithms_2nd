#pragma once

#include <cstddef>
#include <vector>

#include "abstract_function.hpp"

enum Color { white, black, gray };

template <typename T>
using AdjacencyList = std::vector<std::vector<T>>;

template <typename T>
class Graph {
 public:
  std::vector<T>& operator[](const size_t& i);
  size_t Size() const;

  void DFS(size_t vertex, size_t parrent, bool is_root,
           AbstractFunction* function);

  void ResetColors();

  void SetAdjacencyList(std::vector<std::vector<T>>& adjacency_list);
  void SetAdjacencyList(std::vector<std::vector<T>> adjacency_list);

  void SetAdjacencyMatrix(
      std::vector<std::vector<long long>>& adjacency_matrix);
  void SetAdjacencyMatrix(std::vector<std::vector<long long>> adjacency_matrix);

  void AddNewVertex(std::vector<T> vertex);

 protected:
  std::vector<Color> colors_;
  AdjacencyList<T> graph_;
};

template <typename T>
void Graph<T>::SetAdjacencyList(std::vector<std::vector<T>>& adjacency_list) {
  colors_.assign(adjacency_list.size(), white);
  graph_ = adjacency_list;
}

template <typename T>
void Graph<T>::SetAdjacencyList(std::vector<std::vector<T>> adjacency_list) {
  colors_.assign(adjacency_list.size(), white);
  graph_ = adjacency_list;
}

template <typename T>
void Graph<T>::SetAdjacencyMatrix(
    std::vector<std::vector<long long>> adjacency_matrix) {
  graph_.resize(adjacency_matrix.size());
  for (size_t i = 0; i < adjacency_matrix.size(); ++i) {
    for (size_t j = 0; j < adjacency_matrix.size(); ++j) {
      if (adjacency_matrix[i][j] != 0) {
        graph_[i].push_back(T{j, adjacency_matrix[i][j]});
      }
    }
  }
}

template <typename T>
void Graph<T>::DFS(size_t vertex, size_t parent, bool is_root,
                   AbstractFunction* function) {
  colors_[vertex] = gray;
  function->OnVertexBefore(vertex, parent);

  for (const auto& u : graph_[vertex]) {
    if (u == parent) {
      continue;
    }
    if (colors_[u] == white) {
      DFS(u, vertex, false, function);
      function->OnEdgeNotVisited(vertex, u, is_root);
    } else {
      function->OnEdgeVisited(vertex, u, is_root);
    }
  }

  colors_[vertex] = black;
  function->OnVertexAfter(vertex, parent);
}

template <typename T>
std::vector<T>& Graph<T>::operator[](const size_t& i) {
  return graph_[i];
}

template <typename T>
size_t Graph<T>::Size() const {
  return graph_.size();
}

template <typename T>
void Graph<T>::ResetColors() {
  colors_.assign(graph_.size(), white);
}

template <typename T>
void Graph<T>::AddNewVertex(std::vector<T> vertex) {
  graph_.push_back(vertex);
}