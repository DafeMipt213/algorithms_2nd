#include <iostream>
#include <limits.h>
#include <vector>

int Vertex_With_Shortest_Distance(std::vector<long long> &dist, std::vector<bool> &visited);
std::vector<long long> Dijkstra(std::vector<std::vector<int>> &graph, int src);