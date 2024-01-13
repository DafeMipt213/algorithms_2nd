#include "jonsons_algorithm.hpp"

#include <limits>

bool BellmanFord(int n, int source, std::vector<Edge> &edges,
                 std::vector<long long> &distance) {
  distance[source] = 0;
  for (int i = 0; i <= n; i++) {
    bool flag = false;
    for (auto e : edges) {
      if (distance[e.u] + e.w < distance[e.v]) {
        distance[e.v] = distance[e.u] + e.w;
        flag = true;
      }
    }
    if (!flag) return true;
  }
  return false;
}

std::vector<long long> Dijkstra(int n, int source, std::vector<Edge> &edges,
                                std::vector<long long> &potential) {
  std::set<std::pair<long long, int>> S;
  std::vector<long long> distance(n + 1, std::numeric_limits<long long>::max());
  std::vector<long long> temp(n + 1, std::numeric_limits<long long>::max());
  std::vector<std::pair<int, long long>> adj[n + 1];

  distance[source] = temp[source] = 0;
  S.insert(std::make_pair(temp[source], source));
  for (auto e : edges) {
    adj[e.u].push_back(std::make_pair(e.v, e.w));
  }

  while (!S.empty()) {
    std::pair<long long, int> cur = *(S.begin());
    S.erase(cur);

    int u = cur.second;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      long long w = adj[u][i].second;

      if ((temp[u] + w) < temp[v]) {
        S.erase(std::make_pair(temp[v], v));
        temp[v] = temp[u] + w;
        distance[v] = distance[u] + w;
        S.insert(std::make_pair(temp[v], v));
      }
    }
  }
  return distance;
}

void Johnson(int n, std::vector<std::vector<long long>> &graph,
             std::vector<Edge> &edges) {
  std::vector<long long> potential(n + 1,
                                   std::numeric_limits<long long>::max());
  for (int i = 1; i <= n; i++) edges.push_back(Edge(0, i, 0));

  if (!BellmanFord(n, 0, edges, potential)) return;

  for (int i = 1; i <= n; i++) edges.pop_back();

  for (int i = 1; i <= n; i++) {
    std::vector<long long> distance = Dijkstra(n, i, edges, potential);
    for (int j = 1; j <= n; j++) {
      graph[i][j] = distance[j];
    }
  }
}
