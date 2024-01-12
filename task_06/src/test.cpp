#include <gtest/gtest.h>

#include "LCA.hpp"

TEST(LCA, Simple) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->right_child = new Node(2);
  tree.root->right_child = new Node(4);
  tree.root->right_child->right_child = new Node(5);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(2, 4), 0);
}

TEST(LCA, SimpleOtherOrderOfVertexes) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->right_child = new Node(2);
  tree.root->right_child = new Node(4);
  tree.root->right_child->right_child = new Node(5);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(4, 2), 0);
}

TEST(LCA, BiggerTree1) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->left_child = new Node(2);
  tree.root->left_child->left_child->left_child = new Node(3);
  tree.root->left_child->left_child->right_child = new Node(4);
  tree.root->left_child->left_child->right_child->left_child = new Node(5);
  tree.root->left_child->left_child->right_child->right_child = new Node(6);
  tree.root->left_child->right_child = new Node(10);
  tree.root->left_child->right_child->right_child = new Node(9);
  tree.root->right_child = new Node(12);
  tree.root->right_child->left_child = new Node(17);
  tree.root->right_child->left_child->left_child = new Node(11);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(2, 10), 1);
}

TEST(LCA, BiggerTree2) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->left_child = new Node(2);
  tree.root->left_child->left_child->left_child = new Node(3);
  tree.root->left_child->left_child->right_child = new Node(4);
  tree.root->left_child->left_child->right_child->left_child = new Node(5);
  tree.root->left_child->left_child->right_child->right_child = new Node(6);
  tree.root->left_child->right_child = new Node(10);
  tree.root->left_child->right_child->right_child = new Node(9);
  tree.root->right_child = new Node(12);
  tree.root->right_child->left_child = new Node(17);
  tree.root->right_child->left_child->left_child = new Node(11);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(6, 5), 4);
}

TEST(LCA, BiggerTree3) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->left_child = new Node(2);
  tree.root->left_child->left_child->left_child = new Node(3);
  tree.root->left_child->left_child->right_child = new Node(4);
  tree.root->left_child->left_child->right_child->left_child = new Node(5);
  tree.root->left_child->left_child->right_child->right_child = new Node(6);
  tree.root->left_child->right_child = new Node(10);
  tree.root->left_child->right_child->right_child = new Node(9);
  tree.root->right_child = new Node(12);
  tree.root->right_child->left_child = new Node(17);
  tree.root->right_child->left_child->left_child = new Node(11);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(17, 1), 0);
}

TEST(LCA, LineTreeLeft) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->left_child = new Node(2);
  tree.root->left_child->left_child->left_child = new Node(3);
  tree.root->left_child->left_child->left_child->left_child = new Node(4);
  tree.root->left_child->left_child->left_child->left_child->left_child =
      new Node(7);
  tree.root->left_child->left_child->left_child->left_child->left_child
      ->left_child = new Node(5);
  tree.root->left_child->left_child->left_child->left_child->left_child
      ->left_child->left_child = new Node(6);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(2, 4), 2);
}

TEST(LCA, TheSameVertex) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->right_child = new Node(2);
  tree.root->right_child = new Node(4);
  tree.root->right_child->right_child = new Node(5);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(2, 2), 2);
}

TEST(LCA, LineTreeRight) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->right_child = new Node(1);
  tree.root->right_child->right_child = new Node(2);
  tree.root->right_child->right_child->right_child = new Node(3);
  tree.root->right_child->right_child->right_child->right_child = new Node(4);
  tree.root->right_child->right_child->right_child->right_child->right_child =
      new Node(5);
  tree.root->right_child->right_child->right_child->right_child->right_child
      ->right_child = new Node(6);
  tree.root->right_child->right_child->right_child->right_child->right_child
      ->right_child->right_child = new Node(7);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(7, 1), 1);
}

TEST(LCA, OnlyRoot) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.makeRmq();
  ASSERT_EQ(tree.findAncestor(0, 0), 0);
}

TEST(LCA, EmptyTree) {
  BinaryTree tree = BinaryTree();
  ASSERT_ANY_THROW(tree.makeRmq());
}

TEST(LCA, NotUniqueValues) {
  BinaryTree tree = BinaryTree();
  tree.root = new Node(0);
  tree.root->left_child = new Node(1);
  tree.root->left_child->right_child = new Node(2);
  tree.root->right_child = new Node(0);
  tree.root->right_child->right_child = new Node(5);
  ASSERT_ANY_THROW(tree.makeRmq());
}