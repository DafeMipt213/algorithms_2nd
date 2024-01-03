#include "graph.hpp"

Graph::Graph(const std::vector<std::vector<size_t>> &adjacency_list)
    : g{adjacency_list}, color(adjacency_list.size(), Color::White),
      parent(adjacency_list.size()), tin(adjacency_list.size()),
      tout(adjacency_list.size()) {}

void Graph::dfs(int v, int p) {
  tin[v] = timer++;
  parent[v] = p;
  color[v] = Color::Gray;
  for (int to : g[v]) {
    if (color[to] != Color::White)
      continue;
    dfs(to, v);
  }
  tout[v] = timer++;
  color[v] = Color::Black;
}