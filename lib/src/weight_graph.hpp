#pragma once
#include <utility>
#include <vector>
using namespace std;

class Weight_Graph {
  vector<vector<pair<int, int>>> g;

public:
  explicit Weight_Graph(const vector<vector<pair<int, int>>> &adjacency_list);
  vector<int> dijkstra(int src);
};