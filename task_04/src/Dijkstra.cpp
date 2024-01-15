#include "Dijkstra.hpp"

Vertex::Vertex(int destination, int distance)
    : destination(destination), distance(distance) {}

bool Vertex::operator>(const Vertex& V) const {
  return this->distance > V.distance;
}

int Dijkstra(const std::vector<std::vector<Vertex>>& graph, int from, int to) {
  std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>>
      dijkstra_heap;
  std::vector<int> distances(graph.size(), std::numeric_limits<int>::max());
  dijkstra_heap.push({from, 0});

  while (!dijkstra_heap.empty()) {
    const Vertex current_vertex = dijkstra_heap.top();
    dijkstra_heap.pop();

    if (distances[current_vertex.destination] ==
        std::numeric_limits<int>::max()) {
      distances[current_vertex.destination] = current_vertex.distance;
    }

    for (auto& v : graph[current_vertex.destination]) {
      if (distances[v.destination] == std::numeric_limits<int>::max()) {
        dijkstra_heap.push(
            {v.destination, current_vertex.distance + v.distance});
      }
    }
  }
  return distances[to] == std::numeric_limits<int>::max() ? -1 : distances[to];
}