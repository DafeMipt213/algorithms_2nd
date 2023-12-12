#pragma once

#include <vector>

struct vertex {
  int number;
  int distance;
  vertex(int number, int distance) : number(number), distance(distance) {}
};

using Graph = std::vector<std::vector<vertex>>;

// for graph set by the adjacency matrix
int Dijkstra_alg(const Graph& graph, int start, int end);