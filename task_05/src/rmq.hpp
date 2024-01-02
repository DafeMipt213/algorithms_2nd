#pragma once

#include <vector>

class RMQ {
 public:
  RMQ(std::vector<long long>& numbers);
  long long GetMin(const size_t left, const size_t right) const;

 private:
  std::vector<std::vector<long long>> sparse_table_;
};