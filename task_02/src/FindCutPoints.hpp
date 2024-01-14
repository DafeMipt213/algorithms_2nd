#pragma once

#include <iostream>
#include <set>
#include <utility>
#include <vector>

void FindCutPoint(int &timer, int start, std::vector<std::vector<int> > &graph,
                  std::vector<int> &tin, std::vector<int> &fup, int parent,
                  std::set<int> &cpvec, std::vector<bool> used);

std::set<int> returnCP(std::set<int> &cpvec);