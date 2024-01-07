
#include <iostream>
#include <vector>

#include "rmq.hpp"

int main() {
  std::vector<int> numbers;
  int numbers_count;
  std::cin >> numbers_count;

  numbers.assign(numbers_count, -1);
  for (int i = 0; i < numbers_count; i++) std::cin >> numbers[i];

  Solution solution(numbers);
  int left, right;
  std::cin >> left >> right;
  std::cout << solution.RMQ(left, right);
  return 0;
}
