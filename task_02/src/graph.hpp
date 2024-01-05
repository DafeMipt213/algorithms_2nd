#pragma once

#include <vector>
#include <algorithm>


class Graph
{
private:
    std::vector<std::vector<size_t>> data_;
    size_t timer_;
    std::vector<size_t> tin_;  // times of enter in vertex
    std::vector<size_t> ret_;  // ret_[v] = min(tin_[v], tin_[u]), where u - vertex before v (it can be not reacheable from v) 
    std::vector<bool> used_;  // visited vertexes

    std::vector<size_t> dots_;  // articulation points
    std::vector<std::pair<size_t, size_t>> bridges_; 

    void Dfs(size_t vertex, size_t parent=-1);
    bool calculation_done = false;  // if dots and bridges have already found

public:
    Graph(const size_t size) : data_(size), tin_(size), ret_(size), used_(size) {}
    Graph(const std::vector<std::vector<size_t>> data) : data_{data}, tin_(data.size()), ret_(data.size()), used_(data.size()) {}

    std::vector<size_t> operator[] (const size_t index) const { return data_[index]; }

    // check if edge exist between parent and child
    bool operator() (const size_t parent, const size_t child) const{
        const std::vector<size_t>& vec = data_[parent];
        return std::find(vec.begin(), vec.end(), child) != vec.end();
    }

    // add edge between node parent and child
    void AddEdge(const size_t parent, const size_t child) { data_[parent].push_back(child); }
    size_t size() const { return data_.size(); }

    const std::vector<std::vector<size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::vector<size_t>>::iterator end() { return data_.end(); }

    std::vector<std::vector<size_t>> GetList() const { return data_; }
    void LoadList(const std::vector<std::vector<size_t>> new_data) { data_ = new_data; };

    void FindBridgesAndDots() { Dfs(0); };
    std::vector<std::pair<size_t, size_t>> GetBridges() { return bridges_; };
    std::vector<size_t> GetDotes() { return dots_; };

    bool Empty() { return !calculation_done; };
};

std::vector<size_t> FindRouters(Graph& g);
std::vector<std::pair<size_t, size_t>> FindWires(Graph& g);