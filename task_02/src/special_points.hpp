#pragma once

#include <map>
#include <iostream>
#include <vector>

using vector_t = std::vector<size_t>;

enum class NodeColor
{
    White,
    Grey,
    Black
};

class Graph
{
public:
    explicit Graph(size_t n)
        :node_count(n), colors(n), tin(n), fup(n), timer(0)
    {
        for (size_t i = 0; i < n; ++i)
            colors[i] = NodeColor::White;
    }

    Graph(int node_count, std::map<int, std::vector<int>> adjacency)
        :adjacency_list_(adjacency),  node_count(node_count)
    {
        colors.resize(node_count);
        for (int i = 0; i < node_count; i++)
            colors[i] = NodeColor::White;

        edges.resize(node_count);
        tin.resize(node_count);
        fup.resize(node_count);
    }

    void AddEdge(size_t first, size_t second);

    size_t size() const;
    const vector_t& GetNeighbours(size_t vertex) const;

    void Dfs(size_t vertex, size_t parent);
    void FindCutPoints();
    void FindBridges();

    void WriteCutPoints();
    void WriteBridges();

    vector_t RetCut() {return cut_points;}

private:
    int node_count;
    std::map<int, std::vector<int>> adjacency_list_;
    std::vector<NodeColor> colors;
    std::vector<vector_t> edges;
    vector_t tin;
    vector_t fup;
    size_t timer;

    vector_t cut_points;
    std::vector<vector_t> bridges;
};