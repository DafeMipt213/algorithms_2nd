#include "sparse_table.hpp"

SparseTable::SparseTable(std::vector<int> &data) : data_(data) {
  int n = (int)data.size();
  int max_pow = Log2(n) + 1;

  table_ = std::vector<std::vector<int>>(max_pow, std::vector<int>(n, 0));
  table_[0] = data_;
  for (int k = 0; k + 1 < max_pow; ++k) {
    for (int index = 0; index + (1 << k) < n; index++) {
      table_[k + 1][index] = table_[k][index] < table_[k][index + (1 << k)]
                                 ? table_[k][index]
                                 : table_[k][index + (1 << k)];
      // можно воспользоваться min(table_[k][index], table[k][index + (1 <<
      // k)]), но я прочитал в интернете, что функция min работает медленнее,
      // чем тернарный оператор (разница примерно в 2 раза)
    }
  }
}

int SparseTable::FindMin(int left, int right) {
  int power = Log2(right - 1);
  return std::min(table_[power][left], table_[power][right - (1 << power)]);
}