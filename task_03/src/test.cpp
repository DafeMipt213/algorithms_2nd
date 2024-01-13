
#include <gtest/gtest.h>

#include "johnson.hpp"
void testJohnson(std::vector<int> example, Graph& TestGraph, int ind1, int ind2,
                 int weight) {
  std::pair<std::vector<size_t>, int> ans = Johnson(TestGraph, ind1, ind2);
  for (int i = 0; i < ans.first.size(); ++i)
    for (int i = 0; i < ans.first.size(); ++i)
      ASSERT_EQ(example[i], ans.first[i]);
  ASSERT_EQ(ans.second, weight);
}

TEST(Johnson, Normal1) {
  std::vector<Node> nodes;
  for (int i = 1; i < 5; ++i) nodes.push_back(Node(i));
  Graph TestGraph = Graph(nodes);
  TestGraph.addEdge(1, 2, -2);
  TestGraph.addEdge(1, 3, 7);
  TestGraph.addEdge(1, 4, 5);
  TestGraph.addEdge(2, 3, 8);
  TestGraph.addEdge(2, 4, 6);
  TestGraph.addEdge(3, 2, 3);
  TestGraph.addEdge(3, 4, -4);
  TestGraph.addEdge(4, 1, -1);
  std::vector<int> ans = {1, 2, 3, 4};
  testJohnson(ans, TestGraph, 1, 4, 1);
}
