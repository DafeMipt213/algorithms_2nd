#include "bridges_and_joints.hpp"

#include <iostream>

bool operator==(const Edge a, const Edge b) {
  return (a.first_vertex == b.first_vertex &&
          a.second_vertex == b.second_vertex) ||
         (a.first_vertex == b.second_vertex &&
          a.second_vertex == b.first_vertex);
}

bool operator<(const Edge a, const Edge b) {
  return (a.first_vertex < b.first_vertex && a.second_vertex < b.second_vertex);
}

bool operator==(const BridgesAndJoints a, const BridgesAndJoints b) {
  return (a.bridges == b.bridges && a.joints == b.joints);
}

void DFS(int vertex, std::vector<bool> &visited,
         std::vector<std::vector<int>> &graph, std::vector<int> &depth,
         std::vector<int> &minimum_depth, BridgesAndJoints &result,
         int previous) {
  visited[vertex] = true;
  minimum_depth[vertex] = depth[vertex] =
      (previous == -1 ? 0 : depth[previous] + 1);
  int children = 0;
  for (int u : graph[vertex]) {
    if (u != previous) {
      if (visited[u])
        minimum_depth[vertex] = std::min(minimum_depth[vertex], depth[u]);
      else {
        DFS(u, visited, graph, depth, minimum_depth, result, vertex);
        minimum_depth[vertex] =
            std::min(minimum_depth[vertex], minimum_depth[u]);
        if (depth[vertex] < minimum_depth[u])
          result.bridges.insert({vertex, u});
        if (depth[vertex] <= minimum_depth[u] && previous != -1)
          result.joints.insert(vertex);

        children++;
      }
    }
  }
  if (previous == -1 && children > 1) result.joints.insert(vertex);
}

BridgesAndJoints Search(std::vector<std::vector<int>> &graph) {
  BridgesAndJoints result;
  std::vector<int> depth(graph.size(), 0);
  std::vector<int> minimum_depth(graph.size(), 0);
  std::vector<bool> visited(graph.size(), false);
  for (int i = 0; i < graph.size(); i++)
    DFS(i, visited, graph, depth, minimum_depth, result);
  return result;
}