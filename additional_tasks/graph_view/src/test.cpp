#include <gtest/gtest.h>

#include "graph_view.hpp"

using namespace testing;

TEST(Graphs_view_test_system, Adjacency_matrix_base)
{
    AdjacencyMatrix x(5);
    x[0][1] = 1;
    ASSERT_EQ(x[2][3], 0);
    ASSERT_EQ(x[0][1], 1);
    AdjacencyMatrix y(std::vector<std::vector<bool>> {
        {0,1,1,0,1,0},
        {1,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}});
    ASSERT_EQ(y[0][3], 0);
    ASSERT_EQ(y[1][1], 1);
}

TEST(Graphs_view_test_system, Adjacency_matrix_convertion)
{
    AdjacencyMatrix matrix_1(3);
    AdjacencyMatrix matrix_2(3);
    AdjacencyMatrix matrix_3(3);
    AdjacencyListUnorderedSet unord_set_list(std::vector<std::unordered_set<size_t>>{
        {1,2,4},
        {0,1,2,2},
        {2},
        {},
        {},
        {},
    });
    AdjacencyListVec vec_list(std::vector<std::vector<size_t>>{
        {1,2,4},
        {0,1,2,2},
        {2},
        {},
        {},
        {},
    });
    EdgeList edge_list(std::vector<std::pair<size_t, size_t>>
        {{0,1},{0,2},{0,4},{1,0},{1,1},{1,2},{1,2},{2,2}});

    matrix_1 = vec_list;
    std::vector<std::vector<bool>> result_vec{
        {0,1,1,0,1,0},
        {1,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}};
    ASSERT_EQ(matrix_1.GetMatrix(), result_vec);

    matrix_2 = unord_set_list;
    ASSERT_EQ(matrix_2.GetMatrix(), result_vec);

    matrix_3 = edge_list;
    result_vec = std::vector<std::vector<bool>>{
        {0,1,1,0,1},
        {1,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};
    ASSERT_EQ(matrix_3.GetMatrix(), result_vec);
}

TEST(Graphs_view_test_system, Adjacency_list_vec_convertion)
{
    AdjacencyMatrix matrix(std::vector<std::vector<bool>>{
        {0,1,1,0,1,0},
        {0,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}});
    AdjacencyListVec vec_list_1(3);
    vec_list_1 = matrix;
    std::vector<std::vector<size_t>> result_vec{
        {1,2,4},
        {1,2},
        {2},
        {},
        {},
        {}};
    ASSERT_EQ(vec_list_1.GetList(), result_vec);

    AdjacencyListVec vec_list_2(3);
    AdjacencyListUnorderedSet unord_set_list(
        std::vector<std::unordered_set<size_t>>{
        {1,2,4},
        {0,1,2,2},
        {2},
        {},
        {},
        {}});
    vec_list_2 = unord_set_list;
    result_vec = std::vector<std::vector<size_t>>{
        {1,2,4},
        {0,1,2},
        {2},
        {},
        {},
        {}};
    ASSERT_EQ(vec_list_2.GetList(), result_vec);

    AdjacencyListVec vec_list_3(3);
    EdgeList edge_list(std::vector<std::pair<size_t, size_t>>
        {{0,1},{0,2},{0,4},{1,0},{1,1},{1,2},{1,2},{2,2}});
    vec_list_3 = edge_list;
    result_vec = std::vector<std::vector<size_t>>{
        {1,2,4},
        {0,1,2,2},
        {2},
        {},
        {}};
    ASSERT_EQ(vec_list_3.GetList(), result_vec);
}

TEST(Graphs_view_test_system, Adjacency_list_unordered_set_convertion)
{
    AdjacencyListUnorderedSet unord_set_list_1(3);

    AdjacencyMatrix matrix(std::vector<std::vector<bool>>{
        {0,1,1,0,1,0},
        {0,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}});
    unord_set_list_1 = matrix;
    std::vector<std::unordered_set<size_t>> result_unord_set{
        {1,2,4},
        {1,2},
        {2},
        {},
        {},
        {}};
    ASSERT_EQ(unord_set_list_1.GetList(), result_unord_set);

    AdjacencyListUnorderedSet unord_set_list_2(3);
    AdjacencyListVec vec_list(std::vector<std::vector<size_t>>{
        {1,2,4},
        {0,1,2,2},
        {2},
        {},
        {},
        {}});
    unord_set_list_2 = vec_list;
    result_unord_set = std::vector<std::unordered_set<size_t>>{
        {1,2,4},
        {0,1,2},
        {2},
        {},
        {},
        {}};
    ASSERT_EQ(unord_set_list_2.GetList(), result_unord_set);

    AdjacencyListUnorderedSet unord_set_list_3(3);
    EdgeList edge_list(std::vector<std::pair<size_t, size_t>>
        {{0,1},{0,2},{0,4},{1,0},{1,1},{1,2},{1,2},{2,2}});
    unord_set_list_3 = edge_list;
    result_unord_set = std::vector<std::unordered_set<size_t>>{
        {1,2,4},
        {0,1,2},
        {2},
        {},
        {}};
    ASSERT_EQ(unord_set_list_3.GetList(), result_unord_set);
}

TEST(Graphs_view_test_system, Edge_list_convertion)
{
    AdjacencyMatrix matrix(std::vector<std::vector<bool>>{
        {0,1,1,0,1,0},
        {0,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}});
    EdgeList edge_list_1(3);
    edge_list_1 = matrix;
    std::vector<std::pair<size_t, size_t>> result_list(
        {{0,1},{0,2},{0,4},{1,1},{1,2},{2,2}});
    ASSERT_EQ(edge_list_1.GetList(), result_list);

    AdjacencyListVec vec_list = (std::vector<std::vector<size_t>>{
        {1,2,4},
        {0,1,2,2},
        {2},
        {},
        {},
        {}});
    EdgeList edge_list_2(3);
    edge_list_2 = vec_list;
    result_list = std::vector<std::pair<size_t, size_t>>(
        {{0,1},{0,2},{0,4},{1,0},{1,1},{1,2},{1,2},{2,2}});
    ASSERT_EQ(edge_list_2.GetList(), result_list);

    AdjacencyListUnorderedSet unord_set_list(
        std::vector<std::unordered_set<size_t>>{
            {1,2,4},
            {0,1,2,2},
            {2},
            {},
            {},
            {}});
    EdgeList edge_list_3(3);
    edge_list_3 = unord_set_list;
    result_list = std::vector<std::pair<size_t, size_t>>(
        {{0,1},{0,2},{0,4},{1,0},{1,1},{1,2},{2,2}});
    ASSERT_EQ(edge_list_3.GetList(), result_list);
}
