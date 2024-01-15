#pragma once

#include <limits>
#include <vector>

int VertexWithShortestDistance(const std::vector<long long> &dist,
                               const std::vector<bool> &visited);
std::vector<long long> Dijkstra(const std::vector<std::vector<int>> &graph,
                                int source);