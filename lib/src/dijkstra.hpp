#pragma once

#include <cstddef>
#include <vector>

#include "graph.hpp"

struct VertexWeighted {
  size_t number;
  long long weight;
};

bool operator<(const VertexWeighted& vertex1, const VertexWeighted& vertex2);

std::vector<long long> Dijkstra(Graph<VertexWeighted>& graph,
                                size_t start_vertex);