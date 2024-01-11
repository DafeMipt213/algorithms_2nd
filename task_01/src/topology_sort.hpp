#pragma once
#include <algorithm>
#include <stack>
#include <vector>

struct Graph {
  std::vector<std::vector<int>> graph_list;
  std::vector<int> tin;
  std::vector<int> tout;
  std::vector<int> colors;
  std::stack<int> topology_stack;
  int timer;
  Graph(std::vector<std::vector<int>> new_graph);
  void fillStack(int vertex);
  std::vector<int> topologySort(int vertex);
  void dfs(int vertex);
};