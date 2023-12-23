#include <vector>
#include <stdexcept>

const int INF = 1000000;

bool fordBellman(int s, std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<int>& d);

std::vector<std::vector<int>> jonson(std::vector<std::vector<std::pair<int, int>>>& graph);

void dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph, int s, std::vector<int>& d);
