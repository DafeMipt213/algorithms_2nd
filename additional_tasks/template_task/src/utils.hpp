#pragma once
#include <limits>
#include <vector>

const auto INF = std::numeric_limits<int>::max(); 

struct Edge
{
  size_t a;
  size_t b;
  int cost;  
};

class Graph
{
public:
    void ReadGraph(std::vector<std::vector<int>> weight_matrix);

    std::vector<int> FindPaths(size_t start_vertex);
private:
    int vertex_count;
    int edges_count;
    size_t start_vertex;
    std::vector<Edge> edges;
};