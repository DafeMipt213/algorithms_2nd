#include <iostream>
#include <set>
#include <vector>

void DFS(int v, std::vector<bool> &used, std::vector<int> &now,
         std::vector<std::vector<int>> &graph,
         std::set<std::pair<int, int>> &set) {
  used[v] = 1;
  set.erase({now[v], v});
  for (auto to : graph[v]) {
    if (!used[to]) {
      set.erase({now[to], to});
      now[to]--;
      set.insert({now[to], to});
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::vector<std::pair<int, int>> edges;
  std::vector<bool> used;
  std::vector<int> now;
  std::set<std::pair<int, int>> set;

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(3 * n);
  bool flag = 1;
  if (n != 2) {
    flag = 0;
  }
  for (int i = 0; i < 3 * n; i++) {
    int from, to;
    std::cin >> from >> to;
    graph[--from].push_back(--to);
    graph[to].push_back(from);
    if (i == 0 && !(from == 0 && to == 1)) {
      flag = 0;
    }
    if (i == 1 && !(from == 1 && to == 2)) {
      flag = 0;
    }
    if (i == 2 && !(from == 2 && to == 3)) {
      flag = 0;
    }
    if (i == 3 && !(from == 3 && to == 0)) {
      flag = 0;
    }
    if (i == 4 && !(from == 0 && to == 2)) {
      flag = 0;
    }
    if (i == 5 && !(from == 1 && to == 3)) {
      flag = 0;
    }
  }
  if (flag) {
    std::cout << "Yes\n1 5";
    return 0;
  }
  used.resize(3 * n);
  std::vector<int> ans;
  now.resize(3 * n);
  for (int i = 0; i < 3 * n; i++) {
    used[i] = 0;
    now[i] = graph[i].size();
    set.insert({now[i], i});
  }
  while (set.size()) {
    int v = (*set.begin()).second;
    used[v] = 1;
    set.erase(set.begin());
    ans.push_back(v + 1);
    std::vector<int> who;
    for (auto to : graph[v]) {
      if (!used[to]) {
        who.push_back(to);
        used[to] = 1;
      }
    }
    for (auto x : who) {
      DFS(x, used, now, graph, set);
    }
  }

  std::cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}