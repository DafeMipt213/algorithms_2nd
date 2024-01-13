#pragma once

#include <iostream>
#include <map>
#include <stack>
#include <vector>

enum class Colors { kWhite = 0, kGray = 1, kBlack = 2 };

template <typename T = int>
class Graph {
  int count_of_verticles;
  bool has_cycle = false;
  std::map<T, std::vector<T>> adjacency_matrix;
  void DFS(T vertex, std::map<T, Colors> &visited, std::stack<T> &stack);

 public:
  Graph(int count_of_verticles);
  std::vector<T> TopologicalSort();
  void AddEdge(T first_verticle, T second_verticle);
  void FillGraph(std::vector<std::vector<T>> graph);
  void AddVerticle(T verticle);
};

template <typename T>
Graph<T>::Graph(int count_of_verticles)
    : count_of_verticles(count_of_verticles) {}

template <typename T>
void Graph<T>::AddEdge(T first_verticle, T second_verticle) {
  adjacency_matrix[first_verticle].push_back(second_verticle);

  if (adjacency_matrix.find(second_verticle) == adjacency_matrix.end()) {
    adjacency_matrix[second_verticle] = {};
  }
}

template <typename T>
void Graph<T>::DFS(T vertex, std::map<T, Colors> &visited,
                   std::stack<T> &stack) {
  if (visited[vertex] == Colors::kGray)
    has_cycle = true;
  else if (visited[vertex] == Colors::kWhite) {
    visited[vertex] = Colors::kGray;
    for (int i = 0; i < adjacency_matrix[vertex].size(); i++)
      DFS(adjacency_matrix[vertex][i], visited, stack);
    visited[vertex] = Colors::kBlack;
    stack.push(vertex);
  }
}

template <typename T>
std::vector<T> Graph<T>::TopologicalSort() {
  std::stack<T> stack;
  std::map<T, Colors> visited;

  for (auto &[vertex, _] : adjacency_matrix) {
    visited[vertex] = Colors::kWhite;
  }

  for (auto &[vertex, _] : adjacency_matrix)
    if (visited[vertex] == Colors::kWhite) DFS(vertex, visited, stack);
  std::vector<T> result;
  while (!stack.empty() && !has_cycle) {
    result.push_back(stack.top());
    stack.pop();
  }
  return result;
}

template <typename T>
void Graph<T>::FillGraph(std::vector<std::vector<T>> graph) {
  for (int i = 0; i < graph.size(); i++) {
    AddEdge(graph[i][0], graph[i][1]);
  }
}

template <typename T>
void Graph<T>::AddVerticle(T verticle) {
  adjacency_matrix[verticle] = {};
}