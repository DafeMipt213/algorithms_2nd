#include <iostream>
#include <vector>
#include <array>
#include <cassert>

const int MAX_NODES = 100000;

std::vector<int> edges[MAX_NODES];
std::array<std::array<int, 20>, MAX_NODES> ancestor;
int nodeDepth[MAX_NODES];

void explore(int currentNode, int parent) {
    ancestor[currentNode][0] = parent;
    nodeDepth[currentNode] = nodeDepth[parent] + 1;

    for (int i = 1; i < 20; ++i) {
        if (ancestor[currentNode][i - 1] != -1) {
            ancestor[currentNode][i] = ancestor[ancestor[currentNode][i - 1]][i - 1];
        }
        else {
            ancestor[currentNode][i] = -1;
        }
    }

    for (int child : edges[currentNode]) {
        if (child != parent) {
            explore(child, currentNode);
        }
    }
}

int findLowestCommonAncestor(int u, int v) {
    if (u == v) return u;

    if (nodeDepth[u] < nodeDepth[v]) std::swap(u, v);

    for (int i = 20 - 1; i >= 0; --i) {
        if (nodeDepth[u] - (1 << i) >= nodeDepth[v]) {
            u = ancestor[u][i];
        }
    }

    if (u == v) return u;

    for (int i = 20 - 1; i >= 0; --i) {
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }

    return ancestor[u][0];
}

int main() {
    int numNodes = 9;
    edges[1].push_back(2);
    edges[1].push_back(3);
    edges[2].push_back(4);
    edges[2].push_back(5);
    edges[3].push_back(6);
    edges[3].push_back(7);
    edges[5].push_back(8);
    edges[5].push_back(9);

    for (int i = 1; i <= numNodes; ++i) {
        for (int j = 0; j < 20; ++j) {
            ancestor[i][j] = -1;
        }
    }

    explore(1, 0);

    assert(findLowestCommonAncestor(4, 8) == 2);
    assert(findLowestCommonAncestor(2, 1) == 1);

    return 0;
}
