#pragma once

#include <vector>


class AdjacencyListVec
{
private:
    std::vector<std::vector<size_t>> data_;
public:
    AdjacencyListVec(const size_t size) : data_(size) {}
    AdjacencyListVec(const std::vector<std::vector<size_t>> data) : data_{data} {}

    const std::vector<size_t>& operator[] (const size_t index) const { return data_[index]; }
    std::vector<size_t>& operator[] (const size_t index) { return data_[index]; }

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
};