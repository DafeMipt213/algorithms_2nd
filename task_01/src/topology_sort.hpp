#pragma once

#include <iostream>
#include <stack>
#include <vector>

enum class Color { White, Gray, Black };

class Graph {
 public:
  Graph(std::vector<std::vector<int>> graph);
  Graph(int vertices);

  void AddEdge(int u, int v);
  std::vector<int> TopologicalSort();

 private:
  bool Dfs(int current_vertex, std::vector<Color>& vertices_color,
           std::stack<int>& result);

  std::vector<std::vector<int>> adjacency_list_;
};