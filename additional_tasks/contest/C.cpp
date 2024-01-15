#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<int, int>>> graph(n);
  std::vector<std::vector<int>> answer(
      n, std::vector<int>(2, std::numeric_limits<int>::max()));
  std::vector<std::vector<std::pair<int, int>>> from(
      n, std::vector<std::pair<int, int>>(2, {-1, -1}));
  std::set<std::pair<int, std::pair<int, int>>> q;

  for (int i = 0; i < m; i++) {
    int v, u, cost;
    std::cin >> v >> u >> cost;
    v--;
    u--;
    graph[v].push_back({u, cost});
    graph[u].push_back({v, cost});
  }

  answer[0][0] = 0;
  answer[0][1] = 0;

  from[0][0] = {-1, -1};
  q.insert({0, {0, 0}});

  while (!q.empty()) {
    auto now = *q.begin();
    q.erase(q.begin());
    while (!q.empty() &&
           answer[now.second.first][now.second.second] < now.first) {
      now = *q.begin();
      q.erase(q.begin());
    }
    int current_vertex = now.second.first;
    int current_t = now.second.second;
    for (auto neibp : graph[current_vertex]) {
      int neib = neibp.first;
      int dist = neibp.second;
      if (answer[current_vertex][current_t] + dist < answer[neib][current_t]) {
        answer[neib][current_t] = answer[current_vertex][current_t] + dist;
        from[neib][current_t] = {current_vertex, current_t};
        q.insert({answer[neib][current_t], {neib, current_t}});
      }
      if (current_t == 0 &&
          answer[current_vertex][current_t] < answer[neib][1]) {
        answer[neib][1] = answer[current_vertex][current_t];
        from[neib][1] = {current_vertex, current_t};
        q.insert({answer[neib][1], {neib, 1}});
      }
    }
  }

  std::vector<int> cities;
  std::cout << answer[n - 1][1] << ' ';
  int current_vertex = n - 1, current_t = 1;
  int first, second;
  while (current_vertex != -1) {
    cities.push_back(current_vertex);
    auto now = from[current_vertex][current_t];
    if (now.second == 0 && current_t == 1) {
      first = now.first;
      second = current_vertex;
    }
    current_vertex = now.first;
    current_t = now.second;
  }
  std::reverse(cities.begin(), cities.end());
  std::cout << cities.size() - 1 << '\n';
  for (auto city : cities) std::cout << city + 1 << ' ';
  std::cout << '\n';
  std::cout << first + 1 << ' ' << second + 1;
  return 0;
}