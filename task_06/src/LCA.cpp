#include "LCA.hpp"

LCA::LCA(const Tree& tree, int root) {
  int nodes_count = tree.size();
  first_occurrence_.resize(nodes_count);
  depth_level_.resize(nodes_count);
  euler_sequence_.reserve(2 * nodes_count);

  Dfs(root, -1, 0, tree);
  BuildSparseTable();
}

int LCA::Run(int u, int v) {
  int left = first_occurrence_[u];
  int right = first_occurrence_[v];

  if (left > right) std::swap(left, right);

  int log = static_cast<int>(log2(right - left + 1));

  int index_1 = sparse_table_[left][log];
  int index_2 = sparse_table_[right - pow(2, log) + 1][log];

  return (depth_level_[index_1] < depth_level_[index_2]) ? index_1 : index_2;
}

void LCA::Dfs(int node, int parent, int depth, const Tree& tree) {
  euler_sequence_.push_back(node);
  first_occurrence_[node] = euler_sequence_.size() - 1;
  depth_level_[node] = depth;

  for (int neighbor : tree[node])
    if (neighbor != parent) {
      Dfs(neighbor, node, depth + 1, tree);
      euler_sequence_.push_back(node);
    }
}

void LCA::BuildSparseTable() {
  int log = static_cast<int>(log2(euler_sequence_.size())) + 1;
  sparse_table_.assign(euler_sequence_.size(), std::vector<int>(log));

  for (int i = 0; i < euler_sequence_.size(); ++i)
    sparse_table_[i][0] = euler_sequence_[i];

  for (int j = 1; pow(2, j) <= euler_sequence_.size(); ++j)
    for (int i = 0; i + pow(2, j) - 1 < euler_sequence_.size(); ++i) {
      int left = sparse_table_[i][j - 1];
      int right = sparse_table_[i + pow(2, j - 1)][j - 1];
      sparse_table_[i][j] =
          (depth_level_[left] < depth_level_[right]) ? left : right;
    }
}