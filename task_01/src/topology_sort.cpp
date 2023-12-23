#include "topology_sort.hpp"



void Graph::dfs(int vertex)
{    
    tin[vertex] = timer++;
    colors[vertex] = 1;
    for(size_t i = 0; i < graph_list[vertex].size(); ++i)
    {
        if(colors[graph_list[vertex][i]] == 0)
            dfs(graph_list[vertex][i]);
    }
    tout[vertex] = timer++;
    colors[vertex] = 2;
}

void Graph::fillStack(int vertex)
{    
    tin[vertex] = timer++;
    colors[vertex] = 1;
    for(size_t i = 0; i < graph_list[vertex].size(); ++i)
    {
        if(colors[graph_list[vertex][i]] == 0)
        {
            fillStack(graph_list[vertex][i]);
        }
    }
    topology_stack.push(vertex);
    tout[vertex] = timer++;
    colors[vertex] = 2;

    int still_white = -1;
    int grey_vertexes = 0;
    for (size_t i = 0; i < colors.size(); ++i)
    {
        if(colors[i] == 0)
        {
            still_white = i;
        } else if(colors[i] == 1)
        {
            grey_vertexes += 1;
            break;
        }
    }
    if(grey_vertexes == 0 && still_white != -1)
    {
        fillStack(still_white);
    }
}

std::vector<int> Graph::topologySort(int vertex)
{
    fillStack(vertex);
    std::vector<int> result;
    while (topology_stack.empty() == false)
    {
        result.push_back(topology_stack.top());
        topology_stack.pop();
    }
    return result;
}

Graph::Graph(std::vector<std::vector<int>> new_graph)
{
    graph_list = new_graph;
    timer = 0;
    tin.resize(graph_list.size());
    tout.resize(graph_list.size());
    colors.resize(graph_list.size());
}