#pragma once

#include <limits.h>

#include <set>
#include <utility>
#include <vector>

struct edge {
  int u, v;
  long long w;
  edge(int u, int v, long long w) : u(u), v(v), w(w) {}
};

bool BellmanFord(int n, int source, std::vector<struct edge> &edges,
                 std::vector<long long> &distance);
std::vector<long long> Dijkstra(int n, int source, std::vector<edge> &edges,
                                std::vector<long long> &potential);
void Johnson(int n, std::vector<std::vector<long long>> &graph,
             std::vector<struct edge> &edges);