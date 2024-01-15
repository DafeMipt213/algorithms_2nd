#pragma once

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#define INF std::numeric_limits<int>::max()

class Graph {
 public:
  Graph(size_t size) : vertices_(size), adjacency_list_(size) {}

  void AddEdge(int u, int v, int weight) {
    adjacency_list_[u].emplace_back(v, weight);
  }

  std::vector<int> Dijkstra(int start);

 private:
  int vertices_;
  std::vector<std::vector<std::pair<int, int>>> adjacency_list_;
};