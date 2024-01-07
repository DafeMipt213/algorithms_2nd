#pragma once

#include <vector>

// Запрос - О(1), препроцессинг - О(nlog(n))
class SparseTable {
  std::vector<std::vector<int>> table_;
  std::vector<int> data_;

 public:
  SparseTable(std::vector<int> &data);
  int Log2(int value) { return 31 - __builtin_clz(value); }
  int FindMin(int left, int right);
};
