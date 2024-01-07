#pragma once

#include "treap.hpp"

class Solution {
  std::vector<int> heights_;
  std::vector<int> eulerian_tour_;
  std::vector<int> eulerian_tour_position_;

  std::vector<std::vector<int>> adjacency_list_;

  std::vector<std::vector<int>> sparse_table_;
  std::vector<int> block_hashes_;
  std::vector<std::vector<std::vector<int>>> block_rmq_;

  std::vector<int> log_2_;

  int block_size_;
  int block_count_;
  int root_ = -1;

  CartesianTree tree;

  int MinHeight(int i, int j) {
    return heights_[eulerian_tour_[i]] < heights_[eulerian_tour_[j]] ? i : j;
  }

  void ConvertTree(Node *node, Node *parent);
  void DFS(int vertex, int parent, int current_height);
  void DFS(Node *vertex, int current_height);
  void BuildLCA();
  int LCAInBlock(int b, int l, int r);
  int Log2(int value) { return 31 - __builtin_clz(value); }

 public:
  Solution(std::vector<int> &data);
  int LCA(int v, int u);
  int RMQ(int left, int right);
};
