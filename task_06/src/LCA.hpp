#pragma once

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> graph;
typedef std::vector<int>::const_iterator const_graph_iter;

void lca_dfs(const graph &graph, int v, int h = 1);

void lca_build_tree(int i, int l, int r);

void lca_prepare(const graph &graph, int root);

int lca_tree_min(int i, int sl, int sr, int l, int r);

int lca(int a, int b);