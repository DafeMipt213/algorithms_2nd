#pragma once

#include <iostream>
#include <vector>

struct Edge {
    int src, dest, weight;
};

void addEdge(std::vector<Edge>& edges, int src, int dest, int weight);

std::vector<std::vector<int> > johnson(std::vector<Edge>& edges, int V);

void test_johnson();

int main();