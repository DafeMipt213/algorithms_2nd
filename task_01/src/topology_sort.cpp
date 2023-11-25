#include "topology_sort.hpp"

void Graph::TS(int curr_node)
{

    if (node_colors_[curr_node] != NodeColor::White)
        return;

    node_colors_[curr_node] = NodeColor::Grey;
    if (!adjacency_list_[curr_node].empty())
        for (auto iter = adjacency_list_[curr_node].begin(); iter != adjacency_list_[curr_node].end(); ++iter)
        {
            if (node_colors_[*iter] != NodeColor::Grey || node_colors_[*iter] != NodeColor::Black)
                TS(*iter);
        }

    order.push(curr_node);
    node_colors_[curr_node] = NodeColor::Black;
}

std::vector<int> Graph::Sort()
{
    for(std::map<int, std::vector<int>>::iterator iter = adjacency_list_.begin(); iter != adjacency_list_.end(); ++iter)
    {
        int key =  iter->first;
        TS(key);
    }

    std::vector<int> answer;
    for (int i = 0; i < node_count_; i++)
    {
        int temporary = order.top();
        answer.push_back(temporary);
        if (!order.empty())
            order.pop();
        else
            break;
    }

    return answer;
}


void Graph::Print_graph()
{
    for(std::map<int, std::vector<int>>::iterator iter = adjacency_list_.begin(); iter != adjacency_list_.end(); ++iter)
    {
        int key =  iter->first;
        std::vector<int> vec = iter->second;
        std::cout<<key<<": ";

        for (auto viter = vec.begin(); viter != vec.end(); viter++)
        {
            std::cout<<*viter<<' ';
        }

        std::cout<<"\n";
    }
}
