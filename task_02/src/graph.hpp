#pragma once

#include <vector>


class Graph
{
private:
    std::vector<std::vector<int>> data_;
    size_t timer_;
    std::vector<size_t> tin_;  // times of enter in vertex
    std::vector<size_t> ret_;  // ret_[v] = min(tin_[v], tin_[u]), where u - vertex before v (it can be not reacheable from v) 
    std::vector<bool> used_;  // visited vertexes

    std::vector<int> dots_;  // joint points
    std::vector<std::pair<int, int>> bridges_; 

    void Dfs(int vertex, int parent=-1);

public:
    Graph(const size_t size) : data_(size) {}
    Graph(const std::vector<std::vector<size_t>> data) : data_{data} {}

    const std::vector<size_t>& operator[] (const size_t index) const { return data_[index]; }
    std::vector<int>& operator[] (const size_t index) { return data_[index]; }

    bool operator() (const size_t parent, const size_t child) const{
        const std::vector<int>& vec = data_[parent];
        return std::find(vec.begin(), vec.end(), child) != vec.end();
    }

    // add edge between node parent and child
    void AddEdge(const size_t parent, const size_t child) { data_[parent].push_back(child); }
    size_t size() const { return data_.size(); }

    const std::vector<std::vector<int>>::iterator begin() { return data_.begin(); }
    const std::vector<std::vector<int>>::iterator end() { return data_.end(); }

    std::vector<std::vector<int>> GetList() const { return data_; }
    void LoadList(const std::vector<std::vector<size_t>> new_data) { data_ = new_data; };

    void FindBridgesAndDots() { Dfs(0); };
    std::vector<std::pair<int, int>> GetBridges() { return bridges_; };
    std::vector<int> GetDotes() { return dots_; };

    bool empty() { return data_.empty(); };
};

std::vector<int> FindRouters(Graph& g);
std::vector<std::pair<int, int>> FindWires(Graph& g);