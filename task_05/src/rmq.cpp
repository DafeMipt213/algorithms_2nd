#include "tree.hpp"

int Tree::rmq(int left, int right, int x, int lx, int rx) {
  if (left <= lx and right >= rx)
    return tree[x];
  if (left >= rx or right <= lx)
    return INF;

  int mx = (lx + rx) / 2;
  return std::min(rmq(left, right, 2 * x + 1, lx, mx),
                  rmq(left, right, 2 * x + 2, mx, rx));
}