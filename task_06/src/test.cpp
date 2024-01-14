
#include <gtest/gtest.h>
#include "lca.hpp"
TEST(LCA, Simple1) {
  Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	std::vector<Node*> to_do = {node2, node3, node4 };
	node1->setNodes(to_do);
	std::vector<int> ans;
	node3->setNodes({ node5 });
	LCA test({ node1, node2, node3, node4, node5 });
	ASSERT_EQ(test.findLCA(1, 5), 1);
}

TEST(LCA, Simple2){
  Node* node1 = new Node(0);
  Node* node2 = new Node(17);
  Node* node3 = new Node(15);
  Node* node4 = new Node(16);
  Node* node5 = new Node(18);
  Node* node6 = new Node(36);
  Node* node7 = new Node(23);
  Node* node8 = new Node(42);
  Node* node9 = new Node(20);
  node1->setNodes({node2, node3});
  node3->setNodes({node4, node5});
  node4->setNodes({node6, node7});
  node5->setNodes({node8, node9});
  LCA test({ node1, node2, node3, node4, node5, node6, node7, node8, node9 });
  ASSERT_EQ(test.findLCA(16, 18), 15);
  ASSERT_EQ(test.findLCA(36, 42), 15);
  ASSERT_EQ(test.findLCA(17, 0), 0);
  ASSERT_EQ(test.findLCA(0, 17), 0);
  ASSERT_EQ(test.findLCA(0, 20), 0);
  ASSERT_EQ(test.findLCA(0, 18), 0);
}
TEST(LCA, Simple3){
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5); 
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);
  node1->setNodes({node2, node3});
  node2->setNodes({node4, node5});
  node5->setNodes({node6, node7});
  LCA test({node1, node2, node3, node4, node5, node6, node7});
  ASSERT_EQ(test.findLCA(2, 3), 1);
  ASSERT_EQ(test.findLCA(6, 4), 2);
  ASSERT_EQ(test.findLCA(3, 2), 1);
  ASSERT_EQ(test.findLCA(5, 3),1);
  ASSERT_EQ(test.findLCA(2, 1),1);
    for (int i = 1; i <= 7; ++i)
    ASSERT_EQ(test.findLCA(i, i), i);
}

TEST(LCA, Simple4){
  std::vector<Node*> nodes;
  for (int i = 1; i <= 9; ++i)
    nodes.push_back(new Node(i));
  nodes[5]->setNodes({nodes[7], nodes[8], nodes[2]});
  nodes[2]->setNodes({nodes[0], nodes[6]});
  nodes[0]->setNodes({nodes[1]});
  nodes[1]->setNodes({nodes[3], nodes[4]});
  LCA test(nodes);
  ASSERT_EQ(test.findLCA(6, 9), 6);
  ASSERT_EQ(test.findLCA(1, 6), 6);
  ASSERT_EQ(test.findLCA(4, 4), 4);
  for (int i = 1; i <= 9; ++i){
    ASSERT_EQ(test.findLCA(6, i), 6);
    if (i != 8)
    ASSERT_EQ(test.findLCA(8, i), 6);
    if (i != 9)
    ASSERT_EQ(test.findLCA(9, i), 6);
  }
  ASSERT_EQ(test.findLCA(7, 1), 3);
  ASSERT_EQ(test.findLCA(7, 2), 3);
  ASSERT_EQ(test.findLCA(7, 4), 3);
  ASSERT_EQ(test.findLCA(7, 5), 3);
}
