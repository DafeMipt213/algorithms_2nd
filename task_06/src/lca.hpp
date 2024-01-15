#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class LCA {
 public:
  LCA(const std::vector<std::vector<int>>& adj) {
    size_ = adj.size();
    logN_ = static_cast<int>(ceil(log2(size_)));

    parent_.assign(size_, std::vector<int>(logN_ + 1, -1));
    depth_.assign(size_, 0);

    Dfs(0, -1, 0, adj);
  }

  void Dfs(int node, int par, int d, const std::vector<std::vector<int>>& adj) {
    parent_[node][0] = par;
    depth_[node] = d;

    for (int i = 1; i <= logN_; ++i)
      if (parent_[node][i - 1] != -1)
        parent_[node][i] = parent_[parent_[node][i - 1]][i - 1];

    for (int child : adj[node])
      if (child != par) Dfs(child, node, d + 1, adj);
  }
  int FindLCA(int u, int v) {
    if (depth_[u] > depth_[v]) {
      std::swap(u, v);
    }

    for (int i = logN_; i >= 0; --i)
      if (depth_[v] - (1 << i) >= depth_[u]) v = parent_[v][i];
    if (u == v) return u;

    for (int i = logN_; i >= 0; --i)
      if (parent_[u][i] != parent_[v][i]) {
        u = parent_[u][i];
        v = parent_[v][i];
      }

    return parent_[u][0];
  }

 private:
  int size_;
  std::vector<std::vector<int>> parent_;
  std::vector<int> depth_;
  int logN_;
};