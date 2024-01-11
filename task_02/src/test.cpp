
#include <gtest/gtest.h>

#include "search.hpp"

TEST(BridgesSearch, Simple) {
  Graph graph{{1}, {0}};
  ASSERT_EQ(BridgesSearch(graph), std::vector<Edge>{Edge(0, 1)});
}

TEST(BridgesSearch, WithoutBridges) {
  Graph graph{{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  ASSERT_EQ(BridgesSearch(graph), std::vector<Edge>{});
}

TEST(BridgesSearch, ThreeBridges) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<Edge> result{Edge(4, 5), Edge(5, 8), Edge(0, 8)};
  ASSERT_EQ(BridgesSearch(graph), result);
}

TEST(BridgesSearch, TwoBridges) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {8}, {}};
  std::vector<Edge> result{Edge(4, 5), Edge(0, 8)};
  ASSERT_EQ(BridgesSearch(graph), result);
}

TEST(BridgesSearch, AllBridges) {
  Graph graph{{1}, {2}, {3}, {}};
  std::vector<Edge> result{Edge(2, 3), Edge(1, 2), Edge(0, 1)};
  ASSERT_EQ(BridgesSearch(graph), result);
}

TEST(DotsSearch, Simple) {
  Graph graph{{1}, {}, {1}};
  ASSERT_EQ(DotsSearch(graph), std::vector<int>{1});
}

TEST(DotsSearch, WithoutDots) {
  Graph graph{{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  ASSERT_EQ(DotsSearch(graph), std::vector<int>{});
}

TEST(DotsSearch, ThreeDots) {
  Graph graph{{8}, {2, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<int> result{4, 5, 8};
  ASSERT_EQ(DotsSearch(graph), result);
}

TEST(DotsSearch, TwoDots) {
  Graph graph{{8}, {2, 3, 4}, {4}, {4}, {5}, {6, 7, 8}, {7}, {}, {}};
  std::vector<int> result{4, 5, 8};
  ASSERT_EQ(DotsSearch(graph), result);
}

TEST(DotsSearch, AllDots) {
  Graph graph{{1}, {2}, {3}, {}};
  std::vector<int> result{1, 2};
  ASSERT_EQ(DotsSearch(graph), result);
}