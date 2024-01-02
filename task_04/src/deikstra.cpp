#include "deikstra.hpp"
#include <cstddef>
#include <stack>
#include <vector>

void Graph::ReadGraph(std::vector<std::vector<int>> weight_matrix)
{
    this->node_count_ = weight_matrix[0].size();
    this->nodes.resize(node_count_);
    
    for (size_t i = 0; i < node_count_; i++)
    {
        nodes[i].weight = INF;
        nodes[i].index = i;
        nodes[i].prev_index = -1;
        nodes[i].color = NodeColor::White;

        for (size_t j = 0; j < node_count_; j++)
        {
            nodes[i].edges.resize(node_count_);
            nodes[i].edges[j].weight = weight_matrix[i][j];
            nodes[i].edges[j].to = j;
        }
    }
}

vector_t Graph::CorrectPath(size_t start_index, size_t end_index)
{
    vector_t result;
    std::stack<size_t> tmp_path;
    int current_node = end_index;

    while (current_node != -1)
    {
        tmp_path.push(current_node);
        current_node = this->nodes[current_node].prev_index;
    }
    
    while(!tmp_path.empty())
    {
        result.push_back(tmp_path.top());
        tmp_path.pop();
    }

    return result;
}

std::pair<vector_t, int> Graph::FindPath(size_t start_index, size_t end_index)
{
    std::multimap<int, size_t> min_weight_map;
    this->nodes[start_index].weight = 0;
    min_weight_map.insert({0, start_index});
    while (!min_weight_map.empty())
    {
        auto [current_weight, current_index] = *(min_weight_map.begin());
        min_weight_map.erase(min_weight_map.begin());
        
        if (nodes[current_index].color != NodeColor::White) continue;

        nodes[current_index].color = NodeColor::Grey;

        for (size_t i = 0; i < nodes[current_index].edges.size(); i++)
        {
            int index_to = nodes[current_index].edges[i].to;
            int edge_weight = nodes[current_index].edges[i].weight;
            if (nodes[index_to].color == NodeColor::White)
            {
                if (current_weight + edge_weight < nodes[index_to].weight && current_weight + edge_weight > 0)
                {
                    nodes[index_to].weight = current_weight + edge_weight;
                    nodes[index_to].prev_index = current_index;
                    min_weight_map.insert({nodes[index_to].weight, index_to});
                }
            }
        }
    }

    vector_t path = CorrectPath(start_index, end_index);

    std::pair ans {path, nodes[end_index].weight};
    return ans;
}