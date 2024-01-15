#pragma once
#include <iostream>
#include <vector>

class Graph
{
private:
    std::size_t nodes_count_;
    std::vector<bool> is_counted_;
    std::vector<bool> is_used_;
    std::vector<std::vector<bool>> portals_;
public:
    void InitializeGraph(std::size_t size);
    void TestInitialize(std::vector<std::vector<bool>> g);
    void DFS(std::size_t v);
    void ClearUsed();
    void FindPaths();
    void WriteAnswer();
    void Programm(std::size_t n);
    std::vector<std::vector<bool>> GetPortals();
};

