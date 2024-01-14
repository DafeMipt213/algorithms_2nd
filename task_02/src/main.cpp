#include <iostream>

#include "task2.hpp"

int main() {
  Graph G;
  G.Add(2, 1);
  G.Add(3, 2);
  G.Add(1, 3);
  G.Add(4, 3);
  G.Add(5, 4);
  G.Add(6, 5);
  G.Add(4, 6);
  std::vector<std::pair<int, int>> b;
  std::vector<int> c;
  for (auto v : b)
    std::cout << v.first << " " << v.second << std::endl;
  std::cout << std::endl;
  for (auto v : c)
    std::cout << v << std::endl;
  std::cout << std::endl;
  return 0;
}
