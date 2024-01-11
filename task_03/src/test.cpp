#include <gtest/gtest.h>
#include "johnson.hpp"

TEST(JohnsonAlgorithm, SimpleGraph) {
    std::vector<std::vector<int>> G = {
        {0, 3, INF, INF},
        {INF, 0, -2, INF},
        {1, INF, 0, INF},
        {INF, INF, INF, 0}
    };

    JohnsonAlgorithm johnson(G);
    std::vector<std::vector<int>> result = johnson.run();

    int numVertices = result.size();

    // Проверка результатов
    ASSERT_EQ(result[0][1], 3);
    ASSERT_EQ(result[1][2], -2);
    ASSERT_EQ(result[2][0], 1);
    ASSERT_EQ(result[1][3], 1);

    // Проверка отсутствия пути
    ASSERT_EQ(result[0][3], INF);
}
