#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "topology_sort.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > graph;
  graph.resize(n);
  int tmp_from, tmp_to;
  for (int i = 0; i < m; ++i) {
    std::cin >> tmp_from >> tmp_to;
    graph[tmp_from].push_back(tmp_to);
  }

  std::vector<int> vec = top_sort(graph);
}