#pragma once
#include <unordered_map>
#include <vector>
struct Node {
  size_t id;
  std::vector<size_t> out;
  size_t in = 0;
  Node(size_t id, std::vector<size_t> out) : id(id), out(out) {}
  Node() = default;
};

class Graph {
 public:
  std::unordered_map<size_t, Node> nodes;
  void countIncoming();
  Graph(std::vector<Node> nodes) {
    for (size_t i = 0; i < nodes.size(); ++i) this->nodes[nodes[i].id] = nodes[i];
    countIncoming();
  }
};

std::vector<size_t> topologySort(Graph& graph);
