#include "rmq.hpp"
#include <algorithm>
#include <cmath>

int RMQ::fill_tree(int index)
{
    if (index >= tree.size())
        return INF;

    if (tree[index] < INF)
        return tree[index];

    tree[index] = std::min(fill_tree(2 * index + 1), fill_tree(2 * index + 2));
    return tree[index];
}

void RMQ::build_tree(const std::vector<int> &v)
{
    int n = std::pow(2, std::ceil(std::log2(v.size())) + 1) - 1;
    tree.resize(n, INF);
    std::copy(v.begin(), v.end(), tree.end() - (n + 1) / 2);
    fill_tree(0);
}

int RMQ::find_ans(int l, int r)
{
    int ans = INF;
    int n = tree.size() / 2;
    l += n;
    r += n;
    
    while (l <= r)
    {
        if (!(l & 1))
            ans = std::min(ans, tree[l]);

        if (r & 1)
            ans = std::min(ans, tree[r]);

        if (r & 1 && !(l & 1) && (l + 1) / 2 == (r - 1) / 2)
            break;

        l = (l - 1) / 2;
        r = (r - 2) / 2;
    }

    return ans;
}