#include "Johnson.hpp"

#include "Deijkstra.hpp"

std::vector<std::vector<int>> Johnson(std::vector<edge> &edges, int m, int n) {
  std::vector<int> vec(n, INF);
  std::vector<edge> tmp_edges = edges;
  int v = 0;
  vec[v] = 0;
  for (int i = 0; i < n; ++i) {
    tmp_edges.push_back({n, i, 0});
  }

  m += n;

  std::vector<int> p(n, -1);
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (int j = 0; j < m; ++j) {
      if (vec[tmp_edges[j].a] < INF) {
        if (vec[tmp_edges[j].b] > vec[tmp_edges[j].a] + tmp_edges[j].cost) {
          vec[tmp_edges[j].b] = std::min(
              vec[tmp_edges[j].b], vec[tmp_edges[j].a] + tmp_edges[j].cost);
          p[tmp_edges[j].b] = tmp_edges[j].a;
          x = tmp_edges[j].b;
        }
      }
    }
  }
  if (x != -1) {
    throw "Negative Cycle";
  }

  for (int i = 0; i < edges.size(); ++i) {
    edges[i].cost = edges[i].cost + vec[edges[i].a] - vec[edges[i].b];
  }
  std::vector<std::vector<int>> res;

  std::vector<std::vector<std::pair<int, int>>> graph;
  graph.resize(n);

  for (int i = 0; i < edges.size(); ++i) {
    graph[edges[i].a].push_back({edges[i].b, edges[i].cost});
  }

  for (int i = 0; i < n; ++i) {
    res.push_back(Deijkstra(i, graph));
  }

  return res;
}