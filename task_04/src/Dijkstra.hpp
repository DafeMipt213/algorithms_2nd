#include <limits>
#include <queue>
#include <vector>

class Vertex {
 public:
  int destination;
  int distance;

  Vertex(int destination, int distance);

  bool operator>(const Vertex& V) const;
};

int Dijkstra(const std::vector<std::vector<Vertex>>& graph, int from, int to);