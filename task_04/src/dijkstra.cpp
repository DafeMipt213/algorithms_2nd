#include "weight_graph.hpp"
#include <bits/stdc++.h>

#define INF INT_MAX

vector<int> Weight_Graph::dijkstra(int src) {
  size_t n = g.size();
  vector<int> distance(n, INF);
  vector<bool> used(n, false);
  priority_queue<pair<int, int>> heap;
  distance[src] = 0;
  heap.push({0, src});
  while (!heap.empty()) {
    int v = heap.top().second;
    heap.pop();
    if (used[v])
      continue;
    used[v] = true;
    for (auto i : g[v]) {
      int u = i.first, d = i.second;
      int new_dist = distance[v] + d;
      if (new_dist < distance[u]) {
        distance[u] = new_dist;
        heap.push({distance[u], u});
      }
    }
  }
  for (int &i : distance) {
    if (i == INF) {
      i = -1;
    }
  }
  return distance;
}