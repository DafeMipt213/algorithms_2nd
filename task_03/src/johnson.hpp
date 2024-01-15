#pragma once

#include <dijkstra.hpp>
#include <vector>

bool FordBellman(Graph<VertexWeighted>& graph, size_t s,
                 std::vector<long long>& distances);

std::vector<std::vector<long long>> Johnson(Graph<VertexWeighted>& graph);