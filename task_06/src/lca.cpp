#include "lca.hpp"

#include <cstddef>
#include <graph.hpp>
#include <vector>

class LcaFunction : public AbstractFunction {
 public:
  LcaFunction(size_t n, size_t root) : heigths_(n) { heigths_[root] = 0; }

  void OnEdgeNotVisited(size_t from, size_t to, bool is_root) override {
    lca_dfs_list_.push_back(from);
  }

  void OnEdgeVisited(size_t from, size_t to, bool is_root) override {}

  void OnVertexBefore(size_t vertex, size_t parent) override {
    lca_dfs_list_.push_back(vertex);
    if (parent == -1) {
      heigths_[vertex] = 0;
    } else {
      heigths_[vertex] = heigths_[parent] + 1;
    }
  }

  void OnVertexAfter(size_t vertex, size_t parent) override {}

  std::vector<size_t> GetDfsList() { return lca_dfs_list_; }

  std::vector<long long> GetHeights() { return heigths_; }

 private:
  std::vector<size_t> lca_dfs_list_;
  std::vector<long long> heigths_;
};

LCA::LCA(Graph<size_t>& graph, size_t root) : heigths_(graph.Size()) {
  LcaFunction f(graph.Size(), root);
  graph.DFS(root, -1, true, &f);

  dfs_list_ = f.GetDfsList();
  heigths_ = f.GetHeights();

  segments_tree_.assign(dfs_list_.size() * 4 + 1, -1);
  BuildTree(1, 0, dfs_list_.size() - 1);

  first_.assign(graph.Size(), -1);

  for (size_t i = 0; i < dfs_list_.size(); ++i) {
    size_t v = dfs_list_[i];
    if (first_[v] == -1) {
      first_[v] = i;
    }
  }
}

void LCA::BuildTree(size_t i, size_t left, size_t right) {
  if (left == right) {
    segments_tree_[i] = dfs_list_[left];
  } else {
    size_t mid = (left + right) / 2;
    BuildTree(2 * i, left, mid);
    BuildTree(2 * i + 1, mid + 1, right);
    if (heigths_[segments_tree_[2 * i]] < heigths_[segments_tree_[2 * i + 1]]) {
      segments_tree_[i] = segments_tree_[2 * i];
    } else {
      segments_tree_[i] = segments_tree_[2 * i + 1];
    }
  }
}

size_t LCA::MinFromTree(size_t i, size_t s_left, size_t s_right, size_t left,
                        size_t right) {
  if (s_left == left && s_right == right) return segments_tree_[i];
  int s_mid = (s_left + s_right) >> 1;
  if (right <= s_mid) return MinFromTree(i + i, s_left, s_mid, left, right);
  if (left > s_mid)
    return MinFromTree(i + i + 1, s_mid + 1, s_right, left, right);
  int ans1 = MinFromTree(i + i, s_left, s_mid, left, s_mid);
  int ans2 = MinFromTree(i + i + 1, s_mid + 1, s_right, s_mid + 1, right);
  return heigths_[ans1] < heigths_[ans2] ? ans1 : ans2;
}

size_t LCA::GetLCA(size_t a, size_t b) {
  size_t left = first_[a];
  size_t right = first_[b];
  if (left > right) {
    std::swap(left, right);
  }
  return MinFromTree(1, 0, dfs_list_.size() - 1, left, right);
}