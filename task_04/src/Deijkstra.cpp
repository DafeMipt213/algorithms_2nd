#include "Deijkstra.hpp"
#include <vector>

const int INF = 1e9;

int Deijkstra(int start, int end, std::vector< std::vector< std::pair<int, int> > > &graph) {

    if (end >= graph.size() or start < 0) { throw "Bad Input"; }

    if (graph.size() == 0) throw "Empty Graph";

    std::vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    std::vector<bool> used(graph.size());
    
    for(int i = 0; i < graph.size(); ++i) {
        int closest = -1;
        for(int j = 0; j < graph.size(); ++j) {
            if (!used[j] && (closest == -1 || dist[closest] > dist[j])) {
                closest = j;
            }
        }
        
        used[closest] = true;
        
        for(auto &[to, weight] : graph[closest]) {
            if (weight < 0) throw "Negative Weight!";
            if (dist[to] > dist[closest] + weight) {
                dist[to] = dist[closest] + weight;
            }
        }
    }
    if (dist[end] == INF) throw "No path to this verticle!";
    return dist[end];
}