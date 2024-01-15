#pragma once

#include <array>
#include <iostream>
#include <queue>
#include <vector>

struct Vertex {
  int weight;
  int destination;
  Vertex(int destination, int wegiht);
  bool operator>(const Vertex other_vertex) const;
  bool operator<(const Vertex other_vertex) const;
  bool operator==(const Vertex other_vertex) const;
};

std::vector<std::vector<Vertex>> prim(
    const std::vector<std::vector<Vertex>>& g);