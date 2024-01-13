#include "dijkstra.hpp"

#include <map>
#include <stack>

std::vector<size_t> makeAnswer(Graph& graph, size_t start, size_t finish) {
  std::vector<size_t> answer;
  std::stack<size_t> tmp_path;
  int current_node = finish;
  while (current_node != -1) {
    tmp_path.push(current_node);
    current_node = graph.nodes[current_node].prevIndex;

  }

  while (!tmp_path.empty()) {
    answer.push_back(tmp_path.top());
    tmp_path.pop();
  }
  return answer;
}

std::vector<size_t> Dijkstra::findPath(Graph& graph, size_t start, size_t finish) {
  graph.init();
  std::multimap<size_t, size_t> min_weight_map;
  graph.nodes[start].weight = 0;
  min_weight_map.insert({0, start});
  while (!min_weight_map.empty()) {
    auto current_node = *min_weight_map.begin();
    size_t current_weight = current_node.first;
    size_t current_index = current_node.second;
    min_weight_map.erase(min_weight_map.begin());
    if (graph.nodes[current_index].visited) continue;
    graph.nodes[current_index].visited = true;
    for (int i = 0; i < graph.nodes[current_index].edges.size(); ++i) {
      size_t index_to = graph.nodes[current_index].edges[i].index_to;
      size_t edge_weight = graph.nodes[current_index].edges[i].weight;
      if (!graph.nodes[index_to].visited)
        if (current_weight + edge_weight < graph.nodes[index_to].weight) {
          graph.nodes[index_to].weight = current_weight + edge_weight;
          graph.nodes[index_to].prevIndex = current_index;
          min_weight_map.insert({graph.nodes[index_to].weight, index_to});
        }
    }
  }
  length = graph.nodes[finish].weight;
  return makeAnswer(graph, start, finish);
}
