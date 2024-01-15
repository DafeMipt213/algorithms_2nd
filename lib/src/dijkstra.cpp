#include "dijkstra.hpp"

#include <limits>
#include <set>

bool operator<(const VertexWeighted& vertex1, const VertexWeighted& vertex2) {
  return vertex1.weight < vertex2.weight;
}

std::vector<long long> Dijkstra(Graph<VertexWeighted>& graph,
                                size_t start_vertex) {
  std::vector<long long> distances(graph.Size(),
                                   std::numeric_limits<long long>::max());
  std::set<VertexWeighted> queue;
  distances[start_vertex] = 0;
  queue.insert({start_vertex, distances[start_vertex]});

  while (!queue.empty()) {
    VertexWeighted v = *queue.begin();
    queue.erase(queue.begin());
    for (auto& u : graph[v.number]) {
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