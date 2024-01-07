#pragma once

#include <random>
#include <vector>

static std::minstd_rand generator;

struct Node {
  int priority;
  int value;
  int size = 1;
  Node *left = nullptr;
  Node *right = nullptr;
  Node(int value) : priority(generator()), value(value){};
};

class CartesianTree {
  Node *root_ = nullptr;

  void Split(Node *node, int key, Node *&left, Node *&right);
  Node *Merge(Node *left, Node *right);
  void Update(Node *node);
  int Size(Node *node);

 public:
  CartesianTree() = default;
  CartesianTree(std::vector<int> &data);
  int Get(int index);
  void PushBack(int value);
  Node *Build(int *data, int size);
  void Heapify(Node *node);
  friend class Solution;
};