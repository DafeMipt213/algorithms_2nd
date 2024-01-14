#include "Deijkstra.hpp"

#include <vector>

const int INF = 1e9;

std::vector<int> Deijkstra(
    int start, std::vector<std::vector<std::pair<int, int> > > &graph) {
  if (start < 0) {
    throw "Bad Input";
  }

  if (graph.size() == 0) throw "Empty Graph";

  std::vector<int> dist(graph.size(), INF);
  dist[start] = 0;
  std::vector<bool> used(graph.size());

  for (int i = 0; i < graph.size(); ++i) {
    int closest = -1;
    for (int j = 0; j < graph.size(); ++j) {
      if (!used[j] && (closest == -1 || dist[closest] > dist[j])) {
        closest = j;
      }
    }

    used[closest] = true;

    for (auto &[to, weight] : graph[closest]) {
      if (weight < 0) throw "Negative Weight!";
      if (dist[to] > dist[closest] + weight) {
        dist[to] = dist[closest] + weight;
      }
    }
  }
  return dist;
}