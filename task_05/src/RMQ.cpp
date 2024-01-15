#include "RMQ.hpp"

#include <stdexcept>

TableElement::TableElement(int val, int indx) : value(val), index(indx){};

bool TableElement::operator>(const TableElement other_element) const {
  return other_element.value < value;
}

bool TableElement::operator<(const TableElement other_element) const {
  return other_element.value > value;
}

RMQ::RMQ() {}

RMQ::RMQ(const std::vector<int>& input_vector) {
  const size_t pow = std::ceil(std::log2(input_vector.size()));
  const size_t pow_len = static_cast<size_t>(std::pow(2, pow));
  std::vector<TableElement> first_row;
  for (size_t i = 0; i < input_vector.size(); ++i) {
    first_row.push_back(TableElement(input_vector[i], static_cast<int>(i)));
  }
  for (size_t i = input_vector.size(); i < pow_len; ++i) {
    first_row.push_back(TableElement(__INT_MAX__, static_cast<int>(i)));
  }
  minimum_table.push_back(first_row);
  int curr_pow = 1;
  for (size_t i = 1; i < pow + 1; ++i) {
    minimum_table.push_back(std::vector<TableElement>());
    for (size_t j = 0; j < minimum_table[i - 1].size() - curr_pow; ++j) {
      minimum_table[i].push_back(minimum_table[i - 1][j] <
                                         minimum_table[i - 1][j + curr_pow]
                                     ? minimum_table[i - 1][j]
                                     : minimum_table[i - 1][j + curr_pow]);
    }
    curr_pow *= 2;
  }
}

TableElement RMQ::findMin(const unsigned int left, const unsigned int right) {
  if (left > right || left < 0 || right > minimum_table[0].size())
    throw std::out_of_range("wrong border arguments");
  const size_t row = std::floor(std::log2(right - left + 1));
  return std::min(
      minimum_table[row][left],
      minimum_table[row][static_cast<size_t>(right - std::pow(2, row) + 1)]);
}
