#include "search.hpp"

void FindBridge(int v, int parent, std::size_t& timer,
                std::vector<bool>& visited, std::vector<std::size_t>& t_in,
                std::vector<std::size_t>& t_up, const Graph& graph,
                std::vector<Edge>& bridges) {
  visited[v] = true;
  t_in[v] = timer;
  t_up[v] = timer;
  timer += 1;
  for (std::size_t i = 0; i < graph.at(v).size(); ++i) {
    int destination = graph.at(v).at(i);
    if (destination == parent) continue;
    if (visited.at(destination))
      t_up[v] = ((t_up.at(v) > t_in.at(destination)) ? t_in.at(destination)
                                                     : t_up.at(v));
    else {
      FindBridge(destination, v, timer, visited, t_in, t_up, graph, bridges);
      t_up[v] = ((t_up.at(v) > t_up.at(destination)) ? t_up.at(destination)
                                                     : t_up.at(v));
      if (t_up.at(destination) > t_in.at(v))
        bridges.push_back(Edge(v, destination));
    }
  }
}

Graph Prepare(const Graph& graph) {
  Graph new_graph(graph.size());
  for (std::size_t i = 0; i < graph.size(); ++i)
    for (std::size_t j = 0; j < graph.at(i).size(); ++j) {
      new_graph[i].push_back(graph.at(i).at(j));
      new_graph[graph.at(i).at(j)].push_back(i);
    }
  return new_graph;
}

std::vector<Edge> BridgesSearch(const Graph& graph) {
  auto new_graph = Prepare(graph);
  std::vector<bool> visited(new_graph.size(), false);
  std::vector<std::size_t> t_in(new_graph.size());
  std::vector<std::size_t> t_up(new_graph.size());
  std::size_t timer = 0;
  std::vector<Edge> bridges;
  for (std::size_t i = 0; i < new_graph.size(); ++i)
    if (!visited.at(i))
      FindBridge(i, -1, timer, visited, t_in, t_up, new_graph, bridges);
  return bridges;
}
