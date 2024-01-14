#include "lca.hpp"

void DFS(BinTree &t, std::vector<int> &idxs, size_t k = 0) {
  idxs.push_back(k);
  if (t.LeftChld(k) < t.data_.size()) {
    DFS(t, idxs, t.LeftChld(k));
    idxs.push_back(k);
  }
  if (t.RightChld(k) < t.data_.size()) {
    DFS(t, idxs, t.RightChld(k));
    idxs.push_back(k);
  }
}

std::vector<int> DoVectorIndexes(BinTree &t) {
  size_t k = 0;
  std::vector<int> idxs;
  DFS(t, idxs, k);
  return idxs;
}

int LCA(BinTree t, size_t l, size_t m) {
  if (l > m)
    throw std::runtime_error("LCA - wrong indexes");
  return RMQ(DoVectorIndexes(t), l, m);
}