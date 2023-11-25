#include "special_points.hpp"

void Graph::AddEdge(size_t first, size_t second)
{
    edges[first].push_back(second);
    edges[second].push_back(first);
}

size_t Graph::size() const
{
    return edges.size();
}

const vector_t& Graph::GetNeighbours(size_t vertex) const
{
    return edges[vertex];
}

void Graph::Dfs(size_t vertex, size_t parent = -1)
{
    colors[vertex] = NodeColor::Grey;
    tin[vertex] = timer;
    fup[vertex] = timer;
    timer++;
    vector_t children = GetNeighbours(vertex);
    int children_count = 0;
    for (size_t i = 0; i < children.size(); ++i)
    {
        size_t to = children[i];
        if (to == parent) continue;

        if (colors[vertex] != NodeColor::White)
            fup[vertex] = std::min(fup[vertex], tin[to]);

        else
        {
            Dfs(to, vertex);
            fup[vertex] = std::min(fup[vertex], fup[to]);

            if (fup[to] >= tin[vertex] && parent != -1)
                cut_points.push_back(vertex);

            //if (fup[to] > tin[vertex])
                // bridges.push_back(vector_t(vertex, to));

            ++children_count;
        }
    }
    if (parent == -1 && children_count > 1)
        cut_points.push_back(vertex);
}

void Graph::WriteCutPoints()
{
    for (size_t i = 0; i < cut_points.size(); ++i)
        std::cout<<cut_points[i];
}

void Graph::WriteBridges()
{
    for (size_t i = 0; i < bridges.size(); ++i)
        std::cout<<bridges[i][0]<<"->"<<bridges[i][1]<<'\n';
}

void Graph::FindBridges() {
    timer = 0;
    for (int i=0; i < node_count; ++i)
        colors[i] = NodeColor::White;

    for (int j=0; j < node_count; ++j)
        if (colors[j] != NodeColor::White)
           Dfs(j);
}

void Graph::FindCutPoints()
{
    timer = 0;
    for (int i=0; i < node_count; ++i)
        colors[i] = NodeColor::White;
    Dfs(0);
}