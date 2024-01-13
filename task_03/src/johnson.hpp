#pragma once

#include <map>
#include <vector>

struct Edge {
  int from;
  int to;
  long long weight;
};

class Graph {
  std::vector<int> vertexes_;
  std::vector<Edge> edges_;
  std::map<int, long long> distances_;
  std::map<int, long long> values_;
  std::map<int, std::vector<std::pair<int, long long>>> adjacency_map_;
  bool is_cycled = false;

  void PrepareGraph();
  void ChangeEdges();

 public:
  Graph() = default;
  Graph(std::vector<int> vertexes) : vertexes_(vertexes){};
  ~Graph() = default;

  void AddEdge(int from, int to, long long weight);
  void AddVertex(int vertex);
  bool BellmanFord(int vertex);
  std::map<int, long long> Dijkstra(int vertex);
  std::map<int, std::map<int, long long>> Johnson();
};
