#include "tree.hpp"
void Tree::update(unsigned long ind) {
  if (ind <= 0)
    return;

  unsigned long prev = (ind - 1) / 2;
  tree[prev] = std::min(tree[prev * 2 + 1], tree[prev * 2 + 2]);
  update(prev);
}
void Tree::remove(int ind, int value) {
  unsigned long k = tree.size() / 2;
  tree[k + ind] -= value;
  update(k + ind);
}
int Tree::get_min(int ind) {
  if (ind >= (tree.size() / 2))
    return tree[ind];

  tree[2 * ind + 1] = get_min(2 * ind + 1);
  tree[2 * ind + 2] = get_min(2 * ind + 2);
  return std::min(tree[2 * ind + 1], (tree[2 * ind + 2]));
}