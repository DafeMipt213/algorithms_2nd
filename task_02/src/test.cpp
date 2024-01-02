
#include <gtest/gtest.h>

#include <graph.hpp>
#include <vector>

#include "bridge_finder.hpp"
#include "cut_vertex_finder.hpp"

TEST(BridgeFinder, Simple) {
  Graph graph({{1, 2}, {0, 2}, {0, 1, 3}, {2, 5, 4}, {3, 5}, {3, 4}});
  ASSERT_EQ(FindBrindges(graph),
            (std::vector<std::pair<size_t, size_t>>{{2, 3}}));
}

TEST(BridgeFinder, Simple2) {
  Graph graph(
      {{1, 2}, {3, 5}, {0, 4, 5}, {1}, {2, 5}, {1, 2, 4, 6}, {5, 7}, {6}});
  ASSERT_EQ(FindBrindges(graph),
            (std::vector<std::pair<size_t, size_t>>{{1, 3}, {6, 7}, {5, 6}}));
}

TEST(BridgeFinder, Middle) {
  Graph graph{{{1, 2, 0},
               {3, 5, 1},
               {0, 4, 5, 2},
               {1},
               {2, 5},
               {1, 2, 4, 6},
               {5, 7},
               {6}}};
  std::vector<std::pair<size_t, size_t>> res = FindBrindges(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res,
            (std::vector<std::pair<size_t, size_t>>{{1, 3}, {5, 6}, {6, 7}}));
}

TEST(BridgeFinder, Hard) {
  Graph graph{{{1, 2},
               {0, 2},
               {1, 0, 3},
               {2, 4, 5},
               {3, 5},
               {3, 4, 6},
               {5, 7, 8},
               {6, 8},
               {7, 6}}};
  std::vector<std::pair<size_t, size_t>> res = FindBrindges(graph);
  std::sort(res.begin(), res.end());
  ASSERT_EQ(res, (std::vector<std::pair<size_t, size_t>>{{2, 3}, {5, 6}}));
}

TEST(BridgeFinder, NoBridges) {
  Graph graph{{{1, 3}, {0, 2}, {1, 3}, {2, 0}}};
  ASSERT_EQ(FindBrindges(graph), (std::vector<std::pair<size_t, size_t>>{}));
}

// TEST(CutVertexesFinder, Simple) {
//   Graph graph({{1, 2, 3, 4}, {0, 2}, {0, 1}, {0, 4}, {0, 3}});
//   std::vector<size_t> res = FindCutVertexes(graph);
//   ASSERT_EQ(res, (std::vector<size_t>{}));
// }