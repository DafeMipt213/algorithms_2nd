#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Dijkstra {
private:
    int nodes;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

    void relax(int start, int current, std::vector<std::vector<int>>& distances, std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>& q) {
        for (const auto& edge : adjacencyList[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (distances[start][next] > distances[start][current] + weight) {
                distances[start][next] = distances[start][current] + weight;
                q.emplace(distances[start][next], next);
                relax(start, next, distances, q);
            }
        }
    }

public:
    Dijkstra(int n) : nodes(n), adjacencyList(n) {}

    void addLink(int a, int b, int cost) {
        adjacencyList[a].emplace_back(b, cost);
        adjacencyList[b].emplace_back(a, cost);
    }

    std::vector<std::vector<int>> findShortestPaths() {
        std::vector<std::vector<int>> distances(nodes, std::vector<int>(nodes, INT_MAX));

        for (int start = 0; start < nodes; ++start) {
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
            distances[start][start] = 0;
            q.emplace(0, start);

            while (!q.empty()) {
                int current = q.top().second;
                q.pop();
                relax(start, current, distances, q);
            }
        }

        return distances;
    }
};

int main() {
    int vertices = 5;
    Dijkstra dijkstra(vertices);

    dijkstra.addLink(0, 1, 2);
    dijkstra.addLink(1, 3, 2);
    dijkstra.addLink(1, 2, 1);
    dijkstra.addLink(3, 0, 2);
    dijkstra.addLink(2, 3, 3);
    dijkstra.addLink(4, 2, 1);
    dijkstra.addLink(4, 3, 2);

    auto distances = dijkstra.findShortestPaths();

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            std::cout << distances[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}