#include "Johnson_alg.hpp"

#include <limits>
#include <set>
#include <stdexcept>

struct Vertex {
  int number;
  int distance;
  Vertex(int number, int distance) : number(number), distance(distance) {}
  bool operator<(const Vertex& vert) const { return distance < vert.distance; }
};

bool FordBellmanAlgorithm(const std::vector<Edge>& graph,
                          std::vector<int>& distances) {
  int temp_vertex;
  for (std::size_t i = 0; i < distances.size(); ++i) {
    temp_vertex = -1;
    for (std::size_t j = 0; j < graph.size(); ++j)
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

std::vector<int> DijkstraAlgorithm(
    const std::vector<std::vector<Vertex>>& graph, int start) {
  const int inf = std::numeric_limits<int>::max();
  std::vector<int> distances(graph.size(), inf);
  distances[start] = 0;
  std::set<Vertex> queue;
  queue.insert(Vertex(start, distances.at(0)));

  while (!queue.empty()) {
    int temp_vert = queue.begin()->number;
    queue.erase(queue.begin());
    for (std::size_t i = 0; i < graph.at(temp_vert).size(); ++i) {
      int destination = graph.at(temp_vert).at(i).number;
      int distance = graph.at(temp_vert).at(i).distance;

      if (distances.at(temp_vert) + distance < distances.at(destination)) {
        queue.erase(Vertex(destination, distances.at(destination)));
        distances[destination] = distances.at(temp_vert) + distance;
        queue.insert(Vertex(destination, distances.at(destination)));
      }
    }
  }
  return distances;
}

std::vector<std::vector<int>> FindShortestPathes(const std::vector<Edge>& graph,
                                                 int vertexes_count) {
  std::vector<int> potential(vertexes_count);
  if (!FordBellmanAlgorithm(graph, potential))
    throw std::runtime_error("negative cycle");

  std::vector<std::vector<Vertex>> graph_positive(vertexes_count);
  for (std::size_t i = 0; i < graph.size(); ++i)
    graph_positive[graph[i].start].push_back(Vertex(
        graph[i].end,
        graph[i].cost + potential[graph[i].start] - potential[graph[i].end]));

  std::vector<std::vector<int>> distances;
  for (std::size_t i = 0; i < vertexes_count; ++i)
    distances.push_back(DijkstraAlgorithm(graph_positive, i));

  for (std::size_t i = 0; i < vertexes_count; ++i)
    for (std::size_t j = 0; j < vertexes_count; ++j)
      distances[i][j] = distances[i][j] - potential[i] + potential[j];
  return distances;
}