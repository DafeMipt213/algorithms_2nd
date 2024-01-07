#pragma once

#include <vector>

// Запрос - О(1), препроцессинг - О(n)
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

  int MinHeight(int i, int j) {
    return heights_[eulerian_tour_[i]] < heights_[eulerian_tour_[j]] ? i : j;
  }

  void DFS(int vertex, int parent, int current_height);
  void BuildLCA();
  int LCAInBlock(int b, int l, int r);

 public:
  Solution(std::vector<int> &data);
  Solution(std::vector<std::vector<int>> &data);
  int LCA(int v, int u);
};