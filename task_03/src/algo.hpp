#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

#define INF std::numeric_limits<int>::max()

// Structure to represent a weighted edge
struct Edge {
    int source;
    int destination;
    int weight;
};

// Graph class
class Graph {
private:
    int vertex_count;  // Number of vertices
    std::vector<Edge> edges;  // Vector to store graph edges
    
public:
    Graph(int V) : vertex_count(V) {}

    // Add an edge to the graph
    void AddEdge(int source, int destination, int weight) {
        edges.push_back({source, destination, weight});
    }

    std::vector<int> BellmanFord(int source);
    std::vector<int> Dijkstra(int source);
    std::vector<std::vector<int>> JohnsonsAlgorithm();
};
