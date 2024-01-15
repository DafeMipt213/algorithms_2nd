#pragma once

#include <algorithm>
#include <vector>

struct Graph {
 public:
  void AddEdge(const size_t from, const size_t to) {
    adjacency_list_[from].push_back(to);
  }

  Graph(const size_t size)
      : adjacency_list_(size), tin_(size), ret_(size), used_(size) {}

  void Dfs(size_t v, size_t p = -1) {
    size_t children = 0;
    time_count_++;
    tin_[v] = time_count_;
    ret_[v] = tin_[v];
    used_[v] = true;
    for (auto to : adjacency_list_[v]) {
      if (to == p) continue;
      if (used_[to])
        ret_[v] = std::min(ret_[v], tin_[to]);
      else {
        Dfs(to, v);
        ret_[v] = std::min(ret_[v], ret_[to]);
        children += 1;
        if (ret_[to] == tin_[to])
          bridges_.push_back(std::pair<size_t, size_t>(v, to));
        if (ret_[to] >= tin_[v] and p != -1) articulation_points_.push_back(v);
      }
      if (p == -1 && children > 1) articulation_points_.push_back(v);
    }
  }

  std::vector<std::pair<size_t, size_t>> GetBridges() { return bridges_; }
  std::vector<size_t> GetArticulationPoints() { return articulation_points_; }

 private:
  std::vector<std::vector<size_t>> adjacency_list_;
  std::vector<size_t> tin_;
  std::vector<size_t> ret_;
  std::vector<bool> used_;
  size_t time_count_;

  std::vector<size_t> articulation_points_;
  std::vector<std::pair<size_t, size_t>> bridges_;
};