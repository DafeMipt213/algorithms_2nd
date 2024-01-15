#include <iostream>
#include <memory>
#include <set>
#include <vector>

constexpr long long kMod = static_cast<long long>(1e9) + 7;

void DFS(const std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
         std::set<std::pair<int, int>> &bridges, std::vector<int> &tin,
         std::vector<int> &fup, int &timer, int vertex, int parent) {
  visited[vertex] = true;
  tin[vertex] = fup[vertex] = timer++;
  for (int u : graph[vertex]) {
    if (u == parent) continue;
    if (!visited[u]) {
      DFS(graph, visited, bridges, tin, fup, timer, u, vertex);
      fup[vertex] = std::min(fup[vertex], fup[u]);
      if (fup[u] > tin[vertex])
        bridges.insert({std::min(vertex, u), std::max(vertex, u)});
    } else {
      fup[vertex] = std::min(fup[vertex], tin[u]);
    }
  }
}

void FindComponent(const std::vector<std::vector<int>> &graph,
                   std::vector<bool> &visited,
                   const std::set<std::pair<int, int>> &bridges,
                   std::vector<int> &get_component, int component,
                   int &vertex_sizes, int vertex) {
  visited[vertex] = true;
  get_component[vertex] = component;
  vertex_sizes++;
  for (int u : graph[vertex]) {
    std::pair<int, int> pair = {std::min(vertex, u), std::max(vertex, u)};
    if (bridges.find(pair) != bridges.end()) continue;
    if (!visited[u]) {
      FindComponent(graph, visited, bridges, get_component, component,
                    vertex_sizes, u);
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; i++) {
    int v, u;
    std::cin >> v >> u;
    --v;
    --u;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }
  std::set<std::pair<int, int>> bridges;
  std::vector<bool> visited(n, false);
  std::vector<int> tin(n, 0);
  std::vector<int> fup(n, 0);

  int timer = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) DFS(graph, visited, bridges, tin, fup, timer, i, -1);
  }

  std::fill(visited.begin(), visited.end(), false);
  std::vector<int> component_sizes(n, 0);
  std::vector<int> get_components(n, 0);
  int component = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      int vertexes_count = 0;
      FindComponent(graph, visited, bridges, get_components, component,
                    vertexes_count, i);
      component_sizes[component++] = vertexes_count;
    }
  }
  std::vector<int> deg(component, 0);
  for (const auto &bridge : bridges) {
    deg[get_components[bridge.first]]++;
    deg[get_components[bridge.second]]++;
  }
  int answer = 0;
  int count = 1;

  for (int i = 0; i < component; i++) {
    if (deg[i] <= 1) {
      answer++;
      count = static_cast<int>((count * 1LL * component_sizes[i]) % kMod);
    }
  }

  std::cout << answer << " " << count;
  return 0;
}