#include "Dijkstra_alg.hpp"

#include <limits>
#include <set>

int Dijkstra_alg(const Graph& graph, int start, int end) {
  const int inf = std::numeric_limits<int>::max();
  std::vector<int> distances(graph.size(), inf);
  distances[start] = 0;
  std::set<vertex> queue;
  queue.insert(vertex(start, distances.at(0)));

  while (!queue.empty()) {
    int temp_vert = queue.begin()->number;
    queue.erase(queue.begin());

    if (temp_vert == end) return distances.at(temp_vert);

    for (size_t i = 0; i < graph.at(temp_vert).size(); ++i) {
      int destination = graph.at(temp_vert).at(i).number;
      int distance = graph.at(temp_vert).at(i).distance;

      if (distances.at(temp_vert) + distance < distances.at(destination)) {
        queue.erase(vertex(destination, distances.at(destination)));
        distances[destination] = distances.at(temp_vert) + distance;
        queue.insert(vertex(destination, distances.at(destination)));
      }
    }
  }
}