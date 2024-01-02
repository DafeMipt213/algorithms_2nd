#pragma once

#include <vector>
#include <weighted_graph.hpp>

bool FordBellman(WeightedGraph& graph, size_t s,
                 std::vector<long long>& distances);

std::vector<std::vector<long long>> Johnson(WeightedGraph& graph);