#pragma once

#include <vector>

#include "weighted_graph.hpp"

std::vector<long long> Dijkstra(WeightedGraph& graph,
                                unsigned long start_vertex);