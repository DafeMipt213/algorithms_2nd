#pragma once

#include <iostream>
#include <set>
#include <utility>
#include <vector>

void FindBridges(int &timer, int start, std::vector<std::vector<int> > &graph,
                 std::vector<int> &tin, std::vector<int> &fup, int parent,
                 std::set<std::pair<int, int> > &result,
                 std::vector<bool> used);

std::set<std::pair<int, int> > returnBridges(
    std::set<std::pair<int, int> > &result);