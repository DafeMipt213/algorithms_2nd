#include <unordered_map>
#include <vector>

#include "rmq.hpp"
class Node {
 public:
  std::vector<Node*> children{};
  size_t height{1};
  size_t inc{0};
  bool visited{false};
  size_t id;
  size_t ap_ind;
  Node(size_t id) : id(id) {}
  void setNodes(std::vector<Node*> nodes) {
    children = nodes;
    for (auto& child : children) child->inc++;
  }
};

class LCA {
 private:
  std::vector<size_t> order;
  std::vector<size_t> heights;
  std::unordered_map<size_t, size_t> appear;
  std::vector<Node*> graph;
  Node* find_root() {
    for (auto& node : graph)
      if (node->inc == 0) return node;
  }
  void dfs(Node* node, size_t height = 1);

 public:
  size_t findLCA(size_t id1, size_t id2);
  LCA(std::vector<Node*> nodes) : graph(nodes) { dfs(find_root()); }
};
