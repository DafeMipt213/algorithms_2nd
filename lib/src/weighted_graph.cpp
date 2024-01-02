#include "weighted_graph.hpp"

#include <vector>

WeightedGraph::WeightedGraph(
    std::vector<std::vector<long long>> adjacency_matrix)
    : graph_{adjacency_matrix.size()} {
  for (size_t i = 0; i < adjacency_matrix.size(); ++i) {
    for (size_t j = 0; j < adjacency_matrix.size(); ++j) {
      if (adjacency_matrix[i][j] != 0) {
        graph_[i].push_back({j, adjacency_matrix[i][j]});
      }
    }
  }
}

size_t WeightedGraph::Size() const { return graph_.size(); }

std::vector<Vertex>& WeightedGraph::operator[](const Vertex& v) {
  return graph_[v.number];
}

std::vector<Vertex>& WeightedGraph::operator[](const size_t i) {
  return graph_[i];
}

void WeightedGraph::AddNewVertex(std::vector<Vertex> v) { graph_.push_back(v); }

bool operator<(const Vertex& dv1, const Vertex& dv2) {
  return dv1.weight < dv2.weight;
}
