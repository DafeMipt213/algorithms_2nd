#include <algorithm>
#include <stdexcept>

#include "graph.hpp"

bool Graph::Find(int elem) {
  if (graph_.count(elem) != 0)
    return true;
  return false;
}

void Graph::Add(int elem, int parent, int weight) {
  if (weight < 0)
    throw std::runtime_error("Graph::Add - negative weight");
  if (graph_.count(elem) == 0)
    graph_[elem] = {};
  if (graph_.count(parent) == 0)
    graph_[parent] = {{elem, weight}};
  else
    graph_[parent].push_back({elem, weight});
  marks_[elem] = Color::White;
}

void Graph::DFS(int u, std::function<void(int)> action, bool is_clean_marks) {
  if (marks_[u] == Color::Black)
    return;
  if (marks_[u] == Color::Grey) {
    is_cycle_ = true;
    return;
  }
  marks_[u] = Color::Grey;
  for (auto v : graph_[u]) {
    DFS(u, action, false);
  }
  marks_[u] = Color::Black;
  action(u);
  if (is_clean_marks) {
    for (auto it = marks_.begin(); it != marks_.end(); ++it)
      it->second = Color::White;
  }
}

std::map<int, int> Graph::Dijkstra(int s) {
  if (graph_.count(s) == 0)
    throw std::runtime_error(
        "Graph::Dijkstra - there's no such an element in the graph");
  std::map<int, int> dist;
  for (auto it = graph_.begin(); it != graph_.end(); ++it)
    dist[it->first] = inf;
  dist[s] = 0;
  for (auto it = graph_.begin(); it != graph_.end(); ++it) {
    if (marks_[it->first] == Color::White) {
      auto min = (*min_element(dist.begin(), dist.end(),
                               [](const auto &l, const auto &r) {
                                 return l.second < r.second;
                               }))
                     .first;
      marks_[min] = Color::Black;
      for (auto u : graph_[min])
        dist[u.first] = std::min(dist[u.first], dist[min] + u.second);
    }
  }
  for (auto it = marks_.begin(); it != marks_.end(); ++it)
    it->second = Color::White;
  return dist;
}

bool Graph::FordBellman(int s, std::map<int, int> &d) {
  if (graph_.count(s) == 0)
    throw std::runtime_error(
        "Graph::FordBellman - there's no such an element in the graph");
  d = {};
  for (auto it = graph_.begin(); it != graph_.end(); ++it)
    d[it->first] = inf;
  d[s] = 0;
  for (size_t i = 0; i != Size(); ++i) {
    for (auto it = graph_.begin(); it != graph_.end(); ++it)
      for (auto v : it->second) {
        if (d[v.first] > d[it->first] + v.second) {
          d[v.first] = d[it->first] + v.second;
        }
      }
  }
  for (auto it = graph_.begin(); it != graph_.end(); ++it)
    for (auto v : it->second) {
      if (d[v.first] > d[it->first] + v.second) {
        return false;
      }
    }
  return true;
}

std::map<int, std::vector<std::pair<int, int>>> Graph::Johnson() {
  int s = -inf;
  graph_[s] = {};
  for (auto it = graph_.begin(); it != graph_.end(); ++it)
    if (it->first != 0)
      graph_[s].push_back({it->first, 0});
  std::map<int, int> d{};
  if (FordBellman(s, d) == false)
    throw std::runtime_error("Graph::Jonson - negative cycle in the graph");

  for (auto it = graph_.begin(); it != graph_.end(); ++it) {
    for (auto v : it->second)
      v.second = v.second + d[it->first] - v.first;
  }

  graph_.erase(s);
  std::map<int, std::vector<std::pair<int, int>>> res;

  for (auto it = graph_.begin(); it != graph_.end(); ++it) {
    auto b = Dijkstra(it->first);
    for (auto k = graph_.begin(); k != graph_.end(); ++k) {
      if (res.count(it->first) == 0)
        res[it->first] = {{k->first, b[k->first] + d[k->first] - d[it->first]}};
      else
        res[it->first].push_back(
            {k->first, b[k->first] + d[k->first] - d[it->first]});
    }
  }

  for (auto it = graph_.begin(); it != graph_.end(); ++it) {
    for (auto v : it->second)
      v.second = v.second + d[it->first] - v.first;
  }
  return res;
}

void Graph::DFSForBridgesAndCutPoints(std::vector<std::pair<int, int>> &bridges,
                                      std::vector<int> &cut_pnts, int v,
                                      int p) {
  tin_[v] = timer_++;
  ret_[v] = tin_[v];
  marks_[v] = Color::Black;
  int children = 0;
  for (auto to : graph_[v]) {
    if (to.first == p)
      continue;
    if (marks_[to.first] == Color::Black)
      ret_[v] = std::min(ret_[v], tin_[to.first]);
    else {
      DFSForBridgesAndCutPoints(bridges, cut_pnts, to.first, v);
      ret_[v] = std::min(ret_[v], ret_[to.first]);
      if (ret_[to.first] > tin_[v])
        bridges.push_back({v, to.first});
      if (ret_[to.first] >= tin_[v] && p != -1)
        cut_pnts.push_back(v);
      ++children;
    }
  }
  if (p == -inf && children > 1)
    cut_pnts.push_back(v);
  if (p == -inf) {
    timer_ = 0;
    ret_ = {};
    tin_ = {};
  }
}

void Graph::FindBridgesAndCutPoins(std::vector<std::pair<int, int>> &bridges,
                                   std::vector<int> &cut_pnts) {
  for (auto it = graph_.begin(); it != graph_.end(); ++it) {
    if (marks_[it->first] == Color::White)
      DFSForBridgesAndCutPoints(bridges, cut_pnts, it->first);
  }
  for (auto it = marks_.begin(); it != marks_.end(); ++it)
    it->second = Color::White;
}

bool Graph::IsCycle() {
  if (graph_.empty())
    return false;
  DFS(graph_.begin()->first, [](int) {});
  return is_cycle_;
}
