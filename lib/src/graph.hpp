#pragma once
#include <vector>
using namespace std;

enum Color { White, Gray, Black };

class Graph {
private:
  vector<vector<size_t>> g;
  vector<size_t> tin, tout;
  int timer = 0;
  vector<Color> color;
  vector<int> parent;

public:
  Graph(const std::vector<std::vector<size_t>> &adjacency_list);
  void dfs(int v, int p = -1);
  vector<size_t> topologicalSort();
};

