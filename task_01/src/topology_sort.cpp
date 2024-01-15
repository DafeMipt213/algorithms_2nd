#include "topology_sort.hpp"

Graph::Graph(std::vector<std::vector<int>> graph) : adjacency_list_(graph) {}

Graph::Graph(int vertices) : adjacency_list_(vertices) {}

void Graph::AddEdge(int u, int v) { adjacency_list_[u].push_back(v); }

std::vector<int> Graph::TopologicalSort() {
  std::vector<Color> vertices_color(adjacency_list_.size(), Color::White);
  std::stack<int> result;

  for (size_t i = 0; i < adjacency_list_.size(); ++i)
    if (vertices_color[i] == Color::White)
      if (!Dfs(i, vertices_color, result))
        throw std::runtime_error("Graph contains a cycle!");

  std::vector<int> sort_return;
  while (!result.empty()) {
    sort_return.push_back(result.top());
    result.pop();
  }

  return sort_return;
}

bool Graph::Dfs(int current_vertex, std::vector<Color>& vertices_color,
                std::stack<int>& result) {
  vertices_color[current_vertex] = Color::Gray;

  for (int neighbor : adjacency_list_[current_vertex])
    if (vertices_color[neighbor] == Color::White) {
      if (!Dfs(neighbor, vertices_color, result)) return false;
    } else if (vertices_color[neighbor] == Color::Gray)
      return false;

  vertices_color[current_vertex] = Color::Black;
  result.push(current_vertex);
  return true;
}