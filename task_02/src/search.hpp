#pragma once

#include <vector>

// для неориентированного графа без кратных рёбер, задаваемого списком смежности

using Graph = std::vector<std::vector<int>>;
struct Edge {
  int start;
  int end;
  Edge(int start, int end) : start{start}, end{end} {}
  bool operator==(const Edge& edge1) const {
    return (start == edge1.start && end == edge1.end ||
            start == edge1.end && end == edge1.start);
  }
};

std::vector<Edge> BridgesSearch(const Graph& graph);
std::vector<int> DotsSearch(const Graph& graph);

Graph Prepare(const Graph& graph);
