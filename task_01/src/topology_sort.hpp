#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define MAXV 10

struct Edgenote {
  int y;
  int weight;
  struct Edgenote *next;
};

struct Graph {
 public:
  void InitializeGraph(bool directed);
  void InsertEdge(int x, int y, bool directed);
  void ReadGraph(bool directed);
  void PrintGraph();
  void SetQuantity(int nvertices, int nedges);

  int EdgeClassification(int x, int y);
  void ProcessVertexLate(int v);
  void ProcessVertexEarly(int v);
  void ProcessEdge(int x, int y);
  void Dfs(int v);
  std::vector<int> TopSort();

 private:
  Edgenote *edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;

  bool processed[MAXV + 1];
  bool discovered[MAXV + 1];
  int parent[MAXV + 1];
  int entry_time[MAXV + 1];
  int exit_time[MAXV + 1];
  int time_count = 0;
  bool finished = false;
  std::stack<int> sorted;
};
