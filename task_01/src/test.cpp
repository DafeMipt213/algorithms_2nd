#include <gtest/gtest.h>

#include "graph.hpp"

TEST(topologicalSort, Simple) {
  ASSERT_EQ(1, 1); // Stack []
  Graph test({{}, {}, {3}, {1}, {0, 1}, {2, 0}});
  ASSERT_EQ((test.topologicalSort()), (std::vector<size_t>{5, 4, 2, 3, 1, 0}));
  Graph test1({{6}, {6, 2, 4}, {}, {0, 4}, {}, {1}, {}, {0, 1}});
  ASSERT_EQ((test1.topologicalSort()),
            (std::vector<size_t>{7, 5, 3, 1, 4, 2, 0, 6}));
  Graph test3({{3, 4, 2}, {3, 4}, {1}, {4, 2, 0}, {3}});
  ASSERT_EQ((test3.topologicalSort()), (std::vector<size_t>{0, 3, 2, 1, 4}));
}
TEST(topologicalSort, Middle) {
  Graph test2({{2, 5, 4}, {3, 6, 5}, {}, {2}, {}, {2, 3, 4}, {3}, {5}});
  ASSERT_EQ((test2.topologicalSort()),
            (std::vector<size_t>{7, 1, 6, 0, 5, 4, 3, 2}));
}