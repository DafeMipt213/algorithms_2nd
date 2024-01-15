#include "connected_graph.hpp"

Graph::Graph(std::vector<std::vector<int>> graph) : adjacency_list_(graph) {}

Graph::Graph(int vertices) : adjacency_list_(vertices) {}

std::vector<Edge> Graph::FindCriticalEdges() {
  std::vector<Edge> criticalEdges;
  for (int u = 0; u < adjacency_list_.size(); ++u)
    for (int v : adjacency_list_[u]) {
      if (u < v) {
        RemoveEdge(u, v);

        if (CountConnectedComponents() > 1) criticalEdges.push_back(Edge(u, v));

        AddEdge(u, v);
      }
    }
  return criticalEdges;
}

std::vector<int> Graph::FindCriticalRouters() {
  std::vector<int> criticalRouters;
  for (int u = 0; u < adjacency_list_.size(); ++u) {
    std::vector<std::vector<int>> copied_adjacency_list_ = adjacency_list_;
    RemoveRouter(u);

    if (CountConnectedComponents() > 1) criticalRouters.push_back(u);

    adjacency_list_ = copied_adjacency_list_;
  }
  return criticalRouters;
}

void Graph::Dfs(int v, std::vector<bool>& visited) {
  visited[v] = true;
  for (int u : adjacency_list_[v])
    if (!visited[u]) Dfs(u, visited);
}

int Graph::CountConnectedComponents() {
  std::vector<bool> visited(adjacency_list_.size(), false);
  int count = 0;

  for (int v = 0; v < adjacency_list_.size(); ++v)
    if (!visited[v]) {
      Dfs(v, visited);
      ++count;
    }

  return count;
}

void Graph::RemoveEdge(int u, int v) {
  auto removing_vertex =
      std::find(adjacency_list_[u].begin(), adjacency_list_[u].end(), v);
  if (removing_vertex != adjacency_list_[u].end())
    adjacency_list_[u].erase(removing_vertex);

  removing_vertex =
      std::find(adjacency_list_[v].begin(), adjacency_list_[v].end(), u);
  if (removing_vertex != adjacency_list_[v].end())
    adjacency_list_[v].erase(removing_vertex);
}

void Graph::AddEdge(int u, int v) {
  adjacency_list_[u].push_back(v);
  adjacency_list_[v].push_back(u);
}

void Graph::RemoveRouter(int u) {
  for (int v : adjacency_list_[u]) RemoveEdge(u, v);
  for (int i = u; i < adjacency_list_.size() - 1; ++i)
    adjacency_list_[i] = adjacency_list_[i + 1];
  adjacency_list_.pop_back();
}