#include "topology_sort.hpp"

void Dfs(int ver, std::stack<int>& stack_ver, const Graph& graph,
         std::vector<bool>& visited) {
  if (visited[ver] == true) return;
  visited[ver] = true;
  for (std::size_t i = 0; i < graph[ver].size(); ++i) {
    int destination = graph[ver][i];
    if (!visited[destination]) {
      Dfs(destination, stack_ver, graph, visited);
      visited[destination] = true;
    }
  }
  stack_ver.push(ver);
}

Vertexes TopologySort(Graph graph) {
  std::stack<int> result_dfs;
  std::vector<bool> visited;
  visited = std::vector<bool>(graph.size());
  for (std::size_t i = 0; i < graph.size(); ++i) {
    Dfs(i, result_dfs, graph, visited);
  }
  Vertexes result_sort;
  while (!result_dfs.empty()) {
    result_sort.push_back(result_dfs.top());
    result_dfs.pop();
  }
  return result_sort;
}
