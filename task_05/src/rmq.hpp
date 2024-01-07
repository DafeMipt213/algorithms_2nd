#pragma once

#include <stack>
#include <vector>

struct AllData {
  int n, block_size, block_cnt;
  std::vector<std::vector<int>> graph, st;
  std::vector<int> visited, euler_bypass, height, log2, block_mask;
  std::vector<std::vector<std::vector<int>>> blocks;
  AllData(){};
};

void DFS(int v, int p, int h, AllData &data);
int MinimumHeights(int i, int j, AllData &data);
void Precompute(int root, AllData &data);
int LCABlock(int b, int l, int r, AllData &data);
int LCA(int v, int u, AllData &data);
int RMQ(int left, int right, std::vector<int> &graph);