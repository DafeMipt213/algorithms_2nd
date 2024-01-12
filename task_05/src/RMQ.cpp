#include "RMQ.hpp"

#include <cmath>

int RmqSolver::GetLog(int len) {
  if (len <= 1) return 0;
  return GetLog(len / 2) + 1;
}

RmqSolver::RmqSolver(const std::vector<int>& data) {
  sparse_table = std::vector<std::vector<int>>(GetLog(data.size()) + 1,
                                               std::vector<int>(data.size()));
  sparse_table[0] = data;
  for (size_t i = 1; i < sparse_table.size(); ++i)
    for (size_t j = 0; j < data.size(); ++j)
      if (j + std::pow(2, i - 1) < data.size())
        sparse_table[i][j] = (sparse_table[i - 1][j] <
                              sparse_table[i - 1][j + std::pow(2, i - 1)])
                                 ? sparse_table[i - 1][j]
                                 : sparse_table[i - 1][j + std::pow(2, i - 1)];
      else
        sparse_table[i][j] =
            (sparse_table[i - 1][j] < sparse_table[i - 1].back())
                ? sparse_table[i - 1][j]
                : sparse_table[i - 1].back();
}

int RmqSolver::GitMinimum(size_t start, size_t end) {
  int j = GetLog(end - start);
  if (end - std::pow(2, j) + 1 < sparse_table[j].size())
    return (sparse_table[j][start] < sparse_table[j][end - std::pow(2, j) + 1])
               ? sparse_table[j][start]
               : sparse_table[j][end - std::pow(2, j) + 1];
  else
    return (sparse_table[j][start] < sparse_table[j].back())
               ? sparse_table[j][start]
               : sparse_table[j].back();
}