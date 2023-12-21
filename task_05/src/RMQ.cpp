#include "RMQ.hpp"

#include <cmath>

int SolveRMQ::GetLog(int len) {
  if (len <= 1) return 0;
  return GetLog(len / 2) + 1;
}

SolveRMQ::SolveRMQ(const std::vector<int>& data) {
  SparseTable = std::vector<std::vector<int>>(GetLog(data.size()) + 1,
                                              std::vector<int>(data.size()));
  SparseTable[0] = data;
  for (size_t i = 1; i < SparseTable.size(); ++i)
    for (size_t j = 0; j < data.size(); ++j)
      if (j + std::pow(2, i - 1) < data.size())
        SparseTable[i][j] =
            (SparseTable[i - 1][j] < SparseTable[i - 1][j + std::pow(2, i - 1)])
                ? SparseTable[i - 1][j]
                : SparseTable[i - 1][j + std::pow(2, i - 1)];
      else
        SparseTable[i][j] = (SparseTable[i - 1][j] < SparseTable[i - 1].back())
                                ? SparseTable[i - 1][j]
                                : SparseTable[i - 1].back();
}

int SolveRMQ::GitMinimum(size_t start, size_t end) {
  int j = GetLog(end - start);
  if (end - std::pow(2, j) + 1 < SparseTable[j].size())
    return (SparseTable[j][start] < SparseTable[j][end - std::pow(2, j) + 1])
               ? SparseTable[j][start]
               : SparseTable[j][end - std::pow(2, j) + 1];
  else
    return (SparseTable[j][start] < SparseTable[j].back())
               ? SparseTable[j][start]
               : SparseTable[j].back();
}