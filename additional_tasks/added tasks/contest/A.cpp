#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

bool DFS(int vert, int n, std::vector<std::unordered_set<int>> &graph,
         std::vector<bool> &used) {
  if (vert == 2 * n + 1) {
    return true;
  }
  used[vert] = 1;
  bool flag = 0;
  for (auto iter = graph[vert].begin(); iter != graph[vert].end(); iter++) {
    if (!used[*iter]) {
      flag = DFS(*iter, n, graph, used) || flag;
    }
  }
  return flag;
}

void FindPath(int u, int n, std::vector<std::unordered_set<int>> &graph,
              std::vector<bool> &used, std::stack<int> &current_path,
              std::stack<int> &path) {
  used[u] = 1;
  if (u == 2 * n + 1) {
    path = current_path;
    return;
  }
  current_path.push(u);
  for (auto iter = graph[u].begin(); iter != graph[u].end(); iter++) {
    if (!used[*iter]) {
      FindPath(*iter, n, graph, used, current_path, path);
    }
  }
  current_path.pop();
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::unordered_set<int>> graph(2 * n + 2);
  std::vector<bool> used(2 * n + 2);
  std::stack<int> current_path, path;
  for (int i = 1; i <= n; i++) {
    graph[0].insert(i);
    graph[n + i].insert(2 * n + 1);
  }
  bool path_found = 0;
  int answer = 0;
  DFS(0, n, graph, used);
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    if (graph[a].find(b + n) != graph[a].end() ||
        graph[b + n].find(a) != graph[b + n].end()) {
      std::cout << n - answer << ' ';
      continue;
    }
    graph[a].insert(b + n);
    if (!used[b + n] && used[a]) {
      path_found = DFS(b + n, n, graph, used);
    }
    if (path_found) {
      used.assign(2 * n + 2, false);
      answer++;
      FindPath(0, n, graph, used, current_path, path);
      graph[path.top()].erase(2 * n + 1);
      int last = path.top();
      path.pop();
      while (path.size() > 1) {
        graph[path.top()].erase(last);
        graph[last].insert(path.top());
        last = path.top();
        path.pop();
      }
      graph[0].erase(last);
      path.pop();
      used.assign(2 * n + 2, false);
      path_found = DFS(0, n, graph, used);
    }
    std::cout << n - answer << ' ';
  }
  std::cout << "\n";
  return 0;
}
