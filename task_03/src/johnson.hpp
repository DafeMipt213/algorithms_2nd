#pragma once

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class WeightGraph {
 public:
  WeightGraph(int vertices);

  void AddEdge(int from, int to, int weight);
  std::vector<std::vector<int>> JohnsonAlgorithm();

 private:
  bool BellmanFord(std::vector<int>& distance);
  std::vector<int> Dijkstra(int source);

  std::vector<std::vector<std::pair<int, int>>> weight_adjacency_list_;
};