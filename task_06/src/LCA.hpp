#pragma once

#include <cmath>
#include <iostream>
#include <vector>

using Tree = std::vector<std::vector<int>>;

class LCA {
 public:
  LCA(const Tree& tree, int root);

  int Run(int u, int v);

 private:
  void Dfs(int node, int parent, int depth, const Tree& tree);
  void BuildSparseTable();

  std::vector<int> euler_sequence_;
  std::vector<int> first_occurrence_;
  std::vector<int> depth_level_;
  std::vector<std::vector<int>> sparse_table_;
};