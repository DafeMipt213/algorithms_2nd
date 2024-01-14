#include "topology_sort.hpp"
#include <algorithm>
#include <stdexcept>

std::vector<int> TopologySort(Graph G) {
  if (G.IsCycle())
    throw std::runtime_error("TopologySort - cyclical graph");

  std::vector<int> answer{};
  std::vector<int> *ptr = &answer;
  for (int v = 0; v < G.Size(); ++v)
    G.DFS(v, [ptr](int u) { (*ptr).push_back(u); });
  std::reverse(answer.begin(), answer.end());
  return answer;
}
