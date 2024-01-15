#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::unordered_set<int>> convert_vec_vec_to_vec_set(
    const std::vector<std::vector<int>>& graph) {
  std::vector<std::unordered_set<int>> graph_new(graph.size());
  for (int iv = 0; iv < graph.size(); ++iv)
    for (int iu = 0; iu < graph[iv].size(); ++iu)
      graph_new[iv].insert(graph[iv][iu]);

  return graph_new;
}

std::vector<std::vector<int>> convert_vec_vec_to_matrix(
    const std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<int>> graph_new(graph.size());

  int k = 0;
  for (int iv = 0; iv < graph.size(); ++iv) {
    k = 0;
    for (int iu = 0; iu < graph.size(); ++iu) {
      if ((k < graph[iv].size()) && (graph[iv][k]) == iu) {
        graph_new[iv].push_back(1);
        ++k;
      } else
        graph_new[iv].push_back(0);
    }
  }

  return graph_new;
}

std::vector<std::pair<int, int>> convert_vec_vec_to_vec_pair(
    const std::vector<std::vector<int>>& graph) {
  std::vector<std::pair<int, int>> graph_new;
  for (int iv = 0; iv < graph.size(); ++iv)
    for (auto const& iu : graph[iv])
      graph_new.push_back(std::make_pair(iv, iu));

  return graph_new;
}

std::vector<std::vector<int>> convert_vec_set_to_vec_vec(
    const std::vector<std::unordered_set<int>>& graph) {
  std::vector<std::vector<int>> graph_new(graph.size());
  for (int iv = 0; iv < graph.size(); ++iv)
    for (auto const& iu : graph[iv]) graph_new[iv].push_back(iu);

  return graph_new;
}

std::vector<std::vector<int>> convert_matrix_to_vec_vec(
    const std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<int>> graph_new(graph.size());
  int k = 0;
  for (int iv = 0; iv < graph.size(); ++iv) {
    k = 0;
    for (int iu = 0; iu < graph[iv].size(); ++iu) {
      if (graph[iv][iu] == 1) graph_new[iv].push_back(k);
      ++k;
    }
  }
  return graph_new;
}

std::vector<std::vector<int>> convert_vec_pair_to_vec_vec(
    const std::vector<std::pair<int, int>>& graph) {
  std::vector<std::vector<int>> graph_new(graph.size());
  for (int iv = 0; iv < graph.size(); ++iv)
    graph_new[graph[iv].first].push_back(graph[iv].second);

  return graph_new;
}

std::vector<std::vector<int>> convert_vec_set_to_matrix(
    const std::vector<std::unordered_set<int>>& graph) {
  std::vector<std::vector<int>> graph_new;
  graph_new = convert_vec_set_to_vec_vec(graph);
  graph_new = convert_vec_vec_to_matrix(graph_new);
  return graph_new;
}

std::vector<std::unordered_set<int>> convert_matrix_to_vec_set(
    const std::vector<std::vector<int>>& graph) {
  std::vector<std::unordered_set<int>> graph_new;
  std::vector<std::vector<int>> graph_midway;
  graph_midway = convert_matrix_to_vec_vec(graph);
  graph_new = convert_vec_vec_to_vec_set(graph_midway);
  return graph_new;
}

std::vector<std::vector<int>> convert_vec_pair_to_matrix(
    const std::vector<std::pair<int, int>>& graph) {
  std::vector<std::vector<int>> graph_new;
  std::vector<std::vector<int>> graph_midway;
  graph_midway = convert_vec_pair_to_vec_vec(graph);
  graph_new = convert_vec_vec_to_matrix(graph_midway);
  return graph_new;
}

std::vector<std::pair<int, int>> convert_matrix_to_vec_pair(
    const std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<int>> graph_midway;
  std::vector<std::pair<int, int>> graph_new;
  graph_midway = convert_matrix_to_vec_vec(graph);
  graph_new = convert_vec_vec_to_vec_pair(graph_midway);
  return graph_new;
}

std::vector<std::unordered_set<int>> convert_vec_pair_to_vec_set(
    const std::vector<std::pair<int, int>>& graph) {
  std::vector<std::unordered_set<int>> graph_new;
  std::vector<std::vector<int>> graph_midway;
  graph_midway = convert_vec_pair_to_vec_vec(graph);
  graph_new = convert_vec_vec_to_vec_set(graph_midway);
  return graph_new;
}

std::vector<std::pair<int, int>> convert_vec_set_to_vec_pair(
    const std::vector<std::unordered_set<int>>& graph) {
  std::vector<std::vector<int>> graph_midway;
  std::vector<std::pair<int, int>> graph_new;
  graph_midway = convert_vec_set_to_vec_vec(graph);
  graph_new = convert_vec_vec_to_vec_pair(graph_midway);
  return graph_new;
}