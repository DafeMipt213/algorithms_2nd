
#include <gtest/gtest.h>

#include <graph.hpp>
#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{1, 2}, {3, 4}, {}, {2, 4}, {}});
  ASSERT_EQ((TopologySort(graph, 0)), (std::vector<size_t>{0, 1, 3, 4, 2}));
  ASSERT_EQ((TopologySort(graph, 1)), (std::vector<size_t>{1, 3, 4, 2}));
}

TEST(TopologySort, Empty) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({});
  ASSERT_EQ(TopologySort(graph, 0), (std::vector<size_t>{}));
}

TEST(TopologySort, OneVertex) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{}});
  ASSERT_EQ(TopologySort(graph, 0), (std::vector<size_t>{0}));
}

TEST(TopologySort, TwoVertexes) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{1}, {0}});
  ASSERT_EQ(TopologySort(graph, 0), (std::vector<size_t>{0, 1}));
  ASSERT_EQ(TopologySort(graph, 1), (std::vector<size_t>{1, 0}));
}

TEST(TopologySort, Middle) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{3, 4, 2}, {3, 4}, {1}, {4, 2, 0}, {3}});
  ASSERT_EQ((TopologySort(graph, 0)), (std::vector<size_t>{0, 3, 2, 1, 4}));
  ASSERT_EQ((TopologySort(graph, 1)), (std::vector<size_t>{1, 3, 0, 2, 4}));
  ASSERT_EQ((TopologySort(graph, 2)), (std::vector<size_t>{2, 1, 3, 0, 4}));
  ASSERT_EQ((TopologySort(graph, 3)), (std::vector<size_t>{3, 0, 2, 1, 4}));
}

TEST(TopologySort, Middle2) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {5, 2, 0, 1, 4},
      {4, 1, 3, 0},
      {0, 2},
      {3, 2, 5, 1, 0},
      {2, 0, 1, 3},
      {},
  });
  ASSERT_EQ((TopologySort(graph, 0)), (std::vector<size_t>{0, 1, 4, 3, 2, 5}));
  ASSERT_EQ((TopologySort(graph, 1)), (std::vector<size_t>{1, 4, 3, 2, 0, 5}));
  ASSERT_EQ((TopologySort(graph, 2)), (std::vector<size_t>{2, 0, 1, 4, 3, 5}));
  ASSERT_EQ((TopologySort(graph, 3)), (std::vector<size_t>{3, 2, 0, 1, 4, 5}));
};

TEST(TopologySort, Hard) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {0, 6, 3, 5, 4, 2},
      {0},
      {4, 6, 0, 2, 1, 3},
      {6, 3, 0, 1, 5, 2},
      {5, 0, 3, 1, 2},
      {5, 4, 2, 6, 3, 7, 0},
      {2, 4, 0, 6, 5, 1},
      {9, 7, 8, 5, 1, 6, 4, 0, 2},
      {2, 5, 0, 4, 7, 6, 1},
      {3, 4, 0, 2},
  });

  ASSERT_EQ((TopologySort(graph, 0)),
            (std::vector<size_t>{0, 6, 2, 4, 5, 7, 8, 9, 3, 1}));
  ASSERT_EQ((TopologySort(graph, 6)),
            (std::vector<size_t>{6, 2, 4, 5, 7, 8, 9, 3, 1, 0}));
  ASSERT_EQ((TopologySort(graph, 9)),
            (std::vector<size_t>{9, 3, 6, 2, 4, 5, 7, 8, 1, 0}));
  ASSERT_EQ((TopologySort(graph, 3)),
            (std::vector<size_t>{3, 6, 2, 4, 5, 7, 8, 1, 9, 0}));
}

TEST(TopologySort, AnyThrow) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {5, 2, 0, 1, 4},
      {4, 1, 3, 0},
      {0, 2},
      {3, 2, 5, 1, 0},
      {2, 0, 1, 3},
      {},
  });
  ASSERT_ANY_THROW((TopologySort(graph, -1)));
  ASSERT_ANY_THROW((TopologySort(graph, 8)));
}
