
#include <gtest/gtest.h>

#include <graph.hpp>
#include <vector>

#include "bridge_finder.hpp"
#include "cut_vertex_finder.hpp"

TEST(BridgeFinder, Simple) {
  Graph<size_t> graph;
  graph.SetAdjacencyList(
      {{1, 2}, {0, 2}, {0, 1, 3}, {2, 5, 4}, {3, 5}, {3, 4}});
  ASSERT_EQ(FindBrindges(graph),
            (std::vector<std::pair<size_t, size_t>>{{2, 3}}));
}

TEST(BridgeFinder, Simple2) {
  Graph<size_t> graph;
  graph.SetAdjacencyList(
      {{1, 2}, {3, 5}, {0, 4, 5}, {1}, {2, 5}, {1, 2, 4, 6}, {5, 7}, {6}});
  ASSERT_EQ(FindBrindges(graph),
            (std::vector<std::pair<size_t, size_t>>{{1, 3}, {6, 7}, {5, 6}}));
}

TEST(BridgeFinder, Middle) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{{1, 2, 0},
                           {3, 5, 1},
                           {0, 4, 5, 2},
                           {1},
                           {2, 5},
                           {1, 2, 4, 6},
                           {5, 7},
                           {6}}});
  std::vector<std::pair<size_t, size_t>> res = FindBrindges(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res,
            (std::vector<std::pair<size_t, size_t>>{{1, 3}, {5, 6}, {6, 7}}));
}

TEST(BridgeFinder, Hard) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{{1, 2},
                           {0, 2},
                           {1, 0, 3},
                           {2, 4, 5},
                           {3, 5},
                           {3, 4, 6},
                           {5, 7, 8},
                           {6, 8},
                           {7, 6}}});
  std::vector<std::pair<size_t, size_t>> res = FindBrindges(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res, (std::vector<std::pair<size_t, size_t>>{{2, 3}, {5, 6}}));
}

TEST(BridgeFinder, NoBridges) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{{1, 3}, {0, 2}, {1, 3}, {2, 0}}});
  ASSERT_EQ(FindBrindges(graph), (std::vector<std::pair<size_t, size_t>>{}));
}

TEST(BridgeFinder, BigGraph) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {6, 2, 3, 1, 5, 4, 8, 0, 7},
      {0, 5, 9, 4, 3, 1, 7, 2, 6},
      {4, 0, 3, 1},
      {0, 3, 1},
      {3, 2, 0},
      {2, 7, 4, 3, 5, 6, 0},
      {6, 5, 2, 3, 0, 4, 7},
      {0, 1, 5, 2, 4, 6},
      {0, 3, 2},
      {2, 1},
      {5, 10, 7, 4, 11, 3, 8, 9, 1, 0, 2},
      {0, 3, 7, 5, 6, 1, 4},
  });
  ASSERT_EQ(FindBrindges(graph),
            (std::vector<std::pair<size_t, size_t>>{{0, 8}}));
}

TEST(CutVertexesFinder, ZeroCuts) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{1}, {2}, {0}});
  std::vector<size_t> res = FindCutVertexes(graph);
  ASSERT_EQ(res, (std::vector<size_t>{}));
}

TEST(CutVertexesFinder, OneCut) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({{1, 2, 3, 4}, {0, 2}, {1, 0}, {0, 4}, {0, 3}});
  std::vector<size_t> res = FindCutVertexes(graph);
  ASSERT_EQ(res, (std::vector<size_t>{0}));
}

TEST(CutVertexesFinder, TwoCuts) {
  Graph<size_t> graph;
  graph.SetAdjacencyList(
      {{1, 2, 3, 4}, {0, 2}, {1, 0, 5, 6}, {0, 4}, {0, 3}, {5, 6}, {5, 2}});
  std::vector<size_t> res = FindCutVertexes(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res, (std::vector<size_t>{0, 2}));
}

TEST(CutVertexesFinder, Medium) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {1, 2},
      {0, 2, 1},
      {4, 3, 2, 1},
      {1},
      {0, 2, 3, 1},
  });
  std::vector<size_t> res = FindCutVertexes(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res, (std::vector<size_t>{}));
}

TEST(CutVertexesFinder, Medium2) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {0, 1},
      {},
      {2, 3, 1},
      {2, 1},
      {0, 2, 3},
      {4, 1, 3, 5, 2},
  });
  std::vector<size_t> res = FindCutVertexes(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res, (std::vector<size_t>{}));
}

TEST(CutVertexesFinder, BigGraph) {
  Graph<size_t> graph;
  graph.SetAdjacencyList({
      {6, 2, 3, 1, 5, 4, 8, 0, 7},
      {0, 5, 9, 4, 3, 1, 7, 2, 6},
      {4, 0, 3, 1},
      {0, 3, 1},
      {3, 2, 0},
      {2, 7, 4, 3, 5, 6, 0},
      {6, 5, 2, 3, 0, 4, 7},
      {0, 1, 5, 2, 4, 6},
      {0, 3, 2},
      {2, 1},
      {5, 10, 7, 4, 11, 3, 8, 9, 1, 0, 2},
      {0, 3, 7, 5, 6, 1, 4},
  });
  std::vector<size_t> res = FindCutVertexes(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res, (std::vector<size_t>{0}));
}
