#include <gtest/gtest.h>

#include "LCA.hpp"

TEST(LCA, Simple) {
  Tree tree = {{1, 2}, {3, 4}, {}, {}, {}};
  LCA solver(tree, 0);
  ASSERT_EQ(solver.Run(1, 3), 1);
  ASSERT_EQ(solver.Run(3, 4), 1);
  ASSERT_EQ(solver.Run(2, 3), 0);
}

TEST(LCA, Middle) {
  Tree tree = {{1, 2}, {3, 4, 5}, {8}, {}, {6, 7}, {}, {}, {}, {}};
  LCA solver(tree, 0);
  ASSERT_EQ(solver.Run(0, 7), 0);
  ASSERT_EQ(solver.Run(5, 7), 1);
  ASSERT_EQ(solver.Run(5, 8), 0);
  ASSERT_EQ(solver.Run(6, 7), 4);
  ASSERT_EQ(solver.Run(4, 6), 4);
  ASSERT_EQ(solver.Run(3, 5), 1);
}