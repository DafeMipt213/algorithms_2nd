#include "graph.hpp"

void Graph::Dfs(int vertex, int parent)
{
    timer_++;
    tin_[vertex] = timer_;
    ret_[vertex] = tin_[vertex];
    size_t children = 0;
    for (auto to : data_[vertex])
    {
        if (to == parent)
            continue;
        if (used_[to])
            ret_[vertex] = std::min(ret_[vertex], tin_[to]);
        else
        {
            Dfs(to, vertex);
            ret_[vertex] = std::min(ret_[vertex], ret_[to]);
            children += 1;  // for root case
            if (ret_[to] == tin_[to])
                bridges_.push_back(std::pair<int, int> (vertex, to));
            if (ret_[to] >= tin_[vertex] and parent != -1)
                dots_.push_back(vertex);
        }
        if (parent == -1 && children > 1)
            dots_.push_back(vertex);
    }
}

std::vector<int> FindRouters(Graph& g)
{
    if (g.empty())
        g.FindBridgesAndDots();
    return g.GetDotes();
}

std::vector<std::pair<int, int>> FindWires(Graph& g)
{
    if (g.empty())
        g.FindBridgesAndDots();
    return g.GetBridges();
}
