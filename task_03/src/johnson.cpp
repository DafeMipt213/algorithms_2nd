#include "johnson.hpp"

#include <cstddef>
#include <dijkstra.hpp>
#include <limits>
#include <stdexcept>

bool FordBellman(WeightedGraph& graph, size_t s,
                 std::vector<long long>& distances) {
  long long INF = std::numeric_limits<long long>::max();

  distances.assign(graph.Size(), INF);
  distances[s] = 0;

  for (unsigned long long k = 0; k < graph.Size() - 2; ++k) {
    for (size_t i = 0; i < graph.Size(); ++i) {
      for (size_t j = 0; j < graph[i].size(); ++j) {
        size_t u = graph[i][j].number;
        long long weight = graph[i][j].weight;
        if (distances[i] != INF) {
          distances[u] = std::min(distances[u], distances[i] + weight);
        }
      }
    }
  }

  for (size_t i = 0; i < graph.Size(); ++i) {
    for (size_t j = 0; j < graph[i].size(); ++j) {
      long long u = graph[i][j].number;
      long long weight = graph[i][j].weight;
      if (distances[u] > distances[i] + weight) {
        return false;
      }
    }
  }

  return true;
}

std::vector<std::vector<long long>> Johnson(WeightedGraph& graph) {
  long long INF = std::numeric_limits<long long>::max();
  size_t size = graph.Size();
  std::vector<std::vector<long long>> result(size,
                                             std::vector<long long>(size, INF));

  std::vector<long long> potencials(size + 1, 0);
  WeightedGraph new_graph = graph;

  std::vector<Vertex> fictitious_vertex;
  for (size_t i = 0; i < size; ++i) {
    fictitious_vertex.push_back({i, 0});
  }
  new_graph.AddNewVertex(fictitious_vertex);

  if (FordBellman(new_graph, new_graph.Size() - 1, potencials) == false) {
    throw std::runtime_error("Negative cycle");
    return {};
  }

  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < graph[i].size(); ++j) {
      size_t vertex = new_graph[i][j].number;
      new_graph[i][j].weight += potencials[i] - potencials[vertex];
    }
  }

  for (size_t i = 0; i < size; ++i) {
    std::vector<long long> dijkstra_distances = Dijkstra(new_graph, i);
    for (size_t j = 0; j < size; ++j) {
      result[i][j] = dijkstra_distances[j] + potencials[j] - potencials[i];
    }
  }

  return result;
}