#pragma once

#include <cmath>
#include <vector>

class RMQ {
 public:
  RMQ(const std::vector<int>& arr);

  int Run(int left, int right);

 private:
  std::vector<std::vector<int>> sparse_table_;
};