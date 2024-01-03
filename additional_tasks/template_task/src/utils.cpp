#include "utils.hpp"
#include <cstddef>
#include <vector>

void Graph::ReadGraph(std::vector<std::vector<int>> weight_matrix)
{
    this->vertex_count = weight_matrix[0].size();

    for (size_t i = 0; i < vertex_count; i++)
    {
        for (size_t j = 0; j < vertex_count; j++)
        {
            Edge temp_edge;

            if (weight_matrix[i][j] == INF) 
                continue;

            temp_edge.a = i;
            temp_edge.b = j;
            temp_edge.cost = weight_matrix[i][j];
            this->edges.push_back(temp_edge);
        }
    }

    this->edges_count = edges.size();
}

std::vector<int> Graph::FindPaths(size_t start_vertex)
{
    this->start_vertex = start_vertex;

    std::vector<int> distances (vertex_count, INF);
    distances[start_vertex] = 0;

    for (size_t i = 0; i < vertex_count - 1; ++i)
        for (size_t j = 0; j < edges_count; ++j)
            if (distances[edges[j].a] < INF)
                distances[edges[j].b] = std::min(distances[edges[j].b], distances[edges[j].a] + edges[j].cost);
    return distances;
}