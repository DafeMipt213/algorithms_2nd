#include "FindBridges.hpp"

void FindBridges(int &timer, int start, std::vector<std::vector<int> > &graph,
                 std::vector<int> &tin, std::vector<int> &fup, int parent,
                 std::set<std::pair<int, int> > &result,
                 std::vector<bool> used) {
  used[start] = 1;
  tin[start] = fup[start] = ++timer;
  int to;
  for (int i = 0; i < graph[start].size(); ++i) {
    to = graph[start][i];
    if (to == parent) continue;
    if (used[to])
      fup[start] = std::min(fup[start], tin[to]);
    else {
      FindBridges(timer, to, graph, tin, fup, start, result, used);
      fup[start] = std::min(fup[start], fup[to]);
      if (fup[to] > tin[start])
        result.insert({std::min(start, to), std::max(start, to)});
    }
  }
}

std::set<std::pair<int, int> > returnBridges(
    std::set<std::pair<int, int> > &result) {
  return result;
}