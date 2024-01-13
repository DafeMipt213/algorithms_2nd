#include "topology_sort.hpp"

#include <iostream>
#include <queue>
#include <vector>
void Graph::countIncoming() {
  for (auto& elem : nodes) {
    for (size_t j = 0; j < elem.second.out.size(); ++j) {
      size_t cur_number = nodes[elem.first].out[j];
      nodes[cur_number].in++;
    }
  }
}

std::vector<size_t> topologySort(Graph& graph) {
  std::vector<size_t> ans;
  std::queue<size_t> zeros;
  for (auto& elem : graph.nodes)
    if (elem.second.in == 0) zeros.push(elem.first);
  while (zeros.size() != 0) {
    size_t x = zeros.front();
    ans.push_back(x);
    zeros.pop();
    for (size_t j = 0; j < graph.nodes[x].out.size(); ++j) {
      auto cur_number = graph.nodes[x].out[j];
      graph.nodes[cur_number].in--;
      if (graph.nodes[cur_number].in == 0) zeros.push(cur_number);
    }
  }
  return ans;
}
