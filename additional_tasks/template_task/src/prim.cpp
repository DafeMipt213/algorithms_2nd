#include "prim.hpp"

#include <climits>
#include <set>
#include <stdexcept>

bool Vertex::operator>(const Vertex other_vertex) const {
  return other_vertex.weight < weight;
}

bool Vertex::operator<(const Vertex other_vertex) const {
  return other_vertex.weight < weight;
}

bool Vertex::operator==(const Vertex other_vertex) const {
  return other_vertex.weight == weight &&
         other_vertex.destination == destination;
}

Vertex::Vertex(int destination, int weight)
    : weight(weight), destination(destination) {}

std::vector<std::vector<Vertex>> prim(
    const std::vector<std::vector<Vertex>>& graph) {
  if (graph.size() == 0) {
    return {};
  }
  int no_edge = 0;
  std::vector<std::vector<Vertex>> res(graph.size());
  std::vector<int> colors(graph.size());
  colors[0] = 1;
  while (no_edge < graph.size() - 1) {
    int min = INT_MAX;
    int x = 0;
    int y = 0;
    for (size_t i = 0; i < graph.size(); i++) {
      if (colors[i]) {
        for (size_t j = 0; j < graph[i].size(); j++) {
          if (!colors[graph[i][j].destination]) {
            if (min > graph[i][j].weight) {
              min = graph[i][j].weight;
              x = static_cast<int>(i);
              y = static_cast<int>(j);
            }
          }
        }
      }
    }
    res[x].push_back(Vertex(graph[x][y].destination, graph[x][y].weight));
    res[graph[x][y].destination].push_back(Vertex(x, graph[x][y].weight));
    colors[graph[x][y].destination] = 1;
    no_edge++;
  }

  return res;
}