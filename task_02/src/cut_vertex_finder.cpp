#include "cut_vertex_finder.hpp"

#include <cstddef>
#include <vector>

#include "tin_up_function.hpp"

class FindCutVertexesFunction : public TinUpFunction {
 public:
  FindCutVertexesFunction(size_t n) : TinUpFunction(n) {}

  void OnEdgeNotVisited(size_t from, size_t to, bool is_root) override {
    up_[from] = std::min(up_[from], up_[to]);
    if (up_[to] >= tin_[from] && !is_root) {
      IsCutVertex(from);
    }
    children_[from]++;
  }

  void OnVertexAfter(size_t vertex, size_t parent) override {
    if (parent == -1 && children_[vertex] > 1) {
      IsCutVertex(vertex);
    }
  }

  std::vector<size_t> GetCutVertexes() { return cut_vertexes_; }

 private:
  void IsCutVertex(size_t v) { cut_vertexes_.push_back(v); }
  std::vector<size_t> cut_vertexes_;
};

void InnerFindCutVertexes(Graph<size_t>& graph,
                          std::vector<size_t>& cut_vertexes) {
  FindCutVertexesFunction f(graph.Size());
  graph.DFS(0, -1, true, &f);
  cut_vertexes = f.GetCutVertexes();
}

std::vector<size_t> FindCutVertexes(Graph<size_t>& graph) {
  std::vector<size_t> cut_vertexes;
  InnerFindCutVertexes(graph, cut_vertexes);
  return cut_vertexes;
}