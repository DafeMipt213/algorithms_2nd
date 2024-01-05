#pragma once


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Class to represent the binary tree
class BinaryTree {
    int n; // Number of nodes in the tree
    vector<int> parent; // Parent array to store the parent of each node
    vector<int> depth; // Depth array to store the depth of each node
    vector<vector<int>> sparse_table; // Sparse table to store the LCA information

public:
    BinaryTree(int nodes) {
        n = nodes;
        parent.resize(n);
        depth.resize(n);
        sparse_table.resize(n, vector<int>(log2(n) + 1));

        // Initialize parent array with -1
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
        }
    }

    // Function to add an edge between two nodes
    void AddEdge(int child, int par) {
        parent[child] = par;
    }

    // Function to initialize the sparse table
    void InitSparseTable() {
        for (int i = 0; i < n; i++) {
            sparse_table[i][0] = parent[i];
        }

        for (int j = 1; (1 << j) < n; j++) {
            for (int i = 0; i < n; i++) {
                if (sparse_table[i][j - 1] != -1) {
                    sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
                }
            }
        }
    }

    // Function to find the LCA of two nodes using the sparse table
    int findLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int maxDepth = log2(depth[u]) + 1;

        for (int i = maxDepth - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = sparse_table[u][i];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = maxDepth - 1; i >= 0; i--) {
            if (sparse_table[u][i] != -1 && sparse_table[u][i] != sparse_table[v][i]) {
                u = sparse_table[u][i];
                v = sparse_table[v][i];
            }
        }

        return parent[u];
    }

    // Function to calculate the depth of each node
    void CalculateDepths(int node, int d) {
        depth[node] = d;
        for (int child = 0; child < n; child++)
            if (parent[child] == node)
                CalculateDepths(child, d + 1);
    }
};
