#pragma once

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#define INF std::numeric_limits<int>::max()

struct Edge {
  size_t start, end, weight;
};

class Graph {
 public:
  Graph(size_t size) : nvertices_(size) {}

  void AddEdge(size_t start, size_t end, size_t weight) {
    edges_.push_back({start, end, weight});
  }

  std::vector<int> Dijkstra(int start) {
    std::vector<int> distance(nvertices_, INF);
    distance[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    pq.push({start, 0});

    while (!pq.empty()) {
      int u = pq.top().first;
      pq.pop();

      for (const auto& edge : edges_) {
        if (edge.start == u) {
          int v = edge.end;
          int w = edge.weight;
          if (distance[u] != INF && distance[u] + w < distance[v]) {
            distance[v] = distance[u] + w;
            pq.push({v, distance[v]});
          }
        }
      }
    }

    return distance;
  }

  std::vector<int> FordBellman(int start) {
    std::vector<int> distance(nvertices_, INF);
    distance[start] = 0;
    for (size_t i = 0; i < nvertices_ - 1; ++i) {
      for (const auto& edge : edges_) {
        if (distance[edge.start] != INF &&
            distance[edge.start] + edge.weight < distance[edge.end]) {
          distance[edge.start] = distance[edge.end] + edge.weight;
        }
      }
    }

    for (const auto& edge : edges_) {
      if (distance[edge.start] != INF &&
          distance[edge.start] + edge.weight < distance[edge.end]) {
        std::cout << "Graph has negative cycle\n";
        return {};
      }
    }
    return distance;
  }

  std::vector<std::vector<int>> Johnson() {
    for (size_t i = 0; i < nvertices_; ++i)
      edges_.push_back({nvertices_, i, 0});
    std::vector<int> current_vec = FordBellman(nvertices_);
    std::vector<std::vector<int>> distance_matrix(
        nvertices_, std::vector<int>(nvertices_, INF));
    for (auto& edge : edges_)
      if (current_vec[edge.start] != INF && current_vec[edge.start] != INF)
        edge.weight =
            edge.weight + current_vec[edge.start] - current_vec[edge.end];

    for (size_t i = 0; i < nvertices_; ++i) {
      std::vector<int> distance = Dijkstra(i);
      for (size_t j = 0; j < nvertices_; ++j)
        if (distance[j] != INF)
          distance_matrix[i][j] = distance[j] + current_vec[j] - current_vec[i];
    }

    return distance_matrix;
  }

 private:
  size_t nvertices_;
  std::vector<Edge> edges_;
};