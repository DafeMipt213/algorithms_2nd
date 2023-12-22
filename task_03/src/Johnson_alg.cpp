#include "Johnson_alg.hpp"

#include <limits>
#include <set>
#include <stdexcept>

struct vertex {
  int number;
  int distance;
  vertex(int number, int distance) : number(number), distance(distance) {}
  bool operator<(const vertex& vert) const { return distance < vert.distance; }
};

bool Ford_Bellman_algorithm(const std::vector<edge>& graph,
                            std::vector<int>& distances) {
  int temp_vertex;
  for (int i = 0; i < distances.size(); ++i) {
    temp_vertex = -1;
    for (int j = 0; j < graph.size(); ++j)
      if (distances[graph[j].end] > distances[graph[j].start] + graph[j].cost &&
          distances[graph[j].start] != std::numeric_limits<int>::max()) {
        distances[graph[j].end] = distances[graph[j].start] + graph[j].cost;
        temp_vertex = graph[j].end;
      }
  }
  if (temp_vertex == -1)
    return true;
  else
    return false;
}

std::vector<int> Dijkstra_alg(const std::vector<std::vector<vertex>>& graph,
                              int start) {
  const int inf = std::numeric_limits<int>::max();
  std::vector<int> distances(graph.size(), inf);
  distances[start] = 0;
  std::set<vertex> queue;
  queue.insert(vertex(start, distances.at(0)));

  while (!queue.empty()) {
    int temp_vert = queue.begin()->number;
    queue.erase(queue.begin());
    for (std::size_t i = 0; i < graph.at(temp_vert).size(); ++i) {
      int destination = graph.at(temp_vert).at(i).number;
      int distance = graph.at(temp_vert).at(i).distance;

      if (distances.at(temp_vert) + distance < distances.at(destination)) {
        queue.erase(vertex(destination, distances.at(destination)));
        distances[destination] = distances.at(temp_vert) + distance;
        queue.insert(vertex(destination, distances.at(destination)));
      }
    }
  }
  return distances;
}

std::vector<std::vector<int>> Johnson_algorithm(const std::vector<edge>& graph,
                                                int vertexes_count) {
  std::vector<int> potential(vertexes_count);
  if (!Ford_Bellman_algorithm(graph, potential))
    throw std::runtime_error("negative cycle");

  std::vector<std::vector<vertex>> graph_positive(vertexes_count);
  for (int i = 0; i < graph.size(); ++i)
    graph_positive[graph[i].start].push_back(vertex(
        graph[i].end,
        graph[i].cost + potential[graph[i].start] - potential[graph[i].end]));

  std::vector<std::vector<int>> distances;
  for (int i = 0; i < vertexes_count; ++i)
    distances.push_back(Dijkstra_alg(graph_positive, i));

  for (int i = 0; i < vertexes_count; ++i)
    for (int j = 0; j < vertexes_count; ++j)
      distances[i][j] = distances[i][j] - potential[i] + potential[j];
  return distances;
}