#include "bridge_finder.hpp"

#include <cstddef>
#include <vector>

#include "abstract_function.hpp"

class FindBridgesFunction : public AbstractFunction {
 public:
  FindBridgesFunction(size_t n) : timer_{0}, tin_(n), up_(n), bridges_(0) {}

  void OnEdgeNotVisited(size_t from, size_t to) override {
    up_[from] = std::min(up_[from], up_[to]);
    if (up_[to] > tin_[from]) {
      IsBridge(to, from);
    }
  }

  void OnEdgeVisited(size_t from, size_t to) override {
    up_[from] = std::min(up_[from], tin_[to]);
  }

  void OnVertexBefore(size_t vertex, size_t p) override {
    tin_[vertex] = up_[vertex] = timer_++;
  }

  void OnVertexAfter(size_t vertex, size_t p) override {}

  std::vector<std::pair<size_t, size_t>> GetBridges() { return bridges_; }

 private:
  void IsBridge(size_t u, size_t v) {
    size_t min = std::min(u, v);
    size_t max = std::max(u, v);
    bridges_.push_back({min, max});
  }

 private:
  unsigned long long timer_;
  std::vector<unsigned long long> tin_;
  std::vector<unsigned long long> up_;
  std::vector<std::pair<size_t, size_t>> bridges_;
};

void InnerFindBridges(Graph& graph,
                      std::vector<std::pair<size_t, size_t>>& bridges_) {
  FindBridgesFunction f(graph.Size());
  graph.DFS(0, -1, &f);
  bridges_ = f.GetBridges();
}

std::vector<std::pair<size_t, size_t>> FindBrindges(Graph& graph) {
  std::vector<std::pair<size_t, size_t>> bridges_;
  InnerFindBridges(graph, bridges_);
  return bridges_;
}