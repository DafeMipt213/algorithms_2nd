#include <iostream>
#include <stack>
#include <vector>

#include "rmq.hpp"

int main() {
  std::vector<int> indx{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> data{7, 9, 8, 6, 1, 4, 5, 2, 3};

  Solution solution(data);
  // // std::vector<std::vector<int>> graph{
  // // {1, 2, 3}, {0, 4, 5}, {0, 7}, {0, 6}, {1, 9}, {1, 8}, {3}, {2}, {5},
  // {4}}; std::vector<std::vector<int>> graph{{1, 2, 3}, {0, 4, 5}, {0}, {0,
  // 6}, {1, 7},
  //                                     {1, 8},    {3},       {4}, {5}};

  // Solution solution(data);
  // int left = 1, right = 5;
  std::cout << solution.LCA(5, 8) << "\n";
  // std::cout << data[solution.LCA(left, right)] << "\n";
  // return 0;
}
