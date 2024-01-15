#pragma once

#include <map>
#include <set>
#include <vector>

template <typename T = int>
struct Edge {
  T first_vertex, second_vertex;
};

template <typename T = int>
struct BridgesAndJoints {
  std::set<Edge<T>> bridges;
  std::set<T> joints;

  BridgesAndJoints(){};
};

template <typename T = int>
bool operator==(const Edge<T> a, const Edge<T> b) {
  return (a.first_vertex == b.first_vertex &&
          a.second_vertex == b.second_vertex) ||
         (a.first_vertex == b.second_vertex &&
          a.second_vertex == b.first_vertex);
}

template <typename T = int>
bool operator==(const BridgesAndJoints<T> &a, const BridgesAndJoints<T> &b) {
  return (a.bridges == b.bridges && a.joints == b.joints);
}

template <typename T = int>
bool operator<(const Edge<T> a, const Edge<T> b) {
  return (a.first_vertex < b.first_vertex && a.second_vertex < b.second_vertex);
};

template <typename T = int>
void DFS(int vertex, std::map<T, bool> &visited,
         std::map<T, std::vector<T>> &graph, std::map<T, int> &depth,
         std::map<T, int> &minimum_depth, BridgesAndJoints<T> &result,
         T previous, bool is_start = false) {
  visited[vertex] = true;
  minimum_depth[vertex] = depth[vertex] = (is_start ? 0 : depth[previous] + 1);
  int children = 0;
  for (int u : graph[vertex]) {
    if (u != previous || is_start) {
      if (visited[u])
        minimum_depth[vertex] = std::min(minimum_depth[vertex], depth[u]);
      else {
        DFS(u, visited, graph, depth, minimum_depth, result, vertex);
        minimum_depth[vertex] =
            std::min(minimum_depth[vertex], minimum_depth[u]);
        if (depth[vertex] < minimum_depth[u])
          result.bridges.insert({vertex, u});
        if (depth[vertex] <= minimum_depth[u] && !is_start)
          result.joints.insert(vertex);

        children++;
      }
    }
  }
  if (is_start && children > 1) result.joints.insert(vertex);
}

template <typename T = int>
BridgesAndJoints<T> Search(std::map<T, std::vector<T>> &graph) {
  BridgesAndJoints<T> result;

  std::map<T, int> depth;
  std::map<T, int> minimum_depth;
  std::map<T, bool> visited;

  for (auto &[vertex, _] : graph) {
    depth[vertex] = 0;
    minimum_depth[vertex] = 0;
    visited[vertex] = false;
  }

  for (auto &[vertex, _] : graph)
    DFS(vertex, visited, graph, depth, minimum_depth, result, vertex, true);
  return result;
}