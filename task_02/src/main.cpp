#include <iostream>
#include <list>
#include <vector>

class Graph {
    int V;
    std::list<int> *adj;

    void findCutVerticesUtil(int v, std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<bool>& cutVertices);
    void findBridgesUtil(int u, std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent);

public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void findCutVertices();
    void findBridges();
};

Graph::Graph(int vertices) {
    V = vertices;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::findCutVerticesUtil(int u, std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<bool>& cutVertices) {
    static int time = 0;
    int children = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            findCutVerticesUtil(v, visited, disc, low, parent, cutVertices);

            low[u] = std::min(low[u], low[v]);

            if (low[v] >= disc[u] && parent[u] != -1)
                cutVertices[u] = true;

            if (parent[u] == -1 && children > 1)
                cutVertices[u] = true;
        } else if (v != parent[u]) {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

void Graph::findBridgesUtil(int u, std::vector<bool>& visited, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent) {
    static int time = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            findBridgesUtil(v, visited, disc, low, parent);

            low[u] = std::min(low[u], low[v]);

            if (low[v] > disc[u])
                std::cout << "Bridge: " << u << " - " << v << std::endl;
        } else if (v != parent[u]) {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

void Graph::findCutVertices() {
    std::vector<bool> visited(V, false);
    std::vector<int> disc(V, -1);
    std::vector<int> low(V, -1);
    std::vector<int> parent(V, -1);
    std::vector<bool> cutVertices(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            findCutVerticesUtil(i, visited, disc, low, parent, cutVertices);
    }

    std::cout << "Cut vertices in the network are: ";
    for (int i = 0; i < V; i++) {
        if (cutVertices[i])
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

void Graph::findBridges() {
    std::vector<bool> visited(V, false);
    std::vector<int> disc(V, -1);
    std::vector<int> low(V, -1);
    std::vector<int> parent(V, -1);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            findBridgesUtil(i, visited, disc, low, parent);
    }
}

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.findCutVertices();
    g.findBridges();

    return 0;
}