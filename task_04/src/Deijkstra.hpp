#pragma once
#include <vector>

int Deijkstra(int start, int end,
              std::vector<std::vector<std::pair<int, int> > > &graph);