#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <map>

enum class NodeColor
{
    White,
    Grey,
    Black
};

class Graph
{
private:
    int node_count_;
    std::map<int, std::vector<int>> adjacency_list_;
    std::vector<NodeColor> node_colors_;
    std::stack<int> order;

public:
    Graph(int node_count, std::map<int, std::vector<int>> adjacency)
        :adjacency_list_(adjacency),  node_count_(node_count)
    {
        node_colors_.resize(node_count_);
        for (int i = 0; i < node_count; i++)
            node_colors_[i] = NodeColor::White;

    }

    void TS(int curr_node);
    std::vector<int> Sort();
    void Print_graph();
};