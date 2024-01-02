#pragma once

#include <cstddef>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits>

const auto INF = std::numeric_limits<int>::max(); 

enum class NodeColor
{
    White,
    Grey,
    Black
};

struct Edge
{
    int weight;
    size_t to;
};


using vector_t = std::vector<size_t>;
using pair_t = std::pair<size_t, size_t>;

struct Node
{
    int weight;

    size_t index;
    size_t prev_index;
    NodeColor color;

    std::vector<Edge> edges;
};

class Graph
{
public:

    void ReadGraph(std::vector<std::vector<int>> weight_matrix);

    std::pair<vector_t, int> FindPath(size_t start_index, size_t end_index);
    vector_t CorrectPath(size_t start_index, size_t end_index);

private:
    int node_count_;
    std::vector<Node> nodes;
};
