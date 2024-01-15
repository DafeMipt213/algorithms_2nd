#include <cstdio>
#include <iostream>
#include <vector>

void DFSConnectivity(int v, std::vector<std::vector<int>> &graph,
                     std::vector<bool> &used) {
  used[v] = 1;
  for (std::vector<int>::iterator i = graph[v].begin(); i < graph[v].end();
       ++i) {
    if (!used[*i]) DFSConnectivity(*i, graph, used);
  }
}

int DFSCenter(int v, std::vector<std::vector<int>> &graph,
              std::vector<bool> &used, int &cur_o, int cnt = 0) {
  used[v] = 1;
  if (v != cur_o && graph[v].size() == 4) cnt++;
  if (graph[v].size() == 1) return cnt == 1;
  if (v == cur_o) {
    for (std::vector<int>::iterator i = graph[v].begin(); i < graph[v].end();
         ++i) {
      if (used[*i]) return 0;
      if (!DFSCenter(*i, graph, used, cur_o, cnt)) return 0;
    }
    return 1;
  } else if (graph[v].size() == 4) {
    for (std::vector<int>::iterator i = graph[v].begin(); i < graph[v].end();
         ++i) {
      if (!used[*i] && graph[*i].size() != 4) {
        return DFSCenter(*i, graph, used, cur_o, cnt);
      }
    }
  } else {
    for (std::vector<int>::iterator i = graph[v].begin(); i < graph[v].end();
         ++i) {
      if (!used[*i]) {
        return DFSCenter(*i, graph, used, cur_o, cnt);
      }
    }
  }
  return 0;
}

int DFS4(int v, std::vector<std::vector<int>> &graph, std::vector<bool> &used) {
  used[v] = 1;
  int cnt = 1;
  for (std::vector<int>::iterator i = graph[v].begin(); i < graph[v].end();
       ++i) {
    if (!used[*i] && graph[*i].size() == 4) {
      cnt += DFS4(*i, graph, used);
    }
  }
  return cnt;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m;
  std::cin >> n >> m;
  if (n < 7) {
    std::cout << "NO\n";
    return 0;
  }

  std::vector<std::vector<int>> graph(n);
  std::vector<int> ringroad;
  std::vector<bool> used;

  ringroad.reserve(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int cur_o = -1;
  for (int i = 0; i < n; ++i) {
    if (graph[i].size() == 4) {
      ringroad.push_back(i);
    } else if (graph[i].size() != 1 && graph[i].size() != 2) {
      if (cur_o == -1) {
        cur_o = i;
      } else {
        std::cout << "NO\n";
        return 0;
      }
    }
  }

  used.resize(n);
  DFSConnectivity(0, graph, used);
  for (std::vector<bool>::iterator i = used.begin(); i < used.end(); ++i) {
    if (*i == false) {
      std::cout << "NO\n";
      return 0;
    }
  }

  if (ringroad.size() < 3) {
    std::cout << "NO\n";
    return 0;
  }

  if (cur_o != -1) {
    used.clear();
    used.resize(n);
    if (DFSCenter(cur_o, graph, used, cur_o)) {
      used.clear();
      used.resize(n);
      int cnt4 = DFS4(ringroad[0], graph, used);
      if (cnt4 != ringroad.size()) {
        std::cout << "NO\n";
        return 0;
      }
      std::cout << "YES\n";
      return 0;
    } else {
      std::cout << "NO\n";
      return 0;
    }
  } else {
    if (ringroad.size() != 5) {
      std::cout << "NO\n";
      return 0;
    } else {
      for (std::vector<int>::iterator i = ringroad.begin(); i < ringroad.end();
           ++i) {
        cur_o = *i;
        used.clear();
        used.resize(n);
        if (DFSCenter(cur_o, graph, used, cur_o)) {
          used.clear();
          used.resize(n);
          int cnt4 = DFS4(ringroad[0], graph, used);
          if (cnt4 != 4) {
            std::cout << "NO\n";
            return 0;
          }
          std::cout << "YES\n";
          return 0;
        }
      }
      std::cout << "NO\n";
    }
  }
  return 0;
}