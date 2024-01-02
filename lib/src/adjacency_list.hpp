#pragma once

#include <cstddef>
#include <vector>

template <class T>
class AdjacencyList {
 public:
  AdjacencyList<T>(size_t n) : adjacency_list_(n) {}
  std::vector<T>& operator[](const size_t i) { return adjacency_list_[i]; }
  void push_back(const T& obj) { adjacency_list_.push_back(obj); }
  size_t size() const { return adjacency_list_.size(); }

 private:
  std::vector<std::vector<T>> adjacency_list_;
};