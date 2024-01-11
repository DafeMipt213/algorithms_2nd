#include "search.hpp"

void FindDot(int v, int parent, std::size_t& timer, std::vector<bool>& visited,
             std::vector<std::size_t>& t_in, std::vector<std::size_t>& t_up,
             const Graph& graph, std::vector<bool>& dots) {
  visited[v] = true;
  t_in[v] = timer;
  t_up[v] = timer;
  timer += 1;
  size_t children_count = 0;
  for (std::size_t i = 0; i < graph.at(v).size(); ++i) {
    int destination = graph.at(v).at(i);
    if (destination == parent) continue;
    if (visited.at(destination))
      t_up[v] = ((t_up.at(v) > t_in.at(destination)) ? t_in.at(destination)
                                                     : t_up.at(v));
    else {
      FindDot(destination, v, timer, visited, t_in, t_up, graph, dots);
      t_up[v] = ((t_up.at(v) > t_up.at(destination)) ? t_up.at(destination)
                                                     : t_up.at(v));
      if (t_up.at(destination) >= t_in.at(v) && parent != -1) dots[v] = true;
      ++children_count;
    }
  }
  if (parent == -1 && children_count > 1) dots[v] = true;
}

std::vector<int> DotsSearch(const Graph& graph) {
  auto new_graph = Prepare(graph);
  std::vector<bool> visited(new_graph.size(), false);
  std::vector<std::size_t> t_in(new_graph.size());
  std::vector<std::size_t> t_up(new_graph.size());
  std::size_t timer = 0;
  std::vector<bool> dots(new_graph.size(), false);
  FindDot(0, -1, timer, visited, t_in, t_up, new_graph, dots);
  std::vector<int> correction_dots;
  for (std::size_t i = 0; i < dots.size(); ++i)
    if (dots.at(i)) correction_dots.push_back(i);
  return correction_dots;
}