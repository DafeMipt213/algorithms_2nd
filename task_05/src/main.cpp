#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& array);
    int query(int left, int right);

private:
    void build(int node, int start, int end);
    int queryHelper(int node, int start, int end, int left, int right);

    vector<int> arr;
    vector<int> tree;
};

SegmentTree::SegmentTree(const vector<int>& array) {
    arr = array;
    tree.resize(4 * arr.size());
    build(1, 0, arr.size() - 1);
}

void SegmentTree::build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int SegmentTree::query(int left, int right) {
    return queryHelper(1, 0, arr.size() - 1, left, right);
}

int SegmentTree::queryHelper(int node, int start, int end, int left, int right) {
    if (start > right || end < left)
        return INT_MAX;

    if (start >= left && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int leftMin = queryHelper(2 * node, start, mid, left, right);
    int rightMin = queryHelper(2 * node + 1, mid + 1, end, left, right);

    return min(leftMin, rightMin);
}

int main() {
    vector<int> array = {18, 17, 13, 19, 15, 11, 20};
    SegmentTree segmentTree(array);

    assert(segmentTree.query(3, 6) == 11);
    assert(segmentTree.query(1, 4) == 13);
    return 0;
}

