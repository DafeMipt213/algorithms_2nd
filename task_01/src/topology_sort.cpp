#include "topology_sort.hpp"

void dfs(int ver, std::stack<int>& stack_ver, const Graph& graph, std::vector<bool>& visited) {
    if (visited[ver] == true) return;
    visited[ver] = true;
    for (int i = 0; i < graph[ver].size(); ++i)
        if (!visited[graph[ver][i]]) {
            dfs(graph[ver][i], stack_ver, graph, visited);
            visited[graph[ver][i]] = true;
        }
    stack_ver.push(ver);
}

Vertexes TopologySort(Graph graph) {
    std::stack<int> result_dfs;
    std::vector<bool> visited;
    visited = std::vector<bool> (graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        dfs(i, result_dfs, graph, visited);
    }
    Vertexes result_sort;
    while (!result_dfs.empty()) {
        result_sort.push_back(result_dfs.top());
        result_dfs.pop();
    }
    return result_sort;
}
