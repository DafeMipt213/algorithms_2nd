#include "rmq.hpp"
int fl(size_t len) {
  if (len == 1)
    return 0;
  else
    return fl(len / 2) + 1;
}

std::pair<size_t, size_t> f(std::vector<size_t>& data, size_t i, size_t k) {
  if (k <= 0)
    return {data[i], i};
  else
    return std::min(f(data, i, k - 1), f(data, i + pow(2, k - 1), k - 1));
}

std::vector<std::vector<std::pair<size_t, size_t>>> preproc(
    std::vector<size_t>& data) {
  std::vector<std::vector<std::pair<size_t, size_t>>> ans;
  for (size_t i = 0; i < data.size(); ++i) {
    std::vector<std::pair<size_t, size_t>> temp;
    for (size_t j = 0; j <= fl(data.size() - i); ++j)
      temp.push_back(f(data, i, j));
    while (temp.size() < fl(data.size()) + 1) temp.push_back(temp.back());
    ans.push_back(temp);
  }
  return ans;
}

std::pair<size_t, size_t> RMQ::findRMQ(std::vector<size_t>& data, size_t l,
                                       size_t r) {
  size_t i = fl(r - l + 1);
  size_t id_ans = 0;
  std::vector<std::vector<std::pair<size_t, size_t>>> sparse_table =
      preproc(data);
  if (l == r) {
    return {sparse_table[l][0]};
  }
  return std::min(sparse_table[l][i], sparse_table[r - std::pow(2, i) + 1][i]);
}