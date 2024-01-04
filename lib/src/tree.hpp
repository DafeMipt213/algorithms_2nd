#pragma once

#include <climits>
#include <iostream>
#include <utility>
#include <vector>

const int INF = INT_MAX;

class Tree {
private:
  std::vector<int> tree;

public:
  explicit Tree(std::vector<int> t) : tree(std::move(t)) {}

private:
  void update(unsigned long ind);

  void remove(int ind, int value);

  int rmq(int left, int right, int x, int lx, int rx);

  int get_min(int ind);
};
