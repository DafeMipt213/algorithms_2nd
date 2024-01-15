#include <gtest/gtest.h>

#include "rmq.hpp"

TEST(RMQ, Simple) {
  std::vector<int> vec = {2, 5, 1, 4, 9, 3, 7};
  SegmentTree seg_tree(vec);

  ASSERT_EQ(seg_tree.query(1, 4), 1);
  ASSERT_EQ(seg_tree.query(3, 5), 3);
  ASSERT_EQ(seg_tree.query(0, 1), 2);
  ASSERT_EQ(seg_tree.query(0, 6), 1);
}
