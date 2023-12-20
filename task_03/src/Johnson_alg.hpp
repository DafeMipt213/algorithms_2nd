#include <vector>

struct edge {
  int start;
  int end;
  int cost;
  edge(int start, int end, int cost) : start(start), end(end), cost(cost) {}
};

std::vector<std::vector<int>> Johnson_algorithm(const std::vector<edge>& graph, int vertexes_count);