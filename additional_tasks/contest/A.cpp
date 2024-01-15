#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stack>
#include <vector>

bool FindCycle(int vertex, int parent, std::vector<std::vector<int>> &graph,
               std::stack<int> &stack, std::vector<int> &cycle,
               std::vector<int> &visited) {
  stack.push(vertex);
  visited[vertex] = 1;
  for (int to : graph[vertex]) {
    if (!visited[to]) {
      if (FindCycle(to, vertex, graph, stack, cycle, visited)) return true;
    } else if (visited[to] == 1 && to != parent) {
      while (stack.top() != to) {
        cycle.push_back(stack.top());
        stack.pop();
      }
      cycle.push_back(stack.top());
      return true;
    }
  }
  visited[vertex] = 2;
  stack.pop();
  return false;
}

std::pair<int, int> DFS(int vertex, int parent,
                        std::vector<std::vector<int>> &graph,
                        std::vector<int> &visited) {
  std::pair<int, int> result = {0, 1};
  for (int to : graph[vertex]) {
    if (visited[to] != 3 && to != parent) {
      std::pair<int, int> temp = DFS(to, vertex, graph, visited);
      result.first += std::max(temp.first, temp.second);
      result.second += temp.first;
    }
  }
  return result;
}

void Mark(int vertex, std::vector<std::vector<int>> &graph,
          std::vector<int> &visited) {
  visited[vertex] = 4;
  for (int to : graph[vertex]) {
    if (visited[to] != 4) Mark(to, graph, visited);
  }
}

void Solution() {
  int students_count;
  std::cin >> students_count;
  std::vector<std::vector<int>> graph(students_count);
  std::vector<std::pair<int, int>> edges;
  for (int i = 0; i < students_count; i++) {
    int index;
    std::cin >> index;
    if (index != -1) {
      --index;
      int a = i;
      int b = index;
      if (a > b) std::swap(a, b);
      edges.push_back({a, b});
    }
  }

  std::sort(edges.begin(), edges.end());

  edges.erase(std::unique(edges.begin(), edges.end()), edges.end());

  for (std::pair<int, int> edge : edges) {
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first);
  }

  std::stack<int> stack;
  std::vector<int> cycle;
  std::vector<int> visited(students_count);

  std::stack<int> clear{};

  int answer = 0;
  for (int i = 0; i < students_count; i++) {
    if (!visited[i]) {
      cycle.clear();
      stack.swap(clear);
      FindCycle(i, i, graph, stack, cycle, visited);
      if (!cycle.empty()) {
        for (int vertex : cycle) visited[vertex] = 3;

        std::vector<std::pair<int, int>> array;
        for (int vertex : cycle) {
          array.push_back(DFS(vertex, vertex, graph, visited));
        }

        std::pair<std::pair<int, int>, std::pair<int, int>> d = {
            {array[0].first, array[0].first},
            {array[0].first, array[0].second}};
        for (size_t j = 1; j < array.size(); ++j) {
          std::pair<std::pair<int, int>, std::pair<int, int>> next = {{0, 0},
                                                                      {0, 0}};
          next.first.first =
              std::max(d.first.first, d.first.second) + array[j].first;
          next.first.second = std::max(
              std::max(array[j].first, array[j].second) + d.first.first,
              next.first.first);
          next.second.first =
              std::max(d.second.first, d.second.second) + array[j].first;
          next.second.second = std::max(
              std::max(array[j].first, array[j].second) + d.second.first,
              next.second.first);
          std::swap(next, d);
        }
        answer +=
            std::max(std::max(d.first.second, d.first.first), d.second.first);
      } else {
        std::pair<int, int> temp = DFS(i, i, graph, visited);
        answer += std::max(temp.first, temp.second);
      }

      Mark(i, graph, visited);
    }
  }

  std::cout << answer << "\n";
}

int main() {
  std::cout << std::setprecision(15) << std::fixed;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  Solution();
}