#include "rmq.hpp"

Solution::Solution(std::vector<int> &data) {
  int size = data.size();
  heights_.assign(size, 0);
  eulerian_tour_.reserve(2 * size);
  eulerian_tour_position_.assign(size, -1);
  adjacency_list_.assign(size, std::vector<int>());

  // generate cartesian tree
  std::vector<int> parent(data.size(), -1);
  std::stack<int> s;
  for (int i = 0; i < data.size(); i++) {
    int last = -1;
    while (!s.empty() && data[s.top()] >= data[i]) {
      last = s.top();
      s.pop();
    }
    if (!s.empty()) parent[i] = s.top();
    if (last >= 0) parent[last] = i;
    s.push(i);
  }

  for (int i = 0; i < size; i++) {
    adjacency_list_[i].push_back(parent[i]);
    if (parent[i] != -1) adjacency_list_[parent[i]].push_back(i);
    if (parent[i] == -1) root_ = i;
  }

  DFS(root_, -1, 0);
  BuildLCA();
}

void Solution::DFS(int vertex, int parent, int current_height) {
  eulerian_tour_position_[vertex] = (int)eulerian_tour_.size();
  eulerian_tour_.push_back(vertex);
  heights_[vertex] = current_height;

  for (int u : adjacency_list_[vertex]) {
    if (u == parent) continue;
    DFS(u, vertex, current_height + 1);
    eulerian_tour_.push_back(vertex);
  }
}

void Solution::BuildLCA() {
  int m = (int)eulerian_tour_.size();

  log_2_.reserve(m + 1);
  log_2_.push_back(-1);

  for (int i = 1; i <= m; i++) log_2_.push_back(log_2_[i / 2] + 1);

  block_size_ = std::max(1, log_2_[m] / 2);
  block_count_ = (m + block_size_ - 1) / block_size_;

  sparse_table_.assign(block_count_,
                       std::vector<int>(log_2_[block_count_] + 1));
  for (int i = 0, j = 0, b = 0; i < m; i++, j++) {
    if (j == block_size_) j = 0, ++b;
    if (j == 0 || MinHeight(i, sparse_table_[b][0]) == i)
      sparse_table_[b][0] = i;
  }
  for (int l = 1; l <= log_2_[block_count_]; l++) {
    for (int i = 0; i < block_count_; i++) {
      int ni = i + (1 << (l - 1));
      if (ni >= block_count_)
        sparse_table_[i][l] = sparse_table_[i][l - 1];
      else
        sparse_table_[i][l] =
            MinHeight(sparse_table_[i][l - 1], sparse_table_[ni][l - 1]);
    }
  }

  block_hashes_.assign(block_count_, 0);
  for (int i = 0, j = 0, b = 0; i < m; i++, j++) {
    if (j == block_size_) j = 0, ++b;
    if (j > 0 && (i >= m || MinHeight(i - 1, i) == i - 1))
      block_hashes_[b] += 1 << (j - 1);
  }

  int possibilities = 1 << (block_size_ - 1);
  block_rmq_.resize(possibilities);
  for (int b = 0; b < block_count_; b++) {
    int mask = block_hashes_[b];
    if (!block_rmq_[mask].empty()) continue;
    block_rmq_[mask].assign(block_size_, std::vector<int>(block_size_));
    for (int l = 0; l < block_size_; l++) {
      block_rmq_[mask][l][l] = l;
      for (int r = l + 1; r < block_size_; r++) {
        block_rmq_[mask][l][r] = block_rmq_[mask][l][r - 1];
        if (b * block_size_ + r < m)
          block_rmq_[mask][l][r] =
              MinHeight(b * block_size_ + block_rmq_[mask][l][r],
                        b * block_size_ + r) -
              b * block_size_;
      }
    }
  }
}

int Solution::LCAInBlock(int b, int l, int r) {
  return block_rmq_[block_hashes_[b]][l][r] + b * block_size_;
}

int Solution::LCA(int v, int u) {
  int l = eulerian_tour_position_[v];
  int r = eulerian_tour_position_[u];
  if (l > r) std::swap(l, r);
  int block_l = l / block_size_;
  int block_r = r / block_size_;
  if (block_l == block_r)
    return eulerian_tour_[LCAInBlock(block_l, l % block_size_,
                                     r % block_size_)];
  int answer_l = LCAInBlock(block_l, l % block_size_, block_size_ - 1);
  int answer_r = LCAInBlock(block_r, 0, r % block_size_);
  int answer = MinHeight(answer_l, answer_r);

  if (block_l + 1 < block_r) {
    int l = log_2_[block_r - block_l - 1];
    int answer3 = sparse_table_[block_l + 1][l];
    int answer4 = sparse_table_[block_r - (1 << l)][l];
    answer = MinHeight(answer, MinHeight(answer3, answer4));
  }
  return eulerian_tour_[answer];
}

int Solution::RMQ(int left, int right) { return LCA(left, right); }