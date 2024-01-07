#include "treap.hpp"

int CartesianTree::Size(Node *node) { return node ? node->size : 0; }

void CartesianTree::Update(Node *node) {
  if (node) node->size = 1 + Size(node->left) + Size(node->right);
}

Node *CartesianTree::Merge(Node *left, Node *right) {
  if (!left || !right) return left ? left : right;
  if (left->priority > right->priority) {
    left->right = Merge(left->right, right);
    Update(left);
    return left;
  } else {
    right->left = Merge(left, right->left);
    Update(right);
    return right;
  }
}

void CartesianTree::Split(Node *node, int k, Node *&left, Node *&right) {
  if (!node) {
    left = right = nullptr;
    return;
  }
  if (Size(node->left) < k) {
    Split(node->right, k - Size(node->left) - 1, node->right, right);
    left = node;
  } else {
    Split(node->left, k, left, node->left);
    right = node;
  }
  Update(left);
  Update(right);
}

int CartesianTree::Get(int index) {
  Node *less;
  Node *equal;
  Node *greater;
  Split(root_, index, less, greater);
  Split(greater, 1, equal, greater);
  int result = equal->value;
  root_ = Merge(Merge(less, equal), greater);
  return result;
}

void CartesianTree::PushBack(int value) {
  root_ = Merge(root_, new Node(value));
}

CartesianTree::CartesianTree(std::vector<int> &data) {
  for (auto element : data) PushBack(element);
}