#include <gtest/gtest.h>
#include "special_points.hpp"

TEST(CutPointsAndBridges, SimpleCutPoints) {
    Graph g(5, {{0, {2}}, {1, {2}}, {2, {0, 1, 3, 4}}, {3, {2}}, {4, {2}}});
    g.FindCutPoints();
    vector_t cutpoints_ans;
    cutpoints_ans.push_back(3);
    ASSERT_EQ(g.RetCut(), cutpoints_ans);
}