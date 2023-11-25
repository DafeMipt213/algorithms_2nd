#pragma once

#include <vector>

// для неориентированного графа без кратных рёбер, задаваемого списком смежности

using Graph = std::vector<std::vector<int>>;
struct edge {
  int start;
  int end;
  edge(int start, int end) : start{start}, end{end} {}
  bool operator==(const edge& edge1) const {
    return (start == edge1.start && end == edge1.end ||
            start == edge1.end && end == edge1.start);
  }
};

std::vector<edge> BridgeSearch(const Graph& graph);
std::vector<int> DotSearch(const Graph& graph);

Graph Prepare(const Graph& graph);
