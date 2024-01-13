#pragma once
#include <vector>


void dfs (int v, std::vector<bool> &used, std::vector<int> &result, std::vector< std::vector<int> > &graph);

std::vector<int> top_sort (std::vector< std::vector<int> > &graph);