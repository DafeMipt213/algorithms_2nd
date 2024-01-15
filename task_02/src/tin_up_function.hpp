#pragma once

#include <abstract_function.hpp>
#include <vector>

class TinUpFunction : public AbstractFunction {
 public:
  TinUpFunction(size_t n) : timer_{0}, tin_(n), up_(n), children_(n) {}

  void OnEdgeVisited(size_t from, size_t to, bool is_root) override {
    up_[from] = std::min(up_[from], tin_[to]);
  }

  void OnVertexBefore(size_t vertex, size_t parent) override {
    tin_[vertex] = up_[vertex] = timer_++;
  }

 protected:
  unsigned long long timer_;
  std::vector<unsigned long long> tin_;
  std::vector<unsigned long long> up_;
  std::vector<unsigned long long> children_;
};