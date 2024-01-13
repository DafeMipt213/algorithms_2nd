#include "bridges_and_cutpoints.hpp"

void innerFindBridges(const std::vector<std::vector<int>>& graph, int time,
                      std::vector<int>& tin, std::vector<int>& ret,
                      std::vector<int>& colors, int vertex, int parent,
                      std::set<std::pair<int, int>>& bridges) {
  tin[vertex] = ++time;
  ret[vertex] = time;
  colors[vertex] = 1;
  for (int i = 0; i < graph[vertex].size(); ++i) {
    if (graph[vertex][i] == parent) continue;
    if (colors[graph[vertex][i]] > 0)
      ret[vertex] = std::min(ret[vertex], tin[graph[vertex][i]]);
    else {
      innerFindBridges(graph, time, tin, ret, colors, graph[vertex][i], vertex,
                       bridges);
      ret[vertex] = std::min(ret[vertex], ret[graph[vertex][i]]);
      if (ret[graph[vertex][i]] > tin[vertex])
        bridges.insert(std::pair(graph[vertex][i], vertex));
    }
    colors[vertex] = 2;
  }
}

std::set<std::pair<int, int>> findBridges(
    const std::vector<std::vector<int>>& graph) {
  const int time = 0;
  std::vector<int> tin(graph.size());
  std::vector<int> ret(graph.size());
  std::vector<int> colors(graph.size());
  std::set<std::pair<int, int>> bridges;
  if (graph.size() == 0) return bridges;
  innerFindBridges(graph, time, tin, ret, colors, 0, -1, bridges);
  return bridges;
}

void innerFindCutPoints(const std::vector<std::vector<int>>& graph, int time,
                        std::vector<int>& tin, std::vector<int>& ret,
                        std::vector<int>& colors, int vertex, int parent,
                        std::set<int>& cut_points) {
  int children = 0;
  colors[vertex] = 1;
  tin[vertex] = ++time;
  ret[vertex] = time;
  for (size_t i = 0; i < graph[vertex].size(); ++i) {
    if (graph[vertex][i] == parent) continue;
    if (colors[graph[vertex][i]] != 0)
      ret[vertex] = std::min(ret[vertex], tin[graph[vertex][i]]);
    else {
      innerFindCutPoints(graph, time, tin, ret, colors, graph[vertex][i],
                         vertex, cut_points);
      ret[vertex] = std::min(ret[vertex], ret[graph[vertex][i]]);
      if (ret[graph[vertex][i]] >= tin[vertex] && parent != -1)
        cut_points.insert(vertex);
      ++children;
    }
  }
  if (parent == -1 && children > 1) cut_points.insert(vertex);
  colors[vertex] = 2;
}

std::set<int> findCutPoints(const std::vector<std::vector<int>>& graph) {
  const int time = 0;
  std::vector<int> tin(graph.size());
  std::vector<int> ret(graph.size());
  std::vector<int> colors(graph.size());
  std::set<int> cut_points;
  if (graph.size() == 0) return cut_points;
  innerFindCutPoints(graph, time, tin, ret, colors, 0, -1, cut_points);
  return cut_points;
}
