
#include <gtest/gtest.h>

#include "Dijkstra.hpp"

TEST(Dijkstra, Simple_With_Way) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {4, 500}}, {{2, 2}, {4, 5}}, {{3, 1}}, {{4, 1}}, {}};
  ASSERT_EQ(Dijkstra(graph, 0, 4), 5);
}

TEST(Dijkstra, Simple_No_Way) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}}, {{2, 2}}, {{3, 1}}, {}, {}};
  ASSERT_EQ(Dijkstra(graph, 0, 4), -1);
}

TEST(Dijkstra, Big_Unit_Graph_WithWay) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {8, 1}}, {{2, 1}}, {{4, 1}}, {{2, 1}, {4, 1}}, {}, {{7, 1}}, {{5, 1}, {7, 1}}, {{2, 1}, {4, 1}}, {{6, 1}, {9, 1}}, {{6, 1}}};
  ASSERT_EQ(Dijkstra(graph, 0, 4), 3);
}

TEST(Dijkstra, Big_Unit_Graph_Without_Way) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {8, 1}}, {{2, 1}}, {{4, 1}}, {{2, 1}, {4, 1}}, {}, {{7, 1}}, {{5, 1}, {7, 1}}, {{2, 1}, {4, 1}}, {{6, 1}, {9, 1}}, {{6, 1}}};
  ASSERT_EQ(Dijkstra(graph, 3, 5), -1);
}

TEST(Dijkstra, Big_Unit_Graph_Neighbours) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {8, 1}}, {{2, 1}}, {{4, 1}}, {{2, 1}, {4, 1}}, {}, {{7, 1}}, {{5, 1}, {7, 1}}, {{2, 1}, {4, 1}}, {{6, 1}, {9, 1}}, {{6, 1}}};
  ASSERT_EQ(Dijkstra(graph, 9, 6), 1);
}

TEST(Dijkstra, Line_Graph) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}}, {{2, 2}}, {{3, 3}}, {{4, 4}}, {{5, 500}}, {}};
  ASSERT_EQ(Dijkstra(graph, 0, 5), 510);
}

TEST(Dijkstra, Cyclic_Oriented_Graph) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {6, 1}}, {{2, 1}, {0, 1}}, {{3, 1}, {1, 1}}, {{4, 500}, {2, 1}}, {{3, 1}, {5, 1}}, {{4, 500}, {6, 1}}, {{0, 1}, {5, 1}}};
  ASSERT_EQ(Dijkstra(graph, 3, 5), 5);
}

TEST(Dijkstra, Several_Edges_Between_Same_Vertexes) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {6, 1}}, {{2, 1}, {0, 1}}, {{3, 1}, {1, 1}}, {{4, 500}, {4, 1}, {2, 1}}, {{3, 1}, {5, 1}}, {{4, 500}, {4, 1}, {6, 1}}, {{0, 1}, {5, 1}}};
  ASSERT_EQ(Dijkstra(graph, 3, 5), 2);
}

TEST(Dijkstra, Tree) {
  std::vector<std::vector<Vertex>> graph = {{{1, 98}, {2, 73}}, {{5, 24}, {6, 37}}, {{3, 11}, {4, 24}}, {}, {}, {{7, 99}, {8, 55}}, {{9, 17}, {10, 17}}, {}, {}, {}, {}};
  ASSERT_EQ(Dijkstra(graph, 0, 9), 152);
}

TEST(Dijkstra, To_Self) {
  std::vector<std::vector<Vertex>> graph = {{{1, 0}}, {{0, 1}}};
  ASSERT_EQ(Dijkstra(graph, 0, 0), 0);
}

TEST(Dijkstra, Several_Ways) {
  std::vector<std::vector<Vertex>> graph = {{{1, 1}, {1, 2}, {1, 500}, {1, 0}}, {{0, 1}}};
  ASSERT_EQ(Dijkstra(graph, 0, 1), 0);
}