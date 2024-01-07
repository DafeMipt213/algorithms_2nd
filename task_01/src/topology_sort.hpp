#pragma once

#include <iostream>
#include <stack>
#include <vector>

enum Colors { kWhite = 0, kGray = 1, kBlack = 2 };

class Graph {
  int count_of_verticles;
  bool has_cycle = false;
  std::vector<bool> verticles;
  std::vector<std::vector<int>> adjacency_matrix;

  void DFS(int vertex, std::vector<Colors> &visited, std::stack<int> &stack);

 public:
  Graph(int count_of_verticles);
  std::vector<int> TopologicalSort();
  void AddEdge(int first_verticle, int second_verticle);
  void FillGraph(std::vector<std::vector<int>> graph);
  void AddVerticle(int verticle);
};
