#include <iostream>

#include "LCA.hpp"

int main() {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->right_child = new Node(2);
  tree.root->right_child = new Node(4);
  return 0;
}
