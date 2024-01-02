#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include "deikstra.hpp"

TEST(dijkstra, wiki_test) {
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

TEST(dijkstra, second_test)
{
  Graph g;

  std::vector<std::vector<int>> weight_matrix {
    {INF, 10, INF, 30, 100},
    {10, INF, 50, INF, INF},
    {INF, 50, INF, 20, 10},
    {30, INF, 20, INF, 60},
    {100, INF, 10, 60, INF}
  };

  g.ReadGraph(weight_matrix);

  vector_t correct_path = {0, 3, 2, 4};
  int correct_weight = 60;
  std::pair correct_ans {correct_path, correct_weight};
  std::pair ans = g.FindPath(0, 4);

  ASSERT_EQ(correct_ans, ans);
} // Graph from internet