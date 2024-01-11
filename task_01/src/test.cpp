
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph<std::string> graph;
  graph.AddEdge("a", "b");
  graph.AddEdge("a", "c");
  graph.AddEdge("a", "d");
  graph.AddEdge("a", "e");
  graph.AddEdge("b", "d");
  graph.AddEdge("c", "d");
  graph.AddEdge("c", "e");
  graph.AddEdge("d", "e");

  std::vector<std::string> result{"a", "c", "b", "d", "e"};

  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, SimpleCycled) {
  Graph<std::string> graph;
  graph.AddEdge("a", "b");
  graph.AddEdge("b", "a");
  graph.AddEdge("a", "c");
  graph.AddEdge("a", "d");
  graph.AddEdge("a", "e");
  graph.AddEdge("b", "d");
  graph.AddEdge("c", "d");
  graph.AddEdge("c", "e");
  graph.AddEdge("d", "e");

  std::vector<std::string> result = {};

  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, SimpleGraph) {
  Graph<int> graph;
  graph.AddEdge(5, 2);
  graph.AddEdge(5, 0);
  graph.AddEdge(4, 0);
  graph.AddEdge(4, 1);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 1);
  std::vector<int> result{5, 4, 2, 3, 1, 0};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithCycleInOneVertex) {
  Graph<int> graph;
  graph.AddEdge(0, 0);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 2);
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithTwoComponents) {
  Graph<int> graph;
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(4, 5);
  graph.AddEdge(5, 6);
  graph.AddEdge(5, 7);
  std::vector<int> result{4, 5, 7, 6, 0, 1, 3, 2};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithThreeComponents) {
  Graph<int> graph;
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(4, 5);
  graph.AddEdge(5, 6);
  graph.AddEdge(5, 7);
  graph.AddEdge(8, 9);
  graph.AddEdge(9, 10);
  graph.AddEdge(9, 11);
  std::vector<int> result{8, 9, 11, 10, 4, 5, 7, 6, 0, 1, 3, 2};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, EmptyGraph) {
  Graph graph;
  std::vector<int> result{};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, ComplexGraph) {
  Graph<std::string> graph;
  graph.AddEdge("a", "b");
  graph.AddEdge("a", "c");
  graph.AddEdge("b", "d");
  graph.AddEdge("b", "e");
  graph.AddEdge("c", "f");
  graph.AddEdge("c", "g");
  graph.AddEdge("d", "h");
  graph.AddEdge("e", "h");
  graph.AddEdge("f", "i");
  graph.AddEdge("g", "i");
  graph.AddEdge("h", "j");
  graph.AddEdge("i", "j");

  std::vector<std::string> result{"a", "c", "g", "f", "i",
                                  "b", "e", "d", "h", "j"};

  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, ComplexCycled) {
  Graph<std::string> graph;
  graph.AddEdge("a", "b");
  graph.AddEdge("b", "c");
  graph.AddEdge("c", "d");
  graph.AddEdge("d", "e");
  graph.AddEdge("e", "f");
  graph.AddEdge("f", "g");
  graph.AddEdge("g", "h");
  graph.AddEdge("h", "i");
  graph.AddEdge("i", "j");
  graph.AddEdge("j", "a");

  std::vector<std::string> result{};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, ComplexDoubleGraph) {
  Graph<double> graph;
  graph.AddEdge(1.1, 2.2);
  graph.AddEdge(1.1, 3.3);
  graph.AddEdge(2.2, 4.4);
  graph.AddEdge(2.2, 5.5);
  graph.AddEdge(3.3, 6.6);
  graph.AddEdge(3.3, 7.7);
  graph.AddEdge(4.4, 8.8);
  graph.AddEdge(5.5, 8.8);
  graph.AddEdge(6.6, 9.9);
  graph.AddEdge(7.7, 9.9);
  graph.AddEdge(8.8, 10.10);
  graph.AddEdge(9.9, 10.10);

  std::vector<double> result{1.1, 3.3, 7.7, 6.6, 9.9,
                             2.2, 5.5, 4.4, 8.8, 10.10};

  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWithTwoComponentsChar) {
  Graph<char> graph;
  graph.AddEdge('a', 'b');
  graph.AddEdge('b', 'c');
  graph.AddEdge('b', 'd');
  graph.AddEdge('g', 'h');
  graph.AddEdge('h', 'l');
  graph.AddEdge('h', 'k');
  std::vector<char> result{'g', 'h', 'k', 'l', 'a', 'b', 'd', 'c'};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, ComplexGraphDouble) {
  Graph<double> graph;
  graph.AddEdge(1.1, 2.2);
  graph.AddEdge(2.2, 3.3);
  graph.AddEdge(3.3, 4.4);
  graph.AddEdge(4.4, 5.5);
  graph.AddEdge(1.1, 6.6);
  graph.AddEdge(6.6, 7.7);
  graph.AddEdge(7.7, 8.8);
  std::vector<double> result{1.1, 6.6, 7.7, 8.8, 2.2, 3.3, 4.4, 5.5};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, ComplexGraphChar) {
  Graph<char> graph;
  graph.AddEdge('a', 'b');
  graph.AddEdge('b', 'c');
  graph.AddEdge('c', 'd');
  graph.AddEdge('d', 'e');
  graph.AddEdge('a', 'f');
  graph.AddEdge('f', 'g');
  graph.AddEdge('g', 'h');
  std::vector<char> result{'a', 'f', 'g', 'h', 'b', 'c', 'd', 'e'};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, ComplexGraphInt) {
  Graph<int> graph;
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.AddEdge(4, 5);
  graph.AddEdge(1, 6);
  graph.AddEdge(6, 7);
  graph.AddEdge(7, 8);
  std::vector<int> result{1, 6, 7, 8, 2, 3, 4, 5};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, GraphWith20VerticesNonLinear) {
  Graph<int> graph;
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(0, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(1, 5);
  graph.AddEdge(2, 6);
  graph.AddEdge(2, 7);
  graph.AddEdge(3, 8);
  graph.AddEdge(3, 9);
  graph.AddEdge(4, 10);
  graph.AddEdge(5, 11);
  graph.AddEdge(6, 12);
  graph.AddEdge(7, 13);
  graph.AddEdge(8, 14);
  graph.AddEdge(9, 15);
  graph.AddEdge(10, 16);
  graph.AddEdge(11, 17);
  graph.AddEdge(12, 18);
  graph.AddEdge(13, 19);
  std::vector<int> result{0, 3,  9,  15, 8, 14, 2,  7, 13, 19,
                          6, 12, 18, 1,  5, 11, 17, 4, 10, 16};
  ASSERT_EQ(graph.TopologySort(), result);
}

TEST(TopologySort, AmbitiousGraph) {
  Graph graph;
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(1, 5);
  graph.AddEdge(2, 6);
  graph.AddEdge(2, 7);
  graph.AddEdge(2, 8);
  graph.AddEdge(3, 9);
  graph.AddEdge(3, 10);
  graph.AddEdge(3, 11);
  graph.AddEdge(3, 12);
  graph.AddEdge(4, 13);
  graph.AddEdge(4, 14);
  graph.AddEdge(4, 15);
  graph.AddEdge(4, 16);
  graph.AddEdge(5, 17);
  graph.AddEdge(5, 18);
  graph.AddEdge(5, 19);
  graph.AddEdge(5, 20);
  graph.AddEdge(6, 21);
  graph.AddEdge(6, 22);
  graph.AddEdge(6, 23);
  graph.AddEdge(7, 24);
  graph.AddEdge(7, 25);
  graph.AddEdge(8, 26);
  graph.AddEdge(8, 27);
  graph.AddEdge(8, 28);
  graph.AddEdge(8, 29);
  graph.AddEdge(9, 30);
  graph.AddEdge(9, 31);
  graph.AddEdge(9, 32);
  graph.AddEdge(10, 33);
  graph.AddEdge(10, 34);
  graph.AddEdge(10, 35);
  graph.AddEdge(10, 36);
  graph.AddEdge(11, 37);
  graph.AddEdge(11, 38);
  graph.AddEdge(11, 39);
  graph.AddEdge(11, 40);
  graph.AddEdge(12, 41);
  graph.AddEdge(12, 42);
  graph.AddEdge(12, 43);
  graph.AddEdge(12, 44);
  graph.AddEdge(13, 45);
  graph.AddEdge(13, 46);
  graph.AddEdge(13, 47);
  graph.AddEdge(13, 48);
  graph.AddEdge(14, 49);
  graph.AddEdge(14, 50);
  graph.AddEdge(14, 51);
  graph.AddEdge(15, 52);
  graph.AddEdge(15, 53);
  graph.AddEdge(15, 54);
  graph.AddEdge(15, 55);
  graph.AddEdge(16, 56);
  graph.AddEdge(16, 57);
  graph.AddEdge(16, 58);
  graph.AddEdge(17, 59);
  graph.AddEdge(17, 60);
  graph.AddEdge(17, 61);
  graph.AddEdge(17, 62);
  graph.AddEdge(17, 63);
  graph.AddEdge(18, 64);
  graph.AddEdge(18, 65);
  graph.AddEdge(18, 66);
  graph.AddEdge(19, 67);
  graph.AddEdge(19, 68);
  graph.AddEdge(19, 69);
  graph.AddEdge(20, 70);
  graph.AddEdge(20, 71);
  graph.AddEdge(20, 72);
  graph.AddEdge(20, 73);
  graph.AddEdge(21, 74);
  graph.AddEdge(21, 75);
  graph.AddEdge(21, 76);
  graph.AddEdge(21, 77);
  graph.AddEdge(22, 78);
  graph.AddEdge(22, 79);
  graph.AddEdge(22, 80);
  graph.AddEdge(22, 81);
  graph.AddEdge(22, 82);
  std::vector<int> result{
      1,  5,  20, 73, 72, 71, 70, 19, 69, 68, 67, 18, 66, 65, 64, 17, 63,
      62, 61, 60, 59, 4,  16, 58, 57, 56, 15, 55, 54, 53, 52, 14, 51, 50,
      49, 13, 48, 47, 46, 45, 3,  12, 44, 43, 42, 41, 11, 40, 39, 38, 37,
      10, 36, 35, 34, 33, 9,  32, 31, 30, 2,  8,  29, 28, 27, 26, 7,  25,
      24, 6,  23, 22, 82, 81, 80, 79, 78, 21, 77, 76, 75, 74};
  ASSERT_EQ(graph.TopologySort(), result);
}