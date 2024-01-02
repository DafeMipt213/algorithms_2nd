#pragma once

#include <cstddef>
#include <vector>

#include "abstract_function.hpp"

enum Color { white, black, gray };

class Graph {
 public:
  Graph(std::vector<std::vector<size_t>> adjacency_list);
  std::vector<size_t>& operator[](const size_t i);
  size_t Size() const;

  void DFS(size_t vertex, size_t parrent, AbstractFunction* func);
  void BFS(size_t vertex, AbstractFunction* func);

  void ResetColors();

 protected:
  std::vector<Color> colors_;
  std::vector<std::vector<size_t>> graph_;
};
