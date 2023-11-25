#include "special_points.hpp"

void Graph::FillEdges()
{
    for(std::map<size_t, std::vector<size_t>>::iterator iter = adjacency_list_.begin(); iter != adjacency_list_.end(); ++iter)
    {
        size_t key =  iter->first;
        std::vector<size_t> vec = iter->second;

        for (auto viter = vec.begin(); viter != vec.end(); viter++)
        {
            edges[key].push_back(*viter);
        }
    }
}

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
    if (node_count == 0)
        return;
        
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

        if (colors[to] != NodeColor::White)
            fup[vertex] = std::min(fup[vertex], tin[to]);
        else
        {
            Dfs(to, vertex);
            fup[vertex] = std::min(fup[vertex], fup[to]);

            if (fup[to] >= tin[vertex] && parent != -1)
                cut_points.insert(vertex);

            if (fup[to] > tin[vertex])
                bridges.insert(std::pair(to, vertex));

            ++children_count;
        }
    }
    if (parent == -1 && children_count > 1)
        cut_points.insert(vertex);
}

void Graph::FindBridges() {
    timer = 0;
    for (int i=0; i < node_count; ++i)
        colors[i] = NodeColor::White;

    for (int j=0; j < node_count; ++j)
        if (colors[j] == NodeColor::White)
           Dfs(j);
}

void Graph::FindCutPoints()
{
    timer = 0;
    for (int i=0; i < node_count; ++i)
        colors[i] = NodeColor::White;
    Dfs(0);
}