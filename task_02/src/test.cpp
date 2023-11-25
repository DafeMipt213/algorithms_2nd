
#include <gtest/gtest.h>

#include "search.hpp"

TEST(BridgeSearch, Simple) {
  Graph graph{{1}, {0}};
  ASSERT_EQ(bridge_search(graph), std::vector<edge>{edge(0, 1)});
}

TEST(BridgeSearch, WithoutBridges) {
  Graph graph{{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  ASSERT_EQ(bridge_search(graph), std::vector<edge>{});
}

TEST(BridgeSearch, ThreeBridges) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<edge> result{edge(4, 5), edge(5, 8), edge(0, 8)};
  ASSERT_EQ(bridge_search(graph), result);
}

TEST(BridgeSearch, TwoBridges) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {8}, {}};
  std::vector<edge> result{edge(4, 5), edge(0, 8)};
  ASSERT_EQ(bridge_search(graph), result);
}

TEST(BridgeSearch, AllBridges) {
  Graph graph{{1}, {2}, {3}, {}};
  std::vector<edge> result{edge(2, 3), edge(1, 2), edge(0, 1)};
  ASSERT_EQ(bridge_search(graph), result);
}