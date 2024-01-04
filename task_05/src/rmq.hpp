#pragma once
#include <limits>
#include <vector>
#include <cmath>

const auto INF = std::numeric_limits<int>::max();

class RMQ
{
public:
    void build_tree(const std::vector<int>& v);
    int fill_tree(int index);
    int find_ans(int l, int r);
private:
    std::vector<int> tree;
};