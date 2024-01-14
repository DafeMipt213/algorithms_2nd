#include <algorithm>
#include <cmath>

#include "rmq.hpp"

std::vector<int> DoData(const std::vector<int> &massive) {
  int inf = std::numeric_limits<int>::infinity() + 1;
  size_t a = pow(2, ceil(std::log2(massive.size())));
  std::vector<int> data(2 * a - 1);
  std::copy(massive.begin(), massive.end(), data.end() - a);
  std::fill(data.end() - a + massive.size() - 1, data.end(), inf);
  for (size_t i = 0; i < a - 1; ++i)
    data[i] = std::min(data[2 * i + 1], data[2 * i + 2]);
  return data;
}

int Recursion(BinTree t, size_t l, size_t m, size_t i) {
  if (t.LeftChld(i) >= l && t.RightChld(i) <= m)
    return t.data_[i];
  int inf = std::numeric_limits<int>::infinity() + 1;
  if (t.LeftChld(i) > m || t.RightChld(i) < l)
    return inf;
  return std::min(Recursion(t, l, m, t.LeftChld(i)),
                  Recursion(t, l, m, t.RightChld(i)));
}

int RMQ(const std::vector<int> &massive, size_t l, size_t m) {
  if (l > m)
    throw std::runtime_error("RMQ - wrong indexes");
  size_t a = pow(2, ceil(std::log2(massive.size())));
  return Recursion(BinTree(DoData(massive)), l + a - 1, m + a - 1, 0);
}