#pragma once

#include <map>
#include <iostream>
#include <vector>
#include <set>

enum class NodeColor
{
    White,
    Grey,
    Black
};

using vector_t = std::vector<size_t>;
using set_t = std::set<size_t>;
using vector_color = std::vector<NodeColor>;

class Graph
{
public:
    Graph(size_t n)
        :node_count(n), colors(n), tin(n), fup(n), timer(0)
    {
        for (size_t i = 0; i < n; ++i)
            colors[i] = NodeColor::White;
    }

    Graph(int node_count, std::map<size_t, std::vector<size_t>> adjacency)
        :adjacency_list_(adjacency),  node_count(node_count)
    {
        colors.resize(node_count);
        for (int i = 0; i < node_count; i++)
            colors[i] = NodeColor::White;

        edges.resize(node_count);
        tin.resize(node_count);
        fup.resize(node_count);
        FillEdges();
    }

    void FillEdges();
    void AddEdge(size_t first, size_t second);

    size_t size() const;
    const vector_t& GetNeighbours(size_t vertex) const;

    void Dfs(size_t vertex, size_t parent);
    void FindCutPoints();
    void FindBridges();

    set_t RetCut() {return cut_points;}
    std::set<std::pair<size_t, size_t>> RetBridges() {return bridges;}

private:
    int node_count;

    std::map<size_t, vector_t> adjacency_list_;
    std::vector<vector_t> edges;
    vector_color colors;
    
    vector_t tin;
    vector_t fup;
    size_t timer;

    set_t cut_points;
    std::set<std::pair<size_t, size_t>> bridges;
};