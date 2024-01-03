#include "weight_graph.hpp"
Weight_Graph::Weight_Graph(const vector<vector<pair<int, int>>> &adjacency_list)
    : g(adjacency_list) {}