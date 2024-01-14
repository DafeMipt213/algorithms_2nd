#include "Fib_heap.hpp"
#include <algorithm>
#include <vector>

using namespace std;
#define INF INT_MAX
using EDGES_LISTS = vector<vector<pair<int, int>>>;

template <template <class> class T>
vector<int> Dijkstra(EDGES_LISTS &edges_lists, int start_vertex) {
  int n = edges_lists.size();
  vector<int> distance(n, 1000000000);
  vector<bool> used(n, false);

  FibonacciHeap<pair<int, int>> heap;
  distance[start_vertex] = 0;
  heap.Insert({0, start_vertex});

  while (!heap.IsEmpty()) {
    int v = heap.GetMinimum().second;
    heap.RemoveMinimum();
    if (used[v]) {
      continue;
    }
    used[v] = true;
    for (auto i : edges_lists[v]) {
      int u = i.first, d = i.second;
      int new_dist = distance[v] + d;
      if (new_dist < distance[u]) {
        distance[u] = new_dist;
        heap.Insert({distance[u], u});
      }
    }
  }
  for (int i = 0; i < distance.size(); ++i) {
    if (distance[i] == 1000000000) {
      distance[i] = -1;
    }
  }
  return distance;
}