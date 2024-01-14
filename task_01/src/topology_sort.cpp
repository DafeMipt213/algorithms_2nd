#include "graph.hpp"
#include <algorithm>
#include <numeric>
#include <stack>

std::vector<size_t> Graph::topologicalSort() {
  vector<size_t> new_tout(tout.size());
  fill(color.begin(), color.end(), Color::White);
  for (int i = 0; i < g.size(); ++i)
    if (color[i] == Color::White)
      dfs(i);
  copy(begin(tout), end(tout), begin(new_tout));
  vector<size_t> idx(tout.size());
  iota(idx.begin(), idx.end(), 0);
  stable_sort(idx.begin(), idx.end(), [new_tout](size_t i1, size_t i2) {
    return new_tout[i1] > new_tout[i2];
  });
  return idx;
}
