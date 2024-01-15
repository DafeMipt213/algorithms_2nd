#pragma once

#include <limits>
#include <queue>
#include <vector>

class WeightGraph {
 public:
  WeightGraph(int vertices);

  void AddEdge(int from, int to, int weight);
  std::vector<int> DijkstraAlgorithm(int source);

 private:
  std::vector<std::vector<std::pair<int, int>>> weight_adjacency_list_;
};