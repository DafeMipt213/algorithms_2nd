#include <iostream>
#include "topology_sort.hpp"

int main() { 
    Graph g(8);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(7, 0);
    g.addEdge(7, 1);
    g.addEdge(3, 1);
    g.addEdge(3, 6);
    g.addEdge(5, 7);
    g.addEdge(7, 2);
    g.addEdge(6, 0);


    g.topologicalSort();
    return 0; }
