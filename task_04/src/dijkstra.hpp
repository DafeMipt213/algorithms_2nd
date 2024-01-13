#pragma once
#include <unordered_map>
#include <vector>
struct Edge {
  size_t weight;
  size_t index_to;
  Edge(size_t index_to, size_t weight) : weight(weight), index_to(index_to) {}
};

struct Node {
  size_t id;
  std::vector<Edge> edges;
  int prevIndex{-1};
  size_t weight;
  bool visited;
  Node(size_t id, std::vector<Edge> edges = {}) : id(id), edges(edges) {}
  Node() = default;
};

struct Graph {
  std::unordered_map<size_t, Node> nodes;
  int V;
  void init() {
    for (auto& elem : nodes) {
      Node* node = &(elem.second);
      node->weight = 10000000;
      node->visited = false;
      node->prevIndex = -1;
    }
  }
  Graph(std::vector<Node> nodes) {
    for (size_t i = 0; i < nodes.size(); ++i)
      this->nodes[nodes[i].id] = nodes[i];
    V = nodes.size();
  }
  void addEdge(size_t index_from, size_t index_to, size_t weight,
               bool reversed = false) {
    nodes[index_from].edges.push_back(Edge(index_to, weight));
    if (reversed) nodes[index_to].edges.push_back(Edge(index_from, weight));
  }

  void removeExtraNode(int id) {
    V--;
    nodes.erase(id);
  }
};
class Dijkstra {
 public:
  std::vector<size_t> path;
  size_t length;
  Dijkstra(Graph& graph, size_t start, size_t finish) {
    path = findPath(graph, start, finish);
  }

 private:
  std::vector<size_t> findPath(Graph& graph, size_t start, size_t finish);
};