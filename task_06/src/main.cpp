#include "LCA.hpp"

int main() {
  int n, m, root;
  std::cin >> n >> m;

  graph g;
  g.resize(n);

  int from, to;

  for (int i = 0; i < m; ++i) {
    std::cin >> from >> to;
    g[from].push_back(to);
    g[to].push_back(from);
  }
  std::cin >> root;
  lca_prepare(g, root);

  int v1, v2;
  std::cin >> v1 >> v2;
  std::cout << lca(v1, v2);
}