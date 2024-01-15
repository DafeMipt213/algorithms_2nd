
#include <gtest/gtest.h>

#include "Dijkstra_alg.hpp"

TEST(DijkstraAlgorithm, Simple) {
  Graph graph{{Vertex(1, 1)}, {}};
  ASSERT_EQ(DijkstraAlgorithm(graph, 0, 1), 1);
}

TEST(DijkstraAlgorithm, Line) {
  Graph graph{
      {Vertex(1, 30)}, {Vertex(2, 50)}, {Vertex(3, 10)}, {Vertex(4, 20)}, {}};
  ASSERT_EQ(DijkstraAlgorithm(graph, 0, 4), 110);
}

TEST(DijkstraAlgorithm, Middle) {
  Graph graph{{Vertex(3, 30), Vertex(1, 10), Vertex(4, 100)},
              {Vertex(2, 50)},
              {Vertex(4, 10)},
              {Vertex(2, 20), Vertex(4, 60)},
              {}};
  ASSERT_EQ(DijkstraAlgorithm(graph, 0, 4), 60);
}

TEST(DijkstraAlgorithm, MiddleSecond) {
  Graph graph{{Vertex(2, 5), Vertex(1, 1), Vertex(4, 9)},
              {Vertex(2, 3)},
              {},
              {Vertex(2, 8), Vertex(4, 60)},
              {Vertex(2, 11), Vertex(3, 64)}};
  ASSERT_EQ(DijkstraAlgorithm(graph, 0, 2), 4);
}

TEST(DijkstraAlgorithm, MiddleThird) {
  Graph graph{{Vertex(5, 14), Vertex(1, 7), Vertex(2, 9)},
              {Vertex(2, 10), Vertex(3, 15), Vertex(0, 7)},
              {Vertex(1, 10), Vertex(3, 11), Vertex(0, 9), Vertex(5, 2)},
              {Vertex(1, 15), Vertex(2, 11), Vertex(4, 6)},
              {Vertex(3, 6), Vertex(5, 9)},
              {Vertex(4, 9), Vertex(2, 2), Vertex(0, 14)}};
  ASSERT_EQ(DijkstraAlgorithm(graph, 0, 4), 20);
}
