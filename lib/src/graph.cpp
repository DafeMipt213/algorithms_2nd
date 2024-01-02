#include "graph.hpp"

Graph::Graph(std::vector<std::vector<size_t>> adjacency_list)
    : graph_{adjacency_list}, colors_(adjacency_list.size(), white) {}

void Graph::DFS(size_t vertex, size_t p, AbstractFunction* func) {
  if (colors_[vertex] != white) {
    return;
  }

  colors_[vertex] = gray;
  func->OnVertexBefore(vertex, p);

  for (auto u : graph_[vertex]) {
    if (u == p) {
      continue;
    }
    if (colors_[u] == white) {
      DFS(u, vertex, func);
      func->OnEdgeNotVisited(vertex, u);
    } else {
      func->OnEdgeVisited(vertex, u);
    }
  }

  colors_[vertex] = black;
  func->OnVertexAfter(vertex, p);
}

void Graph::BFS(size_t vertex, AbstractFunction* func) {}

std::vector<size_t>& Graph::operator[](const size_t i) { return graph_[i]; }

size_t Graph::Size() const { return graph_.size(); }

void Graph::ResetColors() { colors_.assign(graph_.size(), white); }