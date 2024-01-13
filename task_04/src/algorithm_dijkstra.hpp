#pragma once

#include <limits>
#include <vector>

int VertexWithShortestDistance(std::vector<long long> &dist,
                               std::vector<bool> &visited);
std::vector<long long> Dijkstra(std::vector<std::vector<int>> &graph,
                                int source);