
#include <gtest/gtest.h>

#include "Dijkstra_alg.hpp"

TEST(Dijkstra_alg, Simple) {
  Graph graph{{vertex(1, 1)}, {}};
  ASSERT_EQ(Dijkstra_alg(graph, 0, 1), 1);
}

TEST(Dijkstra_alg, Line) {
  Graph graph{
      {vertex(1, 30)}, {vertex(2, 50)}, {vertex(3, 10)}, {vertex(4, 20)}, {}};
  ASSERT_EQ(Dijkstra_alg(graph, 0, 4), 110);
}

TEST(Dijkstra_alg, Middle) {
  Graph graph{{vertex(3, 30), vertex(1, 10), vertex(4, 100)},
              {vertex(2, 50)},
              {vertex(4, 10)},
              {vertex(2, 20), vertex(4, 60)},
              {}};
  ASSERT_EQ(Dijkstra_alg(graph, 0, 4), 60);
}

TEST(Dijkstra_alg, MiddleSecond) {
  Graph graph{{vertex(2, 5), vertex(1, 1), vertex(4, 9)},
              {vertex(2, 3)},
              {},
              {vertex(2, 8), vertex(4, 60)},
              {vertex(2, 11), vertex(3, 64)}};
  ASSERT_EQ(Dijkstra_alg(graph, 0, 2), 4);
}

TEST(Dijkstra_alg, MiddleThird) {
  Graph graph{{vertex(5, 14), vertex(1, 7), vertex(2, 9)},
              {vertex(2, 10), vertex(3, 15), vertex(0, 7)},
              {vertex(1, 10), vertex(3, 11), vertex(0, 9), vertex(5, 2)},
              {vertex(1, 15), vertex(2, 11), vertex(4, 6)},
              {vertex(3, 6), vertex(5, 9)},
              {vertex(4, 9), vertex(2, 2), vertex(0, 14)}};
  ASSERT_EQ(Dijkstra_alg(graph, 0, 4), 20);
}
