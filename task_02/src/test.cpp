#include <gtest/gtest.h>
#include "special_points.hpp"

TEST(CutPointsAndBridges, BasicCutPoints) {
    Graph g(5, {{0, {2}}, {1, {2}}, {2, {0, 1, 3, 4}}, {3, {2}}, {4, {2}}});
    g.FindCutPoints();
    set_t cutpoints_ans;
    cutpoints_ans.insert(2);
    ASSERT_EQ(g.RetCut(), cutpoints_ans);
}

TEST(CutPointsAndBridges, SimpleCutPoints) {
    Graph g(8, {{0, {1, 2}}, {1, {3, 5}}, {2, {0, 4, 5}}, {3, {1}}, {4, {2, 5}}, {5, {1, 2, 4, 6}}, {6, {5, 7}}, {7, {6}}});
    g.FindCutPoints();
    std::set<size_t> cutpoints_ans;
    cutpoints_ans.insert(1);
    cutpoints_ans.insert(5);
    cutpoints_ans.insert(6);
    ASSERT_EQ(g.RetCut(), cutpoints_ans);
}

TEST(CutPointsAndBridges, SimpleBridges) {
    Graph g(8, {{0, {1, 2}}, {1, {3, 5}}, {2, {0, 4, 5}}, {3, {1}}, {4, {2, 5}}, {5, {1, 2, 4, 6}}, {6, {5, 7}}, {7, {6}}});
    g.FindBridges();
    std::set<std::pair<size_t, size_t>> bridges_ans;
    bridges_ans.insert(std::pair(3, 1));
    bridges_ans.insert(std::pair(6, 5));
    bridges_ans.insert(std::pair(7, 6));
    ASSERT_EQ(g.RetBridges(), bridges_ans);
}

TEST(CutPointsAndBridges, LoopCutpoints) {
    Graph g(8, {{0, {1, 2, 0}}, {1, {3, 5, 1}}, {2, {0, 4, 5, 2}}, {3, {1, 3}}, {4, {2, 5}}, {5, {1, 2, 4, 6}}, {6, {5, 7}}, {7, {6}}});
    g.FindCutPoints();
    std::set<size_t> cutpoints_ans;
    cutpoints_ans.insert(1);
    cutpoints_ans.insert(5);
    cutpoints_ans.insert(6);
    ASSERT_EQ(g.RetCut(), cutpoints_ans);
}

TEST(CutPointsAndBridges, LoopBridges) {
    Graph g(8, {{0, {1, 2, 0}}, {1, {3, 5, 1}}, {2, {0, 4, 5, 2}}, {3, {1, 3}}, {4, {2, 5}}, {5, {1, 2, 4, 6}}, {6, {5, 7}}, {7, {6}}});
    g.FindBridges();
    std::set<std::pair<size_t, size_t>> bridges_ans;
    bridges_ans.insert(std::pair(3, 1));
    bridges_ans.insert(std::pair(6, 5));
    bridges_ans.insert(std::pair(7, 6));
    ASSERT_EQ(g.RetBridges(), bridges_ans);
}

TEST(CutPointsAndBridges, EmptyBridges) {
    Graph g(0);
    g.FindBridges();
    std::set<std::pair<size_t, size_t>> bridges_ans;
    ASSERT_EQ(g.RetBridges(), bridges_ans);
}

TEST(CutPointsAndBridges, EmptyCutpoints) {
    Graph g(0);
    g.FindCutPoints();
    std::set<size_t> cutpoints_ans;
    ASSERT_EQ(g.RetCut(), cutpoints_ans);
}