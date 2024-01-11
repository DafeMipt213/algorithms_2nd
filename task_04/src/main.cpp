#include <dijkstra.hpp>
#include <iostream>

int main() {
    int vertices, edges;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> vertices >> edges;

    Graph graph(vertices);

    std::cout << "Enter the edges and weights:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    int source;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    graph.dijkstra(source);

    return 0;
}

