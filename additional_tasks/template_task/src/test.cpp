
#include <gtest/gtest.h>
#include <vector>
#include "utils.hpp"

TEST(Template, Deikstra_wiki_graph) 
{ 
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
  
  std::vector<int> ans = g.FindPaths(0);
  std::vector<int> correct_ans = {0, 7, 9, 20, 20, 11};
  ASSERT_EQ(ans, correct_ans);
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
  
  std::vector<int> ans = g.FindPaths(0);
  std::vector<int> correct_ans = {0, 6, 9, 5, 4, 7};
  ASSERT_EQ(ans, correct_ans);
}

TEST(Template, Graph_with_negative_cycle) 
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
  
  std::vector<int> ans = g.FindPaths(0);
  std::vector<int> correct_ans = {0}; // ans = {0} if there is negative cycle
  ASSERT_EQ(ans, correct_ans);
}