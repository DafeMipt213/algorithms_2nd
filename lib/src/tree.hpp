#include <cstddef>
#include <stdexcept>
#include <vector>
#include <limits>

class BinTree {
public:
  BinTree(const std::vector<int> &data) : data_{data} {}

  size_t Parent(size_t i) {
    if (i == 0 || i >= data_.size())
      throw std::runtime_error("BinTree::Parent - wrong index");
    return (i - 1) / 2;
  }
  size_t LeftChld(size_t i) {
    size_t inf = std::numeric_limits<int>::infinity() + 1;
    if (i > Parent(data_.size() - 1))
      return inf;
    return 2 * i + 1;
  }
  size_t RightChld(size_t i) {
    size_t inf = std::numeric_limits<int>::infinity() + 1;
    if (2 * i + 1 >= data_.size() - 1)
      return inf;
    return 2 * i + 2;
  }

  std::vector<int> data_;
};