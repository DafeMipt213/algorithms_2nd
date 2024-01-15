#include <iostream>
#include <vector>

#include "prim.hpp"

int main() {
  std::vector<std::vector<Vertex>> graph{
      {{1, 1}, {2, 7}, {3, 3}, {4, 7}, {5, 10}, {6, 1}},
      {{0, 1}, {2, 3}, {3, 1}},
      {{0, 7}, {1, 3}, {3, 4}},
      {{0, 3}, {1, 1}, {2, 4}, {4, 2}},
      {{3, 2}, {0, 7}, {5, 3}},
      {{4, 3}, {0, 10}, {6, 4}},
      {{0, 1}, {5, 4}}};
  std::vector<std::vector<Vertex>> tree = prim(graph);
  return 0;
}
