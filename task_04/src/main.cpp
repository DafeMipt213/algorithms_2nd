#include <iostream>
#include <vector>
#include "Deijkstra.hpp"

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    
    vector< vector< pair<int, int> > > graph;
    graph.resize(n);
    
    int from, to, weight;
    
    for(int i = 0; i < m; ++i) {
        cin >> from >> to >> weight;
        graph[from].push_back( {to, weight} );
    }
    
    int start, end; cin >> start >> end;
    int k = Deijkstra(start, end, graph);

    cout << k;
}