
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(TopologySort, SimpleGraph) {
  Graph graph(6);
  graph.FillGraph({{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}});
  std::vector<int> sort_data{5, 4, 2, 3, 1, 0};
  ASSERT_EQ(graph.TopologicalSort(), sort_data);
}

TEST(TopologySort, CycleGraph) {
  Graph graph(3);
  graph.FillGraph({{1, 2}, {0, 2}, {0, 0}});
  std::vector<int> sort_data{};
  ASSERT_EQ(graph.TopologicalSort(), sort_data);
}

TEST(TopologySort, WikiGraph) {
  Graph graph(12);
  graph.FillGraph({{3, 8},
                   {3, 10},
                   {5, 11},
                   {7, 11},
                   {7, 8},
                   {8, 9},
                   {11, 2},
                   {11, 9},
                   {11, 10}});
  std::vector<int> sort_data{
      7,  5, 11, 3,
      10, 8, 9,  2};  // wiki version(without {7, 5, 11, 3, 8, 2, 9, 10};
  ASSERT_EQ(graph.TopologicalSort(), sort_data);
}

TEST(TopologySort, EmptyGraph) {
  Graph graph(0);
  graph.FillGraph({});
  std::vector<int> sort_data{};
  ASSERT_EQ(graph.TopologicalSort(), sort_data);
}

TEST(TopologySort, TwoPartGraph) {
  Graph graph(7);
  graph.FillGraph({{1, 2}, {2, 3}, {4, 5}, {5, 6}});
  std::vector<int> sort_data{4, 5, 6, 1, 2, 3};
  ASSERT_EQ(graph.TopologicalSort(), sort_data);
}

TEST(TopologySort, OneVerticleGraph) {
  Graph graph(1);
  graph.AddVerticle(0);
  std::vector<int> sort_data{0};
  ASSERT_EQ(graph.TopologicalSort(), sort_data);
}