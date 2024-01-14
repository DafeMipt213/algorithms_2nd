#include "LCA.hpp"

std::vector<int> lca_h, lca_dfs_list, lca_first, lca_tree;
std::vector<bool> lca_dfs_used;

bool Empty = false;
bool OnlyRoot = false;

void lca_dfs(const graph &graph, int v, int h) {
  lca_dfs_used[v] = 1;
  lca_h[v] = h;
  lca_dfs_list.push_back(v);
  for (const_graph_iter i = graph[v].begin(); i != graph[v].end(); ++i) {
    if (!lca_dfs_used[*i]) {
      lca_dfs(graph, *i, h + 1);
      lca_dfs_list.push_back(v);
    }
  }
}

void lca_build_tree(int i, int l, int r) {
  if (l == r)
    lca_tree[i] = lca_dfs_list[l];
  else {
    int m = (l + r) >> 1;
    lca_build_tree(i + i, l, m);
    lca_build_tree(i + i + 1, m + 1, r);
    if (lca_h[lca_tree[i + i]] < lca_h[lca_tree[i + i + 1]])
      lca_tree[i] = lca_tree[i + i];
    else
      lca_tree[i] = lca_tree[i + i + 1];
  }
}

void lca_prepare(const graph &graph, int root) {
  if (graph.empty()) {
    Empty = true;
  } else {
    if (graph.size() == 1) {
      OnlyRoot = true;
    } else {
      int n = (int)graph.size();
      lca_h.resize(n);
      lca_dfs_list.reserve(n * 2);
      lca_dfs_used.assign(n, 0);

      lca_dfs(graph, root);

      int m = (int)lca_dfs_list.size();
      lca_tree.assign(lca_dfs_list.size() * 4 + 1, -1);
      lca_build_tree(1, 0, m - 1);

      lca_first.assign(n, -1);
      for (int i = 0; i <= m; ++i) {
        int v = lca_dfs_list[i];
        if (lca_first[v] == -1) lca_first[v] = i;
      }
    }
  }
}

int lca_tree_min(int i, int sl, int sr, int l, int r) {
  if (sl == l && sr == r) return lca_tree[i];
  int sm = (sl + sr) >> 1;
  if (r <= sm) return lca_tree_min(i + i, sl, sm, l, r);
  if (l > sm) return lca_tree_min(i + i + 1, sm + 1, sr, l, r);
  int ans1 = lca_tree_min(i + i, sl, sm, l, sm);
  int ans2 = lca_tree_min(i + i + 1, sm + 1, sr, sm + 1, r);
  return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
}

int lca(int a, int b) {
  if (Empty or OnlyRoot) throw "Error";
  int left = lca_first[a], right = lca_first[b];
  if (left > right) std::swap(left, right);
  return lca_tree_min(1, 0, (int)lca_dfs_list.size() - 1, left, right);
}