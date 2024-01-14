#include "lca.hpp"
void LCA::dfs(Node* node, size_t height) {
  node->visited = true;
  node->height = height;
  heights.push_back(node->height);
  order.push_back(node->id);
  appear[node->id] = order.size() - 1;
  for (size_t i = 0; i < node->children.size(); ++i)
    if (!node->children[i]->visited) {
      dfs(node->children[i], height + 1);
      order.push_back(node->id);
      heights.push_back(node->height);
    }
}

size_t LCA::findLCA(size_t id1, size_t id2) {
  return order[RMQ(heights, std::min(appear[id1], appear[id2]),
                   std::max(appear[id1], appear[id2]))
                   .ans.second];
}