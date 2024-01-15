#include "rmq.hpp"

#include <cmath>
#include <stdexcept>

RMQ::RMQ(std::vector<long long>& numbers) {
  size_t size = std::ceil(std::log2(numbers.size() + 1));
  sparse_table_.assign(size + 1, std::vector<long long>());

  sparse_table_[0] = numbers;
  for (size_t k = 0; k < sparse_table_.size(); ++k) {
    for (size_t i = 0; i + (1 << k) < numbers.size(); ++i) {
      sparse_table_[k + 1].push_back(
          std::min(sparse_table_[k][i], sparse_table_[k][i + (1 << k)]));
    }
  }
}

long long RMQ::GetMin(const size_t left, const size_t right) const {
  if (left >= right) {
    throw std::runtime_error("uncorrect boundaries");
  }

  if (right > sparse_table_[0].size()) {
    throw std::out_of_range("out of range");
  }

  size_t power = std::floor(std::log2(right - left));
  return std::min(sparse_table_[power][left],
                  sparse_table_[power][right - (1 << power)]);
}