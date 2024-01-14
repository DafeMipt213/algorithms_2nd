#pragma once

#include "FindBridges.hpp"
#include "FindCutPoints.hpp"

void AllFunc(std::vector<std::vector<int> > &graph,
             std::set<std::pair<int, int> > &result, std::set<int> &cpvector);