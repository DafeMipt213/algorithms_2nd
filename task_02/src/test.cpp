
#include <gtest/gtest.h>

#include "search.hpp"

TEST(BridgeSearch, Simple) {
  Graph graph{{1}, {0}};
  ASSERT_EQ(BridgeSearch(graph), std::vector<edge>{edge(0, 1)});
}

TEST(BridgeSearch, WithoutBridges) {
  Graph graph{{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  ASSERT_EQ(BridgeSearch(graph), std::vector<edge>{});
}

TEST(BridgeSearch, ThreeBridges) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<edge> result{edge(4, 5), edge(5, 8), edge(0, 8)};
  ASSERT_EQ(BridgeSearch(graph), result);
}

TEST(BridgeSearch, TwoBridges) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {8}, {}};
  std::vector<edge> result{edge(4, 5), edge(0, 8)};
  ASSERT_EQ(BridgeSearch(graph), result);
}

TEST(BridgeSearch, AllBridges) {
  Graph graph{{1}, {2}, {3}, {}};
  std::vector<edge> result{edge(2, 3), edge(1, 2), edge(0, 1)};
  ASSERT_EQ(BridgeSearch(graph), result);
}

TEST(DotSearch, Simple) {
  Graph graph{{1}, {}, {1}};
  ASSERT_EQ(DotSearch(graph), std::vector<int>{1});
}

TEST(DotSearch, WithoutDots) {
  Graph graph{{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  ASSERT_EQ(DotSearch(graph), std::vector<int>{});
}

TEST(DotSearch, ThreeDots) {
  Graph graph{{8}, {2, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<int> result{4, 5, 8};
  ASSERT_EQ(DotSearch(graph), result);
}

TEST(DotSearch, TwoDots) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<int> result{4, 5, 8};
  ASSERT_EQ(DotSearch(graph), result);
}

TEST(DotSearch, AllDots) {
  Graph graph{{1}, {2}, {3}, {}};
  std::vector<int> result{1, 2};
  ASSERT_EQ(DotSearch(graph), result);
}