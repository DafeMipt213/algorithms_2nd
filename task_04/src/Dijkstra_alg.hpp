#pragma once

#include <vector>

struct Vertex {
  int number;
  int distance;
  Vertex(int number, int distance) : number(number), distance(distance) {}
  bool operator<(const Vertex& vert) const { return distance < vert.distance; }
};

using Graph = std::vector<std::vector<Vertex>>;

// for graph set by the adjacency matrix
int DijkstraAlgorithm(const Graph& graph, int start, int end);