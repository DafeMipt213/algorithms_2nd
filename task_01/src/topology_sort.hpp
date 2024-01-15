#pragma once

#include <vector>
#include <algorithm>

enum Colors{
    White,
    Gray,
    Black
};

void dfs(int v, std::vector<std::vector<int> >& g, std::vector<Colors>& color, std::vector<int>& ans, bool is_circle);

void topology_sort(std::vector<std::vector<int> >& g, std::vector<Colors>& color, std::vector<int>& ans, bool is_circle);