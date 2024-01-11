#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <queue>

class Graph {

public:
    int numVertices;
    std::vector<std::pair<int, int>> *edges;

    Graph(int vertices) {
        numVertices = vertices;
        edges = new std::vector<std::pair<int, int>>[numVertices + 1];
    }

    void addDirectedEdge(int from, int to, int weight) {
        edges[from].push_back({to, weight});
    }
};

void JohnsonAlgorithm(int, std::vector<std::pair<int, int>>[]);
std::vector<int> BellmanFordAlgorithm(int, std::vector<std::pair<int, int>>[]);
std::vector<std::vector<int>> DijkstraAlgorithm(int, std::vector<std::pair<int, int>>[]);

void JohnsonAlgorithm(int numVertices, std::vector<std::pair<int, int>> edges[]) {
    for (int i = 0; i < numVertices; i++) {
        edges[numVertices].push_back({i, 0});
    }

    std::vector<int> h = BellmanFordAlgorithm(numVertices, edges);
    auto it = h.end() - 1;
    h.erase(it);
    edges[numVertices].clear();

    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < edges[u].size(); v++) {
            edges[u][v].second = edges[u][v].second + h[u] - h[edges[u][v].first];
        }
    }

    std::vector<std::vector<int>> shortestPaths = DijkstraAlgorithm(numVertices, edges);

    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            shortestPaths[u][v] = shortestPaths[u][v] + h[v] - h[u];
        }
    }

    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            std::cout << shortestPaths[u][v] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<int> BellmanFordAlgorithm(int numVertices, std::vector<std::pair<int, int>> edges[]) {
    std::vector<int> distances(numVertices + 1, INT32_MAX);
    distances[numVertices] = 0;

    for (int i = 0; i < numVertices; i++) {
        for (int u = numVertices; u >= 0; u--) {
            for (auto edge : edges[u]) {
                int v = edge.first;
                int wt = edge.second;

                if (distances[u] != INT32_MAX && distances[u] + wt < distances[v])
                    distances[v] = distances[u] + wt;
            }
        }
    }

    return distances;
}

std::vector<std::vector<int>> DijkstraAlgorithm(int numVertices, std::vector<std::pair<int, int>> edges[]) {
    std::vector<std::vector<int>> distances(numVertices, std::vector<int>(numVertices, INT32_MAX));
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    for (int i = 0; i < numVertices; i++) {
        int source = i;
        distances[i][i] = 0;
        q.push({0, source});

        while (!q.empty()) {
            int node = q.top().second;
            int currDist = q.top().first;
            q.pop();
            if (distances[i][node] < currDist)
                continue;
            for (auto edge : edges[node]) {
                int vertex = edge.first;
                int weight = edge.second;
                if (weight + distances[i][node] < distances[i][vertex]) {
                    distances[i][vertex] = weight + distances[i][node];
                    q.push({distances[i][vertex], vertex});
                }
            }
        }
    }
    return distances;
}

int main() {
    Graph g(5);
    g.addDirectedEdge(0, 1, 2);
    g.addDirectedEdge(1, 2, -1);
    g.addDirectedEdge(1, 3, 2);
    g.addDirectedEdge(3, 0, -2);
    g.addDirectedEdge(4, 2, 1);
    g.addDirectedEdge(4, 3, -2);
    g.addDirectedEdge(2, 3, 3);

    JohnsonAlgorithm(g.numVertices, g.edges);
    return 0;
}