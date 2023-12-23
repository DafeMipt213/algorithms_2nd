#include "Dijkstra.hpp"
#include <iostream>

int main(){
    std::vector<std::vector<Vertex>> graph = {{{1, 1}, {4, 500}}, {{2, 2}, {4, 5}}, {{3, 1}}, {{4, 1}}, {}};
    std::cout << Dijkstra(graph, 0, 4);
}