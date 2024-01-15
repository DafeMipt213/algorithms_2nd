#include "bridge_finder.hpp"

#include <cstddef>
#include <vector>

#include "tin_up_function.hpp"

class FindBridgesFunction : public TinUpFunction {
 public:
  FindBridgesFunction(size_t n) : TinUpFunction(n) {}

  void OnEdgeNotVisited(size_t from, size_t to, bool is_root) override {
    up_[from] = std::min(up_[from], up_[to]);
    if (up_[to] > tin_[from]) {
      IsBridge(to, from);
    }
  }

  void OnVertexAfter(size_t vertex, size_t parent) override {}

  std::vector<std::pair<size_t, size_t>> GetBridges() { return bridges_; }

 private:
  void IsBridge(size_t u, size_t v) {
    size_t min = std::min(u, v);
    size_t max = std::max(u, v);
    bridges_.push_back({min, max});
  }
  std::vector<std::pair<size_t, size_t>> bridges_;
};

void InnerFindBridges(Graph<size_t>& graph,
                      std::vector<std::pair<size_t, size_t>>& bridges_) {
  FindBridgesFunction f(graph.Size());
  graph.DFS(0, -1, true, &f);
  bridges_ = f.GetBridges();
}

std::vector<std::pair<size_t, size_t>> FindBrindges(Graph<size_t>& graph) {
  std::vector<std::pair<size_t, size_t>> bridges_;
  InnerFindBridges(graph, bridges_);
  return bridges_;
}