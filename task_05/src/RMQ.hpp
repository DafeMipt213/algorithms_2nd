#pragma once

#include <cmath>
#include <vector>

struct TableElement {
  int value;
  int index;
  TableElement(int val, int indx);
  bool operator>(const TableElement other) const;
  bool operator<(const TableElement other) const;
};

class RMQ {
  std::vector<std::vector<TableElement>> minimum_table;

 public:
  RMQ();
  RMQ(const std::vector<int>& input_vector);

  TableElement findMin(const unsigned int left, const unsigned int right);
};