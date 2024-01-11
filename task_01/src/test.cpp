
#include <gtest/gtest.h>
#include "topology_sort.hpp"

TEST(GraphTest, TopologicalSort) {
    // Тест 1: Граф без цикла
    Graph g1(6);
    g1.addEdge(5, 2);
    g1.addEdge(5, 0);
    g1.addEdge(4, 0);
    g1.addEdge(4, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);

    std::vector<int> result1 = g1.topologicalSort();
    ASSERT_EQ(result1.size(), 6);
    EXPECT_EQ(result1[0], 5);
    EXPECT_EQ(result1[1], 4);
    EXPECT_EQ(result1[2], 2);
    EXPECT_EQ(result1[3], 3);
    EXPECT_EQ(result1[4], 1);
    EXPECT_EQ(result1[5], 0);

    // Тест 2: Граф с циклом
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);

    std::vector<int> result2 = g2.topologicalSort();
    ASSERT_TRUE(result2.empty());  // Граф содержит цикл
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
