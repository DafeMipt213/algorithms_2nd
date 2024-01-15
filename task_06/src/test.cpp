
#include <gtest/gtest.h>

#include "LCA.hpp"

TEST(LCA, Simple1) {
  Tree tree{{1, 2}, {}, {}};
  LcaSolver solver(tree, 0);
  ASSERT_EQ(solver.GetLca(1, 2), 0);
  ASSERT_EQ(solver.GetLca(0, 2), 0);
}

TEST(LCA, Simple2) {
  Tree tree{{}};
  LcaSolver solver(tree, 0);
  ASSERT_EQ(solver.GetLca(0, 0), 0);
}

TEST(LCA, Middle1) {
  Tree tree{{1, 2}, {3, 4}, {5}, {}, {6}, {}, {}};
  LcaSolver solver(tree, 0);
  ASSERT_EQ(solver.GetLca(6, 5), 0);
  ASSERT_EQ(solver.GetLca(6, 3), 1);
  ASSERT_EQ(solver.GetLca(1, 3), 1);
}

TEST(LCA, Middle2) {
  Tree tree{{},     {0}, {1},      {2}, {5, 3}, {8, 6},
            {7, 9}, {},  {10, 11}, {},  {},     {}};
  LcaSolver solver(tree, 4);
  ASSERT_EQ(solver.GetLca(7, 0), 4);
  ASSERT_EQ(solver.GetLca(9, 8), 5);
  ASSERT_EQ(solver.GetLca(11, 3), 4);
}

TEST(LCA, Middle3) {
  Tree tree{{10, 11}, {0}, {1}, {2}, {5, 3, 12}, {8, 6}, {7, 9},
            {},       {},  {},  {},  {},         {}};
  LcaSolver solver(tree, 4);
  ASSERT_EQ(solver.GetLca(7, 7), 7);
  ASSERT_EQ(solver.GetLca(9, 8), 5);
  ASSERT_EQ(solver.GetLca(12, 5), 4);
}