#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#include "johnson.hpp"

void addEdge(std::vector<Edge>& edges, int src, int dest, int weight) {
    edges.push_back({src, dest, weight});
}

std::vector<std::vector<int> > johnson(std::vector<Edge>& edges, int V) {
    // Создаем дополнительную вершину и добавляем ребра из нее во все остальные вершины с весом 0
    for (int i = 0; i < V; i++) {
        addEdge(edges, V, i, 0);
    }

    // Используем алгоритм Беллмана-Форда для нахождения кратчайших путей из дополнительной вершины до всех остальных
    std::vector<int> dist(V + 1, INT_MAX);
    dist[V] = 0;

    for (int i = 0; i < V; i++) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Удаляем дополнительную вершину и обновляем веса ребер графа
    edges.pop_back();

    for (auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            // Если существует цикл отрицательного веса, возвращаем пустой вектор
            return {};
        }

        edge.weight += dist[u] - dist[v];
    }

    // Используем алгоритм Дейкстры для нахождения кратчайших путей от каждой вершины до всех остальных
    std::vector<std::vector<int>> shortestPaths(V, std::vector<int>(V, INT_MAX));

    for (int i = 0; i < V; i++) {
        std::vector<int> distance(V, INT_MAX);
        distance[i] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, i});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& edge : edges) {
                int v = edge.dest;
                int weight = edge.weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        for (int j = 0; j < V; j++) {
            shortestPaths[i][j] = distance[j];
        }
    }

    // Возвращаем кратчайшие пути от каждой вершины до всех остальных
    return shortestPaths;
}

// Тесты для функции johnsonAlgorithm
void test_johnson() {
    std::vector<Edge> edges;
    int V = 4;

    addEdge(edges, 0, 1, -5);
    addEdge(edges, 0, 2, 2);
    addEdge(edges, 1, 2, 4);
    addEdge(edges, 1, 3, 3);
    addEdge(edges, 2, 1, -6);
    addEdge(edges, 3, 2, 1);

    std::vector<std::vector<int> > result = johnson(edges, V);

    // Ожидаемые результаты:
    // {{0, -5, -1, -4},
    //  {INF, 0, -6, -9},
    //  {INF, -6, 0, -3},
    //  {INF, 1, -5, 0}}
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    test_johnson();

    return 0;
}

