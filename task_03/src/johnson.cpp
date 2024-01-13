
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <stack>
#include "johnson.hpp"
#include "../../task_04/src/dijkstra.cpp"
bool FordBellman(Graph* graph, int src) {
  const int INT_MAX = 2147483647;
  std::unordered_map<size_t, int> dist; //id-вес
  int V = graph->V;
  for (int i = 0; i < V; i++)
      dist[i] = INT_MAX;
  dist[src] = 0;
  for (size_t i = 1; i <= V - 1; i++) {
      for (auto& node : graph->nodes)
          for (auto& edge : node.second.edges) {
              size_t index_from = node.first;
              size_t index_to = edge.index_to;
              int weight = edge.weight;
              if (dist[index_from] != INT_MAX && (dist[index_from] + weight < dist[index_to]) && index_from != index_to)
                  dist[index_to] = dist[index_from] + weight;
          }
  }
  for (auto& node : graph->nodes)
    for (auto& edge : node.second.edges) {
        size_t index_from = node.first;
        size_t index_to = edge.index_to;
        if (index_from != index_to) {
            int weight = edge.weight;
            edge.weight = edge.weight - dist[index_to] + dist[index_from];
            if (dist[index_from] != INT_MAX
                && dist[index_from] + weight < dist[index_to])
                return false;
        }
    }
          return true;
}

std::pair<std::vector<size_t>, int> Johnson(Graph& graph, size_t ind1, size_t ind2) {
    size_t extra_id = 1000000;
    graph.nodes[extra_id] = Node(extra_id);
    for (auto& node: graph.nodes)
        graph.addEdge(extra_id, node.first, 0);
    if (!FordBellman(&graph, extra_id)) return {{extra_id}, extra_id};
    graph.removeExtraNode(extra_id);
    Dijkstra ans = Dijkstra(graph, ind1, ind2);
    return {ans.path, ans.length};
}