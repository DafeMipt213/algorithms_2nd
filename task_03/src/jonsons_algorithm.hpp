#pragma once

#include <set>
#include <utility>
#include <vector>

struct Edge {
  int u, v;
  long long w;
  Edge(int u, int v, long long w) : u(u), v(v), w(w) {}
};

bool BellmanFord(int n, int source, const std::vector<Edge> &edges,
                 std::vector<long long> &distance);
std::vector<long long> Dijkstra(int n, int source,
                                const std::vector<Edge> &edges,
                                std::vector<long long> &potential);
void Johnson(int n, std::vector<std::vector<long long>> &graph,
             std::vector<Edge> &edges);