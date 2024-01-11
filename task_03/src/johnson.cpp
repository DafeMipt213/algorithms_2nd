#include "johnson.hpp"
#include <iostream>

const int INF = std::numeric_limits<int>::max();

JohnsonAlgorithm::JohnsonAlgorithm(const std::vector<std::vector<int>>& g)
    : graph(g), numVertices(g.size()) {}

std::vector<std::vector<int>> JohnsonAlgorithm::run() {
    //Добавление новой вершины 's' и рёбер с нулевыми весами
    std::vector<std::vector<int>> augmentedGraph(numVertices + 1, std::vector<int>(numVertices + 1, INF));
    addVirtualVertex(augmentedGraph);

    //Применение алгоритма Беллмана-Форда
    std::vector<int> distances(numVertices + 1, INF);
    distances[numVertices] = 0;

    for (int k = 0; k < numVertices; ++k) {
        for (int u = 0; u <= numVertices; ++u) {
            for (int v = 0; v <= numVertices; ++v) {
                if (augmentedGraph[u][v] != INF) {
                    if (distances[u] + augmentedGraph[u][v] < distances[v]) {
                        distances[v] = distances[u] + augmentedGraph[u][v];
                    }
                }
            }
        }
    }

    //Удаление вершины 's' и коррекция весов рёбер
    removeVirtualVertex(augmentedGraph);

    //Применение алгоритма Дейкстры для каждой вершины
    std::vector<std::vector<int>> shortestPaths(numVertices, std::vector<int>(numVertices, INF));

    for (int u = 0; u < numVertices; ++u) {
        std::vector<int> minDistances(numVertices, INF);
        minDistances[u] = 0;

        std::vector<bool> visited(numVertices, false);

        for (int i = 0; i < numVertices; ++i) {
            int minDistance = INF;
            int minIndex = -1;

            for (int j = 0; j < numVertices; ++j) {
                if (!visited[j] && minDistances[j] < minDistance) {
                    minDistance = minDistances[j];
                    minIndex = j;
                }
            }

            visited[minIndex] = true;

            for (int v = 0; v < numVertices; ++v) {
                if (!visited[v] && augmentedGraph[minIndex][v] != INF) {
                    if (minDistance + augmentedGraph[minIndex][v] < minDistances[v]) {
                        minDistances[v] = minDistance + augmentedGraph[minIndex][v];
                    }
                }
            }
        }

        shortestPaths[u] = minDistances;
    }

    return shortestPaths;
}

void JohnsonAlgorithm::addVirtualVertex(std::vector<std::vector<int>>& augmentedGraph) {
    for (int v = 0; v < numVertices; ++v) {
        augmentedGraph[numVertices][v] = 0;
    }
}

void JohnsonAlgorithm::removeVirtualVertex(std::vector<std::vector<int>>& augmentedGraph) {
    augmentedGraph.pop_back();
    for (int i = 0; i < numVertices; ++i) {
        augmentedGraph[i].pop_back();
    }
}

void JohnsonAlgorithm::adjustWeights(std::vector<int>& distances) {
    for (int& distance : distances) {
        distance += distances[numVertices] - distances[0];
    }
}
