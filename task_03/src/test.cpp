#include <gtest/gtest.h>

#include <iostream>

#include "johnson.hpp"

TEST(JohnsonAlgorithm, GraphFromHabr) {
  Graph graph;
  graph.AddEdge(1, 2, -2);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(1, 4, 5);
  graph.AddEdge(2, 4, 6);
  graph.AddEdge(2, 3, 8);
  graph.AddEdge(3, 4, -4);
  graph.AddEdge(3, 2, 3);
  graph.AddEdge(4, 1, -1);

  std::map<int, std::map<int, long long>> result = {
      {1, {{1, 0}, {2, -2}, {3, 6}, {4, 2}}},
      {2, {{1, 3}, {2, 0}, {3, 8}, {4, 4}}},
      {3, {{1, -5}, {2, -7}, {3, 0}, {4, -4}}},
      {4, {{1, -1}, {2, -3}, {3, 5}, {4, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, SimpleGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 3);
  graph.AddEdge(2, 3, 4);
  graph.AddEdge(3, 1, -6);

  std::map<int, std::map<int, long long>> result = {
      {1, {{1, 0}, {2, 3}, {3, 7}}},
      {2, {{1, -2}, {2, 0}, {3, 4}}},
      {3, {{1, -6}, {2, -3}, {3, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, MediumGraph) {
  Graph graph;
  for (int i = 1; i <= 4; ++i) {
    graph.AddEdge(i, i % 4 + 1, i);
  }

  std::map<int, std::map<int, long long>> result = {
      {1, {{1, 0}, {2, 1}, {3, 3}, {4, 6}}},
      {2, {{1, 9}, {2, 0}, {3, 2}, {4, 5}}},
      {3, {{1, 7}, {2, 8}, {3, 0}, {4, 3}}},
      {4, {{1, 4}, {2, 5}, {3, 7}, {4, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, ComplexGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 3);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(2, 4, 2);
  graph.AddEdge(2, 5, 3);
  graph.AddEdge(3, 6, 1);
  graph.AddEdge(4, 7, 4);
  graph.AddEdge(5, 7, 1);
  graph.AddEdge(6, 7, 5);

  std::map<int, std::map<int, long long>> result = {
      {1, {{1, 0}, {2, 3}, {3, 7}, {4, 5}, {5, 6}, {6, 8}, {7, 7}}},
      {2,
       {{1, std::numeric_limits<long long>::max()},
        {2, 0},
        {3, std::numeric_limits<long long>::max()},
        {4, 2},
        {5, 3},
        {6, std::numeric_limits<long long>::max()},
        {7, 4}}},
      {3,
       {{1, std::numeric_limits<long long>::max()},
        {2, std::numeric_limits<long long>::max()},
        {3, 0},
        {4, std::numeric_limits<long long>::max()},
        {5, std::numeric_limits<long long>::max()},
        {6, 1},
        {7, 6}}},
      {4,
       {{1, std::numeric_limits<long long>::max()},
        {2, std::numeric_limits<long long>::max()},
        {3, std::numeric_limits<long long>::max()},
        {4, 0},
        {5, std::numeric_limits<long long>::max()},
        {6, std::numeric_limits<long long>::max()},
        {7, 4}}},
      {5,
       {{1, std::numeric_limits<long long>::max()},
        {2, std::numeric_limits<long long>::max()},
        {3, std::numeric_limits<long long>::max()},
        {4, std::numeric_limits<long long>::max()},
        {5, 0},
        {6, std::numeric_limits<long long>::max()},
        {7, 1}}},
      {6,
       {{1, std::numeric_limits<long long>::max()},
        {2, std::numeric_limits<long long>::max()},
        {3, std::numeric_limits<long long>::max()},
        {4, std::numeric_limits<long long>::max()},
        {5, std::numeric_limits<long long>::max()},
        {6, 0},
        {7, 5}}},
      {7,
       {{1, std::numeric_limits<long long>::max()},
        {2, std::numeric_limits<long long>::max()},
        {3, std::numeric_limits<long long>::max()},
        {4, std::numeric_limits<long long>::max()},
        {5, std::numeric_limits<long long>::max()},
        {6, std::numeric_limits<long long>::max()},
        {7, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, FullyConnectedGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 3);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(2, 4, 2);
  graph.AddEdge(2, 5, 3);
  graph.AddEdge(3, 6, 1);
  graph.AddEdge(4, 7, 4);
  graph.AddEdge(5, 7, 1);
  graph.AddEdge(6, 7, 5);
  graph.AddEdge(3, 1, 2);
  graph.AddEdge(4, 2, 1);
  graph.AddEdge(5, 4, 2);
  graph.AddEdge(6, 3, 1);
  graph.AddEdge(7, 6, 2);

  std::map<int, std::map<int, long long>> result = {
      {1, {{1, 0}, {2, 3}, {3, 7}, {4, 5}, {5, 6}, {6, 8}, {7, 7}}},
      {2, {{1, 9}, {2, 0}, {3, 7}, {4, 2}, {5, 3}, {6, 6}, {7, 4}}},
      {3, {{1, 2}, {2, 5}, {3, 0}, {4, 7}, {5, 8}, {6, 1}, {7, 6}}},
      {4, {{1, 9}, {2, 1}, {3, 7}, {4, 0}, {5, 4}, {6, 6}, {7, 4}}},
      {5, {{1, 6}, {2, 3}, {3, 4}, {4, 2}, {5, 0}, {6, 3}, {7, 1}}},
      {6, {{1, 3}, {2, 6}, {3, 1}, {4, 8}, {5, 9}, {6, 0}, {7, 5}}},
      {7, {{1, 5}, {2, 8}, {3, 3}, {4, 10}, {5, 11}, {6, 2}, {7, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, FullyConnectedGraphNegative) {
  Graph graph;
  graph.AddEdge(1, 2, -3);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(2, 4, 2);
  graph.AddEdge(2, 5, 3);
  graph.AddEdge(3, 6, 1);
  graph.AddEdge(4, 7, -4);
  graph.AddEdge(5, 7, 1);
  graph.AddEdge(6, 7, 5);
  graph.AddEdge(3, 1, 2);
  graph.AddEdge(4, 2, -1);
  graph.AddEdge(5, 4, 2);
  graph.AddEdge(6, 3, 1);
  graph.AddEdge(7, 6, 2);

  std::map<int, std::map<int, long long>> result{
      {1, {{1, 0}, {2, -3}, {3, -2}, {4, -1}, {5, 0}, {6, -3}, {7, -5}}},
      {2, {{1, 3}, {2, 0}, {3, 1}, {4, 2}, {5, 3}, {6, 0}, {7, -2}}},
      {3, {{1, 2}, {2, -1}, {3, 0}, {4, 1}, {5, 2}, {6, -1}, {7, -3}}},
      {4, {{1, 1}, {2, -2}, {3, -1}, {4, 0}, {5, 1}, {6, -2}, {7, -4}}},
      {5, {{1, 3}, {2, 0}, {3, 1}, {4, 2}, {5, 0}, {6, 0}, {7, -2}}},
      {6, {{1, 3}, {2, 0}, {3, 1}, {4, 2}, {5, 3}, {6, 0}, {7, -2}}},
      {7, {{1, 5}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 2}, {7, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, FullyConnectedGraphNegativeCycled) {
  Graph graph;
  graph.AddEdge(1, 2, -3);
  graph.AddEdge(1, 3, 7);
  graph.AddEdge(2, 4, 2);
  graph.AddEdge(2, 5, -3);
  graph.AddEdge(3, 6, 1);
  graph.AddEdge(4, 7, -4);
  graph.AddEdge(5, 7, 1);
  graph.AddEdge(6, 7, 5);
  graph.AddEdge(3, 1, 2);
  graph.AddEdge(4, 2, -1);
  graph.AddEdge(5, 4, 2);
  graph.AddEdge(6, 3, -1);
  graph.AddEdge(7, 6, -2);

  std::map<int, std::map<int, long long>> result{};

  ASSERT_EQ(graph.Johnson(), result);
}

TEST(JohnsonAlgorithm, AnotherGraph) {
  Graph graph;
  graph.AddEdge(1, 2, 4);
  graph.AddEdge(1, 3, 1);
  graph.AddEdge(2, 3, 2);
  graph.AddEdge(2, 4, 5);
  graph.AddEdge(3, 4, 8);
  graph.AddEdge(4, 1, 1);

  std::map<int, std::map<int, long long>> result{
      {1, {{1, 0}, {2, 4}, {3, 1}, {4, 9}}},
      {2, {{1, 6}, {2, 0}, {3, 2}, {4, 5}}},
      {3, {{1, 9}, {2, 13}, {3, 0}, {4, 8}}},
      {4, {{1, 1}, {2, 5}, {3, 2}, {4, 0}}}};

  ASSERT_EQ(graph.Johnson(), result);
}