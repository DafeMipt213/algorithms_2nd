#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

std::pair<std::vector<int>, bool> Ford(const std::vector<std::vector<std::pair<int, int> > >& graph, int v, int infinity);

int main();