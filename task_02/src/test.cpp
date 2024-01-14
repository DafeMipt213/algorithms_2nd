
#include <gtest/gtest.h>

#include "net.hpp"

TEST(Nets, Simple) {
  std::vector<Node*> nodes;
  for (int i = 0; i <= 8; ++i) nodes.push_back(new Node(i));
  nodes[0]->setNodes({nodes[1], nodes[2]});
  nodes[1]->setNodes({nodes[0], nodes[2]});
  nodes[2]->setNodes({nodes[1], nodes[0], nodes[3]});
  nodes[3]->setNodes({nodes[2], nodes[4], nodes[5]});
  nodes[4]->setNodes({nodes[3], nodes[5]});
  nodes[5]->setNodes({nodes[3], nodes[4], nodes[6]});
  nodes[6]->setNodes({nodes[5], nodes[7], nodes[8]});
  nodes[7]->setNodes({nodes[6], nodes[8]});
  nodes[8]->setNodes({nodes[7], nodes[6]});
  Net TestNet = Net(nodes);
  std::set<size_t> routers = {6, 5, 3, 2};
  std::vector<std::pair<size_t, size_t>> nets = {{5, 6}, {2, 3}};
  ASSERT_EQ(TestNet.weak_nets, nets);
  ASSERT_EQ(TestNet.weak_routers, routers);
}

TEST(Nets, Simple2) {
  std::vector<Node*> nodes;
  for (int i = 0; i <= 9; ++i) nodes.push_back(new Node(i));
  nodes[0]->setNodes({nodes[1], nodes[2]});
  nodes[1]->setNodes({nodes[2]});
  nodes[2]->setNodes({nodes[0], nodes[3]});
  nodes[3]->setNodes({nodes[6], nodes[7], nodes[4], nodes[5]});
  nodes[4]->setNodes({nodes[5]});
  nodes[5]->setNodes({nodes[3], nodes[9]});
  nodes[6]->setNodes({nodes[7]});
  nodes[7]->setNodes({nodes[3], nodes[8]});
  Net TestNet = Net(nodes);
  std::set<size_t> routers = {2, 3, 5, 7};
  std::vector<std::pair<size_t, size_t>> nets = {{7, 8}, {5, 9}, {2, 3}};
  ASSERT_EQ(TestNet.weak_nets, nets);
  ASSERT_EQ(TestNet.weak_routers, routers);
}
