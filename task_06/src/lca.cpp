#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> dp;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

int lca(int v, int u) {
  if (depth[v] > depth[u])
    swap(v, u);

  for (int i = log(n); i >= 0; --i) {
    if (depth[dp[u][i]] - depth[v] >= 0) {
      u = dp[u][i];
    }
  }
  if (v == u)
    return v;
  for (int i = log(n); i >= 0; --i) {
    if (dp[v][i] != dp[u][i]) {
      v = dp[v][i];
      u = dp[u][i];
    }
  }
  return parent[v];
}