#pragma once
#include <vector>
#include <stack>

using Graph = std::vector<std::vector<int>>;
using Vertexes = std::vector<int>;

Vertexes TopologySort(Graph graph);


