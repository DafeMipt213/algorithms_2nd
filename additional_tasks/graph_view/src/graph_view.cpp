#include "graph_view.hpp"
#include "container_couts.hpp"

Adjacency_matrix& Adjacency_matrix::operator= (const Adjacency_list_vec& vec_list)
{
    data_.clear();
    data_.resize(vec_list.size(), std::vector<bool>(vec_list.size()));
    for (size_t vec_index = 0; vec_index < vec_list.size(); vec_index++)
        for (size_t index = 0; index < vec_list[vec_index].size(); index++)
            data_[vec_index][vec_list[vec_index][index]] = vec_list[vec_index][index] || vec_list[vec_index][index] == 0 ? true : false;
    return *this;
}

Adjacency_matrix& Adjacency_matrix::operator= (const Adjacency_list_unordered_set& unord_list)
{
    data_.clear();
    data_.resize(unord_list.size(), std::vector<bool>(unord_list.size()));
    for (size_t vec_index = 0; vec_index < unord_list.size(); vec_index++)
        for (size_t elem : unord_list[vec_index])
            data_[vec_index][elem] = elem || elem == 0 ? true : false;
    return *this;
}

Adjacency_matrix& Adjacency_matrix::operator= (const Edge_list& edge_list)
{
    data_.clear();
    size_t max_vertex{0};
    for (size_t index = 0; index < edge_list.size(); index++)
    {
        std::pair<size_t, size_t> pair = edge_list[index];
        size_t parent = pair.first;
        size_t child = pair.second;
        max_vertex = std::max(max_vertex, std::max(parent, child) + 1);
    }

    data_.resize(max_vertex, std::vector<bool>(max_vertex));

    for (size_t index = 0; index < edge_list.size(); index++)
    {
        std::pair<size_t, size_t> pair = edge_list[index];
        size_t parent = pair.first;
        size_t child = pair.second;
        size_t max_vertex = std::max(parent, child) + 1;
        data_[parent][child] = child || child == 0 ? true : false;
    }
    return *this;
}




Adjacency_list_vec& Adjacency_list_vec::operator= (const Adjacency_matrix& matrix)
{
    data_.clear();
    data_.resize(matrix.size());
    for (size_t vertex = 0; vertex < matrix.size(); vertex++)
        for (size_t index = 0; index < matrix.size(); index++)
            if(matrix[vertex][index]) data_[vertex].push_back(index);
    return *this;
}

Adjacency_list_vec& Adjacency_list_vec::operator= (const Adjacency_list_unordered_set& list)
{
    Adjacency_matrix matrix(3);
    matrix = list;
    *this = matrix;
    return *this;
}

Adjacency_list_vec& Adjacency_list_vec::operator= (const Edge_list& list)
{
    data_.clear();
    size_t max_vertex{0};
    for (size_t index = 0; index < list.size(); index++)
    {
        std::pair<size_t, size_t> pair = list[index];
        size_t parent = pair.first;
        size_t child = pair.second;
        max_vertex = std::max(max_vertex, std::max(parent, child) + 1);
    }
    data_.resize(max_vertex);
    for (size_t index = 0; index < list.size(); index++)
    {
        std::pair<size_t, size_t> pair = list[index];
        size_t parent = pair.first;
        size_t child = pair.second;
        data_[parent].push_back(child);
    }
    return *this;
}




Adjacency_list_unordered_set& Adjacency_list_unordered_set::operator= (const Adjacency_matrix& matrix)
{
    data_.clear();
    data_.resize(matrix.size());
    for (size_t vertex = 0; vertex < matrix.size(); vertex++)
        for (size_t index = 0; index < matrix.size(); index++)
            if(matrix[vertex][index]) data_[vertex].insert(index);
    return *this;
}

Adjacency_list_unordered_set& Adjacency_list_unordered_set::operator= (const Adjacency_list_vec& list)
{
    Adjacency_matrix matrix(3);
    matrix = list;
    *this = matrix;
    return *this;
}

Adjacency_list_unordered_set& Adjacency_list_unordered_set::operator= (const Edge_list& list)
{
    Adjacency_matrix matrix(3);
    matrix = list;
    *this = matrix;
    return *this;
}




Edge_list& Edge_list::operator= (const Adjacency_matrix& matrix)
{
    data_.clear();
    for (size_t vertex = 0; vertex < matrix.size(); vertex++)
        for (size_t index = 0; index < matrix.size(); index++)
            if(matrix[vertex][index]) data_.push_back(std::pair<size_t, size_t> (vertex, index));
    return *this;
}

Edge_list& Edge_list::operator= (const Adjacency_list_vec& list)
{
    data_.clear();
    for(size_t parent = 0; parent < list.size(); parent++)
    {
        for(size_t child : list[parent])
            data_.push_back(std::pair<size_t, size_t>(parent, child));
    }
    return *this;
}

Edge_list& Edge_list::operator= (const Adjacency_list_unordered_set& list)
{
    Adjacency_matrix matrix(3);
    matrix = list;
    *this = matrix;
    return *this;
}





std::ostream& operator<< (std::ostream& ost, Adjacency_matrix& matrix)
{
    for (auto& vec : matrix.data_)
        std::cout << vec << std::endl;
    return ost;
}

std::ostream& operator<< (std::ostream& ost, Adjacency_list_vec& list_vec)
{
    size_t i = 0;
    for (auto& vec : list_vec.data_)
        std::cout << i++ << ":" << vec << std::endl;
    return ost;
}

std::ostream& operator<< (std::ostream& ost, Adjacency_list_unordered_set& list_unord_set)
{
    for (auto& unord_set : list_unord_set.data_)
        std::cout << unord_set << std::endl;
    return ost;
}

std::ostream& operator<< (std::ostream& ost, Edge_list& edge_list)
{
    for (auto& pair : edge_list.data_)
        std::cout << pair << std::endl;
    return ost;
}
