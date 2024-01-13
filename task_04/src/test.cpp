#include <gtest/gtest.h>
#include "Deijkstra.hpp"

TEST(Deijkstra, Test_default_graph_1) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 1}, {8, 1}},
                                            {{2, 1}},
                                            {{4, 1}},
                                            {{2, 1}, {4, 1}},
                                            {},
                                            {{7, 1}},
                                            {{5, 1}, {7, 1}},
                                            {{2, 1}, {4, 1}},
                                            {{6, 1}, {9, 1}},
                                            {{6, 1}}};
  ASSERT_EQ(Deijkstra(0, 4, graph), 3);
}

TEST(Deijkstra, Test_default_graph_2) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 10}, {2, 7}},
                                            {{4, 3}, {3, 9}},
                                            {{3, 11}, {5, 2}},
                                            {{6, 8}, {7, 12}, {8, 1}},
                                            {{6, 4}},
                                            {{8, 5}},
                                            {{9, 6}},
                                            {{9, 13}},
                                            {{9, 8}},
                                            {}};
  ASSERT_EQ(Deijkstra(0, 9, graph), 22);
}

TEST(Deijkstra, Test_default_graph_3) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 2}, {2, 2}, {5, 3}},
                                            {{2, 1}, {3, 2}, {6, 8}},
                                            {{3, 1}, {5, 4}},
                                            {{6, 3}, {4, 2}},
                                            {{5, 4}, {7, 6}},
                                            {{7, 7}},
                                            {{7, 8}},
                                            {}};
  ASSERT_EQ(Deijkstra(0, 7, graph), 10);
}

TEST(Deijkstra, Test_default_graph_4) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 10}, {3, 8}, {4, 31}},
                                            {{2, 7}},
                                            {{3, 9}, {7, 27}},
                                            {{5, 11}},
                                            {{6, 32}},
                                            {{6, 17}, {8, 15}},
                                            {{8, 21}},
                                            {{8, 15}},
                                            {}};
  ASSERT_EQ(Deijkstra(0, 3, graph), 8);
}

TEST(Deijkstra, Test_check_for_bad_input_1) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 10}, {2, 7}},
                                            {{4, 3}, {3, 9}},
                                            {{3, 11}, {5, 2}},
                                            {{6, 8}, {7, 12}, {8, 1}},
                                            {{6, 4}},
                                            {{8, 5}},
                                            {{9, 6}},
                                            {{9, 13}},
                                            {{9, 8}},
                                            {}};
  ASSERT_ANY_THROW(Deijkstra(0, 10, graph));
}

TEST(Deijkstra, Test_check_for_bad_input_2) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 10}, {2, 7}},
                                            {{4, 3}, {3, 9}},
                                            {{3, 11}, {5, 2}},
                                            {{6, 8}, {7, 12}, {8, 1}},
                                            {{6, 4}},
                                            {{8, 5}},
                                            {{9, 6}},
                                            {{9, 13}},
                                            {{9, 8}},
                                            {}};
  ASSERT_ANY_THROW(Deijkstra(-6, 9, graph));
}

TEST(Deijkstra, Test_empty_graph) {
  std::vector< std::vector< std::pair<int, int> > > graph = {};
  ASSERT_ANY_THROW(Deijkstra(0, 9, graph));
}

TEST(Deijkstra, Test_default_graph_with_negative_weights) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 1}, {8, 1}},
                                            {{2, 1}},
                                            {{4, 1}},
                                            {{2, 1}, {4, -1}},
                                            {},
                                            {{7, 1}},
                                            {{5, -1}, {7, 1}},
                                            {{2, 1}, {4, 1}},
                                            {{6, 1}, {9, -1}},
                                            {{6, -1}}};
  ASSERT_ANY_THROW(Deijkstra(0, 9, graph));
}

TEST(Deijkstra, Test_for_isolated_verticle) {
  std::vector< std::vector< std::pair<int, int> > > graph = {{{1, 1}, {8, 1}},
                                            {{2, 1}},
                                            {{4, 1}},
                                            {{2, 1}, {4, -1}},
                                            {},
                                            {{7, 1}},
                                            {{5, -1}, {7, 1}},
                                            {{2, 1}, {4, 1}},
                                            {{6, 1}, {9, -1}},
                                            {{6, -1}},
                                            {},
                                            {}};
  ASSERT_ANY_THROW(Deijkstra(0, 10, graph));
}