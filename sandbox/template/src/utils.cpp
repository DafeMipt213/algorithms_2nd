#include "utils.hpp"
#include <algorithm>

void Graph::InitializeGraph(std::size_t size)
{
    nodes_count_ = size;
    is_used_.resize(nodes_count_, 0);
    is_counted_.resize(nodes_count_, 0);
    portals_.resize(nodes_count_);
    for (std::size_t i = 0; i < size; i++)
//        while (bool road = cin.get() != '\n')
//            portals_[i].push_back(road);
        for (std::size_t j = 0; j < size; j++)
        {
            bool road;
            std::cin >> road;
            portals_[i].push_back(road);
        }
}

void Graph::DFS(size_t v)
{
    for (std::size_t j = 0; j < nodes_count_; j++)
        if (!is_used_[j] && portals_[v][j])
        {
            is_used_[j] = true;
            DFS(j);
        }
}

void Graph::ClearUsed()
{
    for (std::size_t i = 0; i < nodes_count_; i++)
    {
        is_used_[i] = false;
        is_counted_[i] = false;
    }
}

void Graph::FindPaths()
{
    for (std::size_t i = 0; i < nodes_count_; i++)
    {
        DFS(i);
        for (std::size_t j = 0; j < nodes_count_; j++)
            if (is_used_[j])
                portals_[i][j] = 1;
        ClearUsed();
    }
}

void Graph::WriteAnswer()
{
    for (std::size_t i = 0; i < nodes_count_; i++)
    {
        for (std::size_t j = 0; j < nodes_count_; j++)
            std::cout << portals_[i][j];
        std::cout<<'\n';
    }
}

void Graph::Programm(std::size_t n)
{
    InitializeGraph(n);
    FindPaths();
    WriteAnswer();
}

void Graph::TestInitialize(std::vector<std::vector<bool>> g)
{
    nodes_count_ = g.size();
    is_used_.resize(nodes_count_, 0);
    is_counted_.resize(nodes_count_, 0);
    portals_.resize(nodes_count_);
    portals_.resize(g.size());
    std::copy(g.begin(), g.end(), portals_.begin());
}

std::vector<std::vector<bool>> Graph::GetPortals()
{
    return portals_;
}