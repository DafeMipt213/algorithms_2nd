#pragma once

#include <vector>

using Edge = std::pair<int, int>;

class Graph {
 public:
  Graph(std::vector<std::vector<int>> graph);
  Graph(int vertices);

  void RemoveEdge(int u, int v);
  void AddEdge(int u, int v);
  void RemoveRouter(int u);
  std::vector<Edge> FindCriticalEdges();
  std::vector<int> FindCriticalRouters();

 private:
  void Dfs(int v, std::vector<bool>& visited);
  int CountConnectedComponents();

  std::vector<std::vector<int>> adjacency_list_;
};