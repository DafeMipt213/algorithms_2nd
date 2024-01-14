#pragma once
#include <utility>
#include <vector>
using namespace std;

enum Color { White, Gray, Black };

class Graph {
private:
  vector<vector<int>> g;
  vector<size_t> tin, tout;
  int timer = 0;
  vector<pair<size_t, size_t>> vec_bridges;
  vector<size_t> vec_articulation_points;
  vector<bool> used;
  vector<size_t> ret;
  vector<Color> color;
  vector<int> parent;
  void util_articulation_points_and_bridge_finder(size_t v, int p);

public:
  explicit Graph(const vector<vector<int>> &adjacency_list);
  void dfs(int v, int p = -1);
  vector<size_t> articulation_points_finder(size_t v, int p = -1);
  vector<pair<size_t, size_t>> bridge_finder(size_t v, int p = -1);
  vector<size_t> topologicalSort();
};
