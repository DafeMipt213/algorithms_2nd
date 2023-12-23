#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <set>

std::set<std::pair<int, int>> findBridges (const std::vector<std::vector<int>>& graph);
void innerFindBridges(std::vector<std::vector<int>>& graph, int time, std::vector<int>& tin, std::vector<int>& ret,
                         std::vector<int>& colors, int vertex, int parent, std::set<std::pair<int, int>>& bridges);

std::set<int> findCutPoints (const std::vector<std::vector<int>>& graph);
void innerFindCutPoints(std::vector<std::vector<int>>& graph, int time, std::vector<int>& tin, std::vector<int>& ret,
                         std::vector<int>& colors, int vertex, int parent, std::set<int>& articulation_points);