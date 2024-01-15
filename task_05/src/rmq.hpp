#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#define INF std::numeric_limits<int>::max()

class SegmentTree {
 private:
  std::vector<int> tree_;
  int size_;

  int LeftChild(int i) { return 2 * i + 1; }

  int RightChild(int i) { return 2 * i + 2; }

  void BuildSegmentTree(const std::vector<int>& arr, int root, int left,
                        int right) {
    if (left == right) {
      tree_[root] = arr[left];
    } else {
      int mid = left + (right - left) / 2;
      BuildSegmentTree(arr, LeftChild(root), left, mid);
      BuildSegmentTree(arr, RightChild(root), mid + 1, right);
      tree_[root] = std::min(tree_[LeftChild(root)], tree_[RightChild(root)]);
    }
  }

  int QuerySegmentTree(int root, int left, int right, int query_left,
                       int query_right) {
    if (query_left > right || query_right < left) {
      return INF;
    }
    if (query_left <= left && query_right >= right) {
      return tree_[root];
    }
    int mid = left + (right - left) / 2;
    return std::min(
        QuerySegmentTree(LeftChild(root), left, mid, query_left, query_right),
        QuerySegmentTree(RightChild(root), mid + 1, right, query_left,
                         query_right));
  }

 public:
  SegmentTree(const std::vector<int>& arr) {
    size_ = arr.size();
    int height = static_cast<int>(ceil(log2(size_)));
    int tree_size = 2 * static_cast<int>(pow(2, height)) - 1;
    tree_.resize(tree_size);
    BuildSegmentTree(arr, 0, 0, size_ - 1);
  }

  int query(int query_left, int query_right) {
    return QuerySegmentTree(0, 0, size_ - 1, query_left, query_right);
  }
};