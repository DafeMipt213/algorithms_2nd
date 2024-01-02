#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include "deikstra.hpp"

TEST(TopologySort, wiki_test) {
  Graph g;

  std::vector<std::vector<int>> weight_matrix {
    {INF, 7, 9, INF, INF, 14},
    {7, INF, 10, 15, INF, INF},
    {9, 10, INF, 11, INF, 2},
    {INF, 15, 11, INF, 6, INF},
    {INF, INF, INF, 6, INF, 9},
    {14, INF, 2, INF, 9, INF}
  };

  g.ReadGraph(weight_matrix);
  
  vector_t correct_path = {0, 2, 5, 4};
  int correct_weight = 20;
  std::pair correct_ans {correct_path, correct_weight};
  std::pair ans = g.FindPath(0, 4);

  ASSERT_EQ(correct_ans, ans);
} // Graph from wiki
