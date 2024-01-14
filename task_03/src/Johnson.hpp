#pragma once

#include <vector>

#include "Deijkstra.hpp"

const int INF = 1e9;

class edge {
 public:
  int a;
  int b;
  int cost;
};

std::vector<std::vector<int>> Johnson(std::vector<edge> &edges, int m, int n);