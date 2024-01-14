#include <functional>
#include <limits>
#include <map>
#include <utility>
#include <vector>

const int inf = std::numeric_limits<int>::infinity() + 1;

enum class Color { White, Grey, Black };

class Graph {
public:
  Graph() : graph_{}, marks_{} {}

  void Add(int elem, int parent, int weight = 1);
  bool IsCycle();
  bool Find(int elem);
  int Size() { return graph_.size(); }

  void DFS(int u, std::function<void(int)> action, bool is_clean_marks = true);
  std::map<int, int> Dijkstra(int s);
  bool FordBellman(int s, std::map<int, int> &d);
  std::map<int, std::vector<std::pair<int, int>>> Johnson();
  void FindBridgesAndCutPoins(std::vector<std::pair<int, int>> &bridges,
                                     std::vector<int> &cut_pnts);

private:
  std::map<int, std::vector<std::pair<int, int>>> graph_;
  std::map<int, Color> marks_;
  bool is_cycle_ = false;

  int timer_ = 0;
  std::map<int, int> tin_{}, ret_{};
  void DFSForBridgesAndCutPoints(std::vector<std::pair<int, int>> &bridges,
                                 std::vector<int> &cut_pnts, int v,
                                 int p = -inf);
};
