#include <gtest/gtest.h>
#include <vector>
#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph g(4, {{0, {3}}, {1, {}}, {2, {1}}, {3, {1, 2}}});
  std::vector<int> answer = g.Sort();
  std::vector<int> correct_ans{0, 3, 2, 1};
  ASSERT_EQ(answer, correct_ans);
}

TEST(TopologySort, Normal) {
  Graph g(6, {{0, {1, 2}}, {1, {}}, {2, {3}}, {3, {4}}, {4, {5}}, {5, {}}});
  std::vector<int> answer = g.Sort();
  std::vector<int> correct_ans{0, 2, 3, 4, 5, 1};
  ASSERT_EQ(answer, correct_ans);
}