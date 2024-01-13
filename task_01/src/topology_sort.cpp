#include "topology_sort.hpp"
#include <algorithm>

void dfs (int v, std::vector<bool> &used, std::vector<int> &result, std::vector< std::vector<int> > &graph) {
    used[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if(!used[to]) 
            dfs(to, used, result, graph);
    }
    
    result.push_back(v);
}

std::vector<int> top_sort (std::vector< std::vector<int> > &graph) {
    std::vector<bool> used;
	used.resize(graph.size());
	
	std::vector<int> result;
	for (int i = 0; i < graph.size(); ++i) {
		if (!used[i])
			dfs(i, used, result, graph);
	}
	
	reverse(result.begin(), result.end());

    return result;
}