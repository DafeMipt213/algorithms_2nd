
#include <gtest/gtest.h>

#include <graph.hpp>
#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  Graph test1({{1, 2}, {3, 4}, {}, {2, 4}, {}});
  ASSERT_EQ((TopologySort(test1, 0)), (std::vector<size_t>{0, 1, 3, 4, 2}));
  ASSERT_EQ((TopologySort(test1, 1)), (std::vector<size_t>{1, 3, 4, 2}));
}

TEST(TopologySort, Middle) {
  Graph test1({{3, 4, 2}, {3, 4}, {1}, {4, 2, 0}, {3}});
  ASSERT_EQ((TopologySort(test1, 0)), (std::vector<size_t>{0, 3, 2, 1, 4}));
  ASSERT_EQ((TopologySort(test1, 1)), (std::vector<size_t>{1, 3, 0, 2, 4}));
  ASSERT_EQ((TopologySort(test1, 2)), (std::vector<size_t>{2, 1, 3, 0, 4}));
  ASSERT_EQ((TopologySort(test1, 3)), (std::vector<size_t>{3, 0, 2, 1, 4}));
}

// TEST(TopologySort, Hard) {
//   GraphWithTopologySort test1({{1, {12, 4}},
//                                {2, {12, 8, 4, 10, 3, 11, 9, 6, 1, 5}},
//                                {3, {7, 10, 12, 1, 6, 11, 4, 5}},
//                                {4, {11, 6, 1, 8, 9, 5, 3, 7, 2, 12}},
//                                {5, {11}},
//                                {6, {5, 11, 8, 7}},
//                                {7, {3, 9, 6, 12, 1, 11}},
//                                {8, {7, 3}},
//                                {9, {2, 5, 1}},
//                                {10, {2, 7}},
//                                {11, {3, 8, 6}},
//                                {12, {5, 11, 4, 3, 1}}});
//   ASSERT_EQ((test1.TopologySort(1)),
//             (std::vector<size_t>{1, 12, 5, 11, 3, 7, 9, 2, 10, 4, 6, 8}));
//   ASSERT_EQ((test1.TopologySort(12)),
//             (std::vector<size_t>{12, 5, 11, 3, 7, 9, 2, 10, 4, 1, 6, 8}));
//   ASSERT_EQ((test1.TopologySort(6)),
//             (std::vector<size_t>{6, 5, 11, 3, 7, 9, 2, 10, 12, 4, 8, 1}));
//   ASSERT_EQ((test1.TopologySort(5)),
//             (std::vector<size_t>{5, 11, 3, 7, 9, 2, 10, 12, 4, 1, 6, 8}));
// }
