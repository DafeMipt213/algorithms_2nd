#include <vector>

struct Edge {
  int start;
  int end;
  int cost;
  Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {}
};

// Johnson's algorithm
std::vector<std::vector<int>> FindShortestPathes(const std::vector<Edge>& graph,
                                                 int vertexes_count);