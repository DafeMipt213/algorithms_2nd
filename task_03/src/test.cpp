#include <gtest/gtest.h>
#include <vector>
#include "jonson.hpp"

TEST(Jonson, Graph_with_negative_cycle) 
{ 
  Graph g;

  std::vector<std::vector<int>> weight_matrix {
    {INF, -2, 1, INF, 5, INF},
    {-1, INF, 3, -1, INF, INF},
    {INF, INF, INF, 3, INF, INF},
    {INF, INF, INF, INF, INF, 3},
    {INF, INF, INF, 1, INF, 7},
    {INF, INF, INF, INF, INF, INF}
  };

  g.ReadGraph(weight_matrix);
  
  std::vector<std::vector<int>> ans = g.jonson();
  std::vector<std::vector<int>> correct_ans = {{0}}; // ans = {0} if there is negative cycle
  ASSERT_EQ(ans, correct_ans);
}

TEST(Jonson, wiki_test) {
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

  std::vector<std::vector<int>> correct_ans = {
    {0, 7, 9, 20, 20, 11},
    {7, 0, 10, 15, 21, 12},
    {9, 10, 0, 11, 11, 2},
    {20, 15, 11, 0, 6, 13},
    {20, 21, 11, 6, 0, 9},
    {11, 12, 2, 13, 9, 0}
    };
  std::vector<std::vector<int>> ans = g.jonson();

  ASSERT_EQ(correct_ans, ans);
}

TEST(Template, Graph_with_negative_weights) 
{ 
  Graph g;

  std::vector<std::vector<int>> weight_matrix {
    {INF, 7, 9, INF, INF, INF},
    {INF, INF, INF, -1, -2, INF},
    {INF, -3, INF, INF, 2, INF},
    {INF, INF, INF, INF, 1, 3},
    {INF, INF, INF, INF, INF, 3},
    {INF, INF, INF, INF, INF, INF}
  };

  g.ReadGraph(weight_matrix);
  
  std::vector<std::vector<int>> ans = g.jonson();
  std::vector<std::vector<int>> correct_ans = {
    {0, 6, 9, 5, 4, 7},
    {INF, 0, INF, -1, -2, 1},
    {INF, -3, 0, -4, -5, -2},
    {INF, INF, INF, 0, 1, 3},
    {INF, INF, INF, INF, 0, 3},
    {INF, INF, INF, INF, INF, 0}
  };
  ASSERT_EQ(ans, correct_ans);
}