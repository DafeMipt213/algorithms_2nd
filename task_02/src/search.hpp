#pragma once

#include <vector>

// для неориентированного графа без кратных рёбер, задаваемого списком смежности

using Graph = std::vector<std::vector<char>>;
struct edge{
    char start;
    char end;
    edge(char start, char end) : start{start}, end{end} {}
    bool operator == (const edge& edge1) const
    {
        return (start == edge1.start && end == edge1.end || start == edge1.end && end == edge1.start);
    }
};

std::vector<edge> bridge_search(const Graph& graph);
std::vector<char> dots_search(const Graph& graph);
