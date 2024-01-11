#include "LCA.hpp"


Node::Node(int val) : value(val), height(0), used(false) {}

BinaryTree::BinaryTree() :root(nullptr), rmq(RMQ(std::vector<int>())) {}

BinaryTree::~BinaryTree() { destroy_tree(); }

void BinaryTree::destroy_tree(Node* leaf) {
  if (leaf != nullptr) {
    destroy_tree(leaf->left_child);
    destroy_tree(leaf->right_child);
    delete leaf;
  }
}

void BinaryTree::destroy_tree() { destroy_tree(root); }

void BinaryTree::dfs_inner(int current_height, Node* current_vertex) {
  heights.push_back(current_height);
  values.push_back(current_vertex->value);
  current_vertex->height = current_height;
  current_vertex->used = true;
  indexes[current_vertex->value] = values.size();

  if (current_vertex->left_child != nullptr &&
      current_vertex->left_child->used == false) {
    dfs_inner(current_height + 1, current_vertex->left_child);
  }
  if (current_vertex->right_child != nullptr &&
      current_vertex->right_child->used == false) {
    dfs_inner(current_height + 1, current_vertex->right_child);
  }
}

int BinaryTree::findMin(int value1, int value2) {
  int left = std::min(indexes[value1], indexes[value2]);
  int right = std::max(indexes[value1], indexes[value2]);
  return rmq.findMin(left, right);
}

void BinaryTree::dfs() { dfs_inner(0, root); }

void BinaryTree::makeRmq() {
  dfs();
  rmq = RMQ(static_cast<std::vector<int>>(heights));
}