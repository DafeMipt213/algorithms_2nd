#pragma once

#include <cmath>
#include <vector>

class RMQ {
  std::vector<std::vector<int>> minimum_table;

 public:
  RMQ(const std::vector<int>& input_vector);

  int findMin(const unsigned int left, const unsigned int right);
};