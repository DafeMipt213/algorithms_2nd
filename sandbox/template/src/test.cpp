
#include <gtest/gtest.h>

#include <stack>
#include <vector>

#include "utils.hpp"

TEST(Template, Simple) { 
    std::vector<std::vector<bool>> paths = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}
    };

    Graph g;
    g.TestInitialize(paths);
    g.FindPaths();

    std::vector<std::vector<bool>> correct = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    ASSERT_EQ(correct, g.GetPortals());
}
