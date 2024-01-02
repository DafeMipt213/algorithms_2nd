#pragma once

#include <cstddef>

class AbstractFunction {
 public:
  virtual void OnEdgeVisited(size_t from, size_t to) = 0;
  virtual void OnEdgeNotVisited(size_t from, size_t to) = 0;
  virtual void OnVertexBefore(size_t vertex, size_t p) = 0;
  virtual void OnVertexAfter(size_t vertex, size_t p) = 0;
};