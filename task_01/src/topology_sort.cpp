#include "topology_sort.hpp"

#include <cstddef>
#include <stack>
#include <vector>

#include "graph.hpp"

class StackFunction : public AbstractFunction {
 public:
  StackFunction() : topology_stack{std::stack<size_t>()} {}
  void OnEdgeNotVisited(size_t from, size_t to, bool is_root) override {}
  void OnEdgeVisited(size_t from, size_t to, bool is_root) override {}
  void OnVertexBefore(size_t vertex, size_t p) override {}
  void OnVertexAfter(size_t vertex, size_t p) override {
    topology_stack.push(vertex);
  }
  std::stack<size_t> topology_stack;
};

std::vector<size_t> TopologySort(Graph<size_t>& graph, size_t vertex) {
  graph.ResetColors();
  StackFunction stack_function;
  graph.DFS(vertex, -1, true, &stack_function);
  std::vector<size_t> result;
  for (unsigned int i = 0; i < stack_function.topology_stack.size();) {
    result.push_back(stack_function.topology_stack.top());
    stack_function.topology_stack.pop();
  }
  return result;
}
