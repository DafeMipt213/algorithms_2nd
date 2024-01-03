#pragma once

#include <iostream>
#include <vector>
#include <stack>

//#include <bits/stdc++.h>

enum colors {kWhite = 0, kGray = 1, kBlack = 2};

class Graph {
    int count_of_verticles;
    std::vector<bool> verticles;
    std::vector<std::vector<int>> adjacency_matrix;

    void DFS(int v, std::vector<colors> &visited, std::stack<int> &stack);

public:
    bool hasCycle = false; 
    Graph(int count_of_verticles);
    std::vector<int> TopologicalSort();
    void AddEdge(int first_verticle, int second_verticle);
    void FillGraph(std::vector<std::vector<int>> vector);
    void addVerticle(int verticle);
};


