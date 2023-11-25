
#include <gtest/gtest.h>

#include "search.hpp"

TEST(BridgeSearch, Simple) {
  Graph graph{{1}, {0}};
  ASSERT_EQ(bridge_search(graph), std::vector<edge>{edge(0, 1)});
}
