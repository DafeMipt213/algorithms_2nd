#pragma once
#include <stack>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using Vertexes = std::vector<int>;

Vertexes TopologySort(Graph graph);
