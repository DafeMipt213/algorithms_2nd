#include "dijkstra.hpp"

#include <limits>
#include <set>

std::vector<long long> Dijkstra(WeightedGraph& graph, size_t start_vertex) {
  std::vector<long long> distances(graph.Size(),
                                   std::numeric_limits<long long>::max());
  std::set<Vertex> queue;
  distances[start_vertex] = 0;
  queue.insert({start_vertex, distances[start_vertex]});

  while (!queue.empty()) {
    Vertex v = *queue.begin();
    queue.erase(queue.begin());
    for (auto& u : graph[v]) {
      long long distance_from_v_to_u = distances[v.number] + u.weight;
      if (distance_from_v_to_u < distances[u.number]) {
        distances[u.number] = distance_from_v_to_u;
        queue.insert({
            u.number,
            distances[u.number],
        });
      }
    }
  }
  return distances;
}