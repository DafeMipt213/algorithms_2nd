#include <iostream>
#include <vector>

const int INF = 1e9;

class edge {
 public:
  int a;
  int b;
  int cost;
};

int main() {
  int n = 5, m = 8;

  std::vector<int> vec(n, INF);
  std::vector<edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                             {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
  int v = 0;
  vec[v] = 0;
  std::vector<int> p(n, -1);
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (int j = 0; j < m; ++j) {
      if (vec[edges[j].a] < INF) {
        if (vec[edges[j].b] > vec[edges[j].a] + edges[j].cost) {
          vec[edges[j].b] = std::max(-INF, vec[edges[j].a] + edges[j].cost);
          p[edges[j].b] = edges[j].a;
          x = edges[j].b;
        }
      }
    }
  }
  if (x != -1) {
    throw "Negative Cycle";
  }

  for (auto i : vec) {
    std::cout << i << " ";
  }
}