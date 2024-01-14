#pragma once
#include <vector>

std::vector<int> Deijkstra(
    int start, std::vector<std::vector<std::pair<int, int> > > &graph);