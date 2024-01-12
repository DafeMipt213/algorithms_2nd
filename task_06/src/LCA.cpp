#include "LCA.hpp"

#include "../../task_05/src/RMQ.cpp"

Node::Node(int val)
    : value(val),
      height(0),
      used(false),
      left_child(nullptr),
      right_child(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() { destroy_tree(); }

void BinaryTree::destroy_tree(Node* leaf) {
  if (leaf != nullptr) {
    destroy_tree(leaf->left_child);
    destroy_tree(leaf->right_child);
    delete leaf;
  }
}

void BinaryTree::destroy_tree() { destroy_tree(root); }

void BinaryTree::dfs_inner(int current_height, Node* current_vertex, int& cnt) {
  if (current_vertex == nullptr) return;
  current_vertex->height = current_height;
  current_vertex->used = true;

  if (current_vertex->left_child != nullptr &&
      current_vertex->left_child->used == false) {
    dfs_inner(current_height + 1, current_vertex->left_child, cnt);
  }
  heights.push_back(current_height);
  values.push_back(current_vertex->value);
  if (indexes.find(current_vertex->value) != indexes.cend())
    throw std::out_of_range("values must be unique");
  indexes[current_vertex->value] = static_cast<int>(cnt++);

  if (current_vertex->right_child != nullptr &&
      current_vertex->right_child->used == false) {
    dfs_inner(current_height + 1, current_vertex->right_child, cnt);
  }
}

int BinaryTree::findAncestor(int value1, int value2) {
  const unsigned int left = std::min(indexes[value1], indexes[value2]);
  const unsigned int right = std::max(indexes[value1], indexes[value2]);
  return values[rmq.findMin(left, right).index];
}

void BinaryTree::dfs() {
  int cnt = 0;
  dfs_inner(0, root, cnt);
}

void BinaryTree::makeRmq() {
  if (root == nullptr) throw std::runtime_error("Tree is empty");
  dfs();
  rmq = RMQ(static_cast<std::vector<int>>(heights));
}