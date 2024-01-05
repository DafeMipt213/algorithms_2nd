#ifndef GRAPH_VIEWS_H
#define GRAPH_VIEWS_H

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

class AdjacencyMatrix;
class AdjacencyListVec;
class AdjacencyListUnorderedSet;
class EdgeList;

class AdjacencyMatrix
{
private:
    std::vector<std::vector<bool>> data_;
public:
    AdjacencyMatrix(const size_t size) : data_(size, std::vector<bool>(size, 0)) {}
    AdjacencyMatrix(const std::vector<std::vector<bool>> data) : data_{data} {}

    const std::vector<bool>& operator[] (const size_t index) const { return data_[index]; }
    std::vector<bool>& operator[] (const size_t index) { return data_[index]; }

    friend std::ostream& operator<< (std::ostream &ost, AdjacencyMatrix& matrix);

    AdjacencyMatrix& operator= (const AdjacencyListVec& vec_list);
    AdjacencyMatrix& operator= (const AdjacencyListUnorderedSet& list_unord);
    AdjacencyMatrix& operator= (const EdgeList& edge_list);

    size_t size() const { return data_.size(); }

    const std::vector<std::vector<bool>>::iterator begin() { return data_.begin(); }
    const std::vector<std::vector<bool>>::iterator end() { return data_.end(); }

    std::vector<std::vector<bool>> GetMatrix() const { return data_; }
    void LoadMatrix(const std::vector<std::vector<bool>> new_data) { data_ = new_data; };
};

class AdjacencyListVec
{
private:
    std::vector<std::vector<size_t>> data_;
public:
    AdjacencyListVec(const size_t size) : data_(size) {}
    AdjacencyListVec(const std::vector<std::vector<size_t>> data) : data_{data} {}

    const std::vector<size_t>& operator[] (const size_t index) const { return data_[index]; }
    std::vector<size_t>& operator[] (const size_t index) { return data_[index]; }

    friend std::ostream& operator<< (std::ostream &ost, AdjacencyListVec& list_vec);

    bool operator() (const size_t parent, const size_t child) const{
        const std::vector<size_t>& vec = data_[parent];
        return std::find(vec.begin(), vec.end(), child) != vec.end();
    }

    // add edge between node parent and child
    void AddEdge(const size_t parent, const size_t child) { data_[parent].push_back(child); }
    size_t size() const { return data_.size(); }

    AdjacencyListVec& operator= (const AdjacencyMatrix& matrix);
    AdjacencyListVec& operator= (const AdjacencyListUnorderedSet& list);
    AdjacencyListVec& operator= (const EdgeList& list);

    const std::vector<std::vector<size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::vector<size_t>>::iterator end() { return data_.end(); }

    std::vector<std::vector<size_t>> GetList() const { return data_; }
    void LoadList(const std::vector<std::vector<size_t>> new_data) { data_ = new_data; };
};

class AdjacencyListUnorderedSet
{
private:
    std::vector<std::unordered_set<size_t>> data_;
public:
    AdjacencyListUnorderedSet(const size_t size) : data_(size) {}
    AdjacencyListUnorderedSet(const std::vector<std::unordered_set<size_t>> data) : data_{data} {}

    const std::unordered_set<size_t>& operator[] (const size_t index) const { return data_[index]; }
    std::unordered_set<size_t>& operator[] (const size_t index) { return data_[index]; }

    friend std::ostream& operator<< (std::ostream &ost, AdjacencyListUnorderedSet& list_unord_set);
    bool operator() (const size_t parent, const size_t child){
        const std::unordered_set<size_t>& unord_set = data_[parent];
        return std::find(unord_set.begin(), unord_set.end(), child) != unord_set.end();
    }

    // add edge between node parent and child
    void AddEdge(const size_t parent, const size_t child) { data_[parent].insert(child); }
    size_t size() const { return data_.size(); }

    AdjacencyListUnorderedSet& operator= (const AdjacencyMatrix& matrix);
    AdjacencyListUnorderedSet& operator= (const AdjacencyListVec& list);
    AdjacencyListUnorderedSet& operator= (const EdgeList& list);


    const std::vector<std::unordered_set<size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::unordered_set<size_t>>::iterator end() { return data_.end(); }

    std::vector<std::unordered_set<size_t>> GetList() const { return data_; }
    void LoadList(const std::vector<std::unordered_set<size_t>> new_data) { data_ = new_data; };
};

class EdgeList
{
private:
    std::vector<std::pair<size_t, size_t>> data_;
public:
    EdgeList(const size_t size) : data_(size) {}
    EdgeList(const std::vector<std::pair<size_t, size_t>> data) : data_{data} {}

    friend std::ostream& operator<< (std::ostream &ost, EdgeList& edge_list);
    bool operator() (const std::pair<size_t, size_t> edge) { return std::find(data_.begin(), data_.end(), edge) != data_.end(); }
    bool operator() (const size_t parent, const size_t child) {
        std::pair<size_t, size_t> edge(parent, child);
        return std::find(data_.begin(), data_.end(), edge) != data_.end();
    }

    // add edge between node parent and child
    void AddEdge(const size_t parent, const size_t child) { data_.push_back(std::pair<size_t, size_t> (parent, child)); }
    void AddEdge(const std::pair<size_t, size_t> edge) { data_.push_back(edge); }
    size_t size() const { return data_.size(); }
    const std::pair<size_t, size_t>& operator[] (const size_t index) const { return data_[index]; }

    EdgeList& operator= (const AdjacencyMatrix& matrix);
    EdgeList& operator= (const AdjacencyListVec& list);
    EdgeList& operator= (const AdjacencyListUnorderedSet& list);

    const std::vector<std::pair<size_t, size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::pair<size_t, size_t>>::iterator end() { return data_.end(); }

    std::vector<std::pair<size_t, size_t>> GetList() const { return data_; }
    void LoadList(const std::vector<std::pair<size_t, size_t>> new_data) { data_ = new_data; };
};

#endif // GRAPH_VIEWS_H
