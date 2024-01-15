
#include <gtest/gtest.h>

#include <vector>

#include "busses_in_vasyuki.hpp"

TEST(Busses, Simple) {
  std::vector<std::vector<Edge>> graph{
      {Edge{0, 1, 5}, Edge{1, 1, 3}, Edge{1, 2, 10}}, {Edge{3, 2, 5}}, {}};
  ASSERT_EQ(BussesInVasyuki(graph, 0, 2), 5);
}

TEST(Busses, Imposible) {
  std::vector<std::vector<Edge>> graph{{}, {}, {}};
  ASSERT_EQ(BussesInVasyuki(graph, 0, 2), -1);
}
