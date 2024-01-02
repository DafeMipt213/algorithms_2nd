#pragma once

#include <cstddef>
#include <vector>

struct Vertex {
  size_t number;
  long long weight;
};

class WeightedGraph {
 public:
  WeightedGraph(std::vector<std::vector<long long>> adjacency_matrix);
  std::vector<Vertex>& operator[](const Vertex& v);
  std::vector<Vertex>& operator[](const size_t i);
  void AddNewVertex(std::vector<Vertex> dv);
  size_t Size() const;

 private:
  std::vector<std::vector<Vertex>> graph_;
};

bool operator<(const Vertex& dv1, const Vertex& dv2);