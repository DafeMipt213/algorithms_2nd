#ifndef GRAPH_VIEWS_H
#define GRAPH_VIEWS_H

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

class Adjacency_matrix;
class Adjacency_list_vec;
class Adjacency_list_unordered_set;
class Edge_list;

class Adjacency_matrix
{
private:
    std::vector<std::vector<bool>> data_;
public:
    Adjacency_matrix(const size_t size) : data_(size, std::vector<bool>(size, 0)) {}
    Adjacency_matrix(const std::vector<std::vector<bool>> data) : data_{data} {}

    const std::vector<bool>& operator[] (const size_t index) const { return data_[index]; }
    std::vector<bool>& operator[] (const size_t index) { return data_[index]; }

    friend std::ostream& operator<< (std::ostream &ost, Adjacency_matrix& matrix);

    Adjacency_matrix& operator= (const Adjacency_list_vec& vec_list);
    Adjacency_matrix& operator= (const Adjacency_list_unordered_set& list_unord);
    Adjacency_matrix& operator= (const Edge_list& edge_list);

    size_t size() const { return data_.size(); }

    const std::vector<std::vector<bool>>::iterator begin() { return data_.begin(); }
    const std::vector<std::vector<bool>>::iterator end() { return data_.end(); }

    std::vector<std::vector<bool>> get_matrix() const { return data_; }
    void load_matrix(const std::vector<std::vector<bool>> new_data) { data_ = new_data; };
};

class Adjacency_list_vec
{
private:
    std::vector<std::vector<size_t>> data_;
public:
    Adjacency_list_vec(const size_t size) : data_(size) {}
    Adjacency_list_vec(const std::vector<std::vector<size_t>> data) : data_{data} {}

    const std::vector<size_t>& operator[] (const size_t index) const { return data_[index]; }
    std::vector<size_t>& operator[] (const size_t index) { return data_[index]; }

    friend std::ostream& operator<< (std::ostream &ost, Adjacency_list_vec& list_vec);

    bool operator() (const size_t parent, const size_t child) const{
        const std::vector<size_t>& vec = data_[parent];
        return std::find(vec.begin(), vec.end(), child) != vec.end();
    }

    // add edge between node parent and child
    void add_edge(const size_t parent, const size_t child) { data_[parent].push_back(child); }
    size_t size() const { return data_.size(); }

    Adjacency_list_vec& operator= (const Adjacency_matrix& matrix);
    Adjacency_list_vec& operator= (const Adjacency_list_unordered_set& list);
    Adjacency_list_vec& operator= (const Edge_list& list);

    const std::vector<std::vector<size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::vector<size_t>>::iterator end() { return data_.end(); }

    std::vector<std::vector<size_t>> get_list() const { return data_; }
    void load_list(const std::vector<std::vector<size_t>> new_data) { data_ = new_data; };
};

class Adjacency_list_unordered_set
{
private:
    std::vector<std::unordered_set<size_t>> data_;
public:
    Adjacency_list_unordered_set(const size_t size) : data_(size) {}
    Adjacency_list_unordered_set(const std::vector<std::unordered_set<size_t>> data) : data_{data} {}

    const std::unordered_set<size_t>& operator[] (const size_t index) const { return data_[index]; }
    std::unordered_set<size_t>& operator[] (const size_t index) { return data_[index]; }

    friend std::ostream& operator<< (std::ostream &ost, Adjacency_list_unordered_set& list_unord_set);
    bool operator() (const size_t parent, const size_t child){
        const std::unordered_set<size_t>& unord_set = data_[parent];
        return std::find(unord_set.begin(), unord_set.end(), child) != unord_set.end();
    }

    // add edge between node parent and child
    void add_edge(const size_t parent, const size_t child) { data_[parent].insert(child); }
    size_t size() const { return data_.size(); }

    Adjacency_list_unordered_set& operator= (const Adjacency_matrix& matrix);
    Adjacency_list_unordered_set& operator= (const Adjacency_list_vec& list);
    Adjacency_list_unordered_set& operator= (const Edge_list& list);


    const std::vector<std::unordered_set<size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::unordered_set<size_t>>::iterator end() { return data_.end(); }

    std::vector<std::unordered_set<size_t>> get_list() const { return data_; }
    void load_list(const std::vector<std::unordered_set<size_t>> new_data) { data_ = new_data; };
};

class Edge_list
{
private:
    std::vector<std::pair<size_t, size_t>> data_;
public:
    Edge_list(const size_t size) : data_(size) {}
    Edge_list(const std::vector<std::pair<size_t, size_t>> data) : data_{data} {}

    friend std::ostream& operator<< (std::ostream &ost, Edge_list& edge_list);
    bool operator() (const std::pair<size_t, size_t> edge) { return std::find(data_.begin(), data_.end(), edge) != data_.end(); }
    bool operator() (const size_t parent, const size_t child) {
        std::pair<size_t, size_t> edge(parent, child);
        return std::find(data_.begin(), data_.end(), edge) != data_.end();
    }

    // add edge between node parent and child
    void add_edge(const size_t parent, const size_t child) { data_.push_back(std::pair<size_t, size_t> (parent, child)); }
    void add_edge(const std::pair<size_t, size_t> edge) { data_.push_back(edge); }
    size_t size() const { return data_.size(); }
    const std::pair<size_t, size_t>& operator[] (const size_t index) const { return data_[index]; }

    Edge_list& operator= (const Adjacency_matrix& matrix);
    Edge_list& operator= (const Adjacency_list_vec& list);
    Edge_list& operator= (const Adjacency_list_unordered_set& list);

    const std::vector<std::pair<size_t, size_t>>::iterator begin() { return data_.begin(); }
    const std::vector<std::pair<size_t, size_t>>::iterator end() { return data_.end(); }

    std::vector<std::pair<size_t, size_t>> get_list() const { return data_; }
    void load_list(const std::vector<std::pair<size_t, size_t>> new_data) { data_ = new_data; };
};

#endif // GRAPH_VIEWS_H
