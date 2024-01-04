#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
#include <utility>
#include <vector>
#include <stack>
#include <map>

const auto INF = std::numeric_limits<int>::max();

enum class NodeColor
{
    White,
    Grey,
    Black
};

struct Edge
{
    size_t from;
    size_t to;
    int weight;
};

struct Vertex
{
    int weight;

    size_t index;
    NodeColor color;

    std::vector<Edge> edges;
};

class Graph
{
public:
    void ReadGraph(std::vector<std::vector<int>> weight_matrix);
    std::vector<int> FordBelman(size_t start_vertex);
    void DijkstraPreparation();
    void DijkstraUpdate();
    int Dijkstra(size_t start_index, size_t end_index);

    std::vector<std::vector<int>> jonson();
private:
    int edges_count;
    int vertex_count;
    std::vector<Vertex> vertexes;
    std::vector<Edge> edges;
};