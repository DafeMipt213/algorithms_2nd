#include "graph.hpp"

void Graph::Dfs(size_t vertex, size_t parent)
{
    timer_++;
    tin_[vertex] = timer_;
    ret_[vertex] = tin_[vertex];
    used_[vertex] = true;
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
                bridges_.push_back(std::pair<size_t, size_t> (vertex, to));
            if (ret_[to] >= tin_[vertex] and parent != -1)
                dots_.push_back(vertex);
        }
        if (parent == -1 && children > 1)  // it's root
            dots_.push_back(vertex);
    }
}

std::vector<size_t> FindRouters(Graph& g)
{
    if (g.Empty())
        g.FindBridgesAndDots();
    return g.GetDotes();
}

std::vector<std::pair<size_t, size_t>> FindWires(Graph& g)
{
    if (g.Empty())
        g.FindBridgesAndDots();
    return g.GetBridges();
}
