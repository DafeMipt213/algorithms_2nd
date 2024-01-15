#include "RMQ.hpp"

RMQ::RMQ(const std::vector<int>& arr) {
  int size = arr.size();
  int log = static_cast<int>(log2(size)) + 1;

  sparse_table_.assign(size, std::vector<int>(log, 0));

  for (int i = 0; i < size; ++i) sparse_table_[i][0] = arr[i];

  for (int j = 1; pow(2, j) <= size; ++j)
    for (int i = 0; i + pow(2, j) - 1 < size; ++i)
      sparse_table_[i][j] = std::min(sparse_table_[i][j - 1],
                                     sparse_table_[i + pow(2, j - 1)][j - 1]);
}

int RMQ::Run(int left, int right) {
  int k = static_cast<int>(log2(right - left + 1));
  return std::min(sparse_table_[left][k],
                  sparse_table_[right - pow(2, k) + 1][k]);
}