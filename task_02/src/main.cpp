#include <iostream>
#include <vector>
#include <algorithm>

// Неможифицированный dfs
void dfs(int v, std::vector<bool>& used, std::vector<std::vector<int>>& adj) {
    used[v] = true;

    for (int u : adj[v]) {
        if (!used[u]) {
            dfs(u, used, adj);
        }
    }
}

// Функция для поиска узких мест сети
void findBottlenecks(std::vector<std::vector<int>>& adj, int n) {
    std::vector<bool> used(n, false);

    // Проверяем провода
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int u = i;
            int v = adj[i][j];

            // Удаляем провод
            adj[u].erase(adj[u].begin() + j);
            adj[v].erase(find(adj[v].begin(), adj[v].end(), u));

            // Проверяем связность сети после удаления провода
            fill(used.begin(), used.end(), false);
            dfs(0, used, adj);

            // Если сеть не связна, выводим информацию о проводе
            if (find(used.begin(), used.end(), false) != used.end()) {
                std::cout << "Найдено узкое место: провод между роутерами " << u << " и " << v << std::endl;
            }

            // Восстанавливаем провод
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // Проверяем роутеры
    for (int i = 0; i < n; i++) {
        // Удаляем роутер
        adj[i].clear();

        // Проверяем связность сети после удаления роутера
        fill(used.begin(), used.end(), false);
        dfs(0, used, adj);

        // Если сеть не связна, выводим информацию о роутере
        if (find(used.begin(), used.end(), false) != used.end()) {
            std::cout << "Найдено узкое место: роутер " << i << std::endl;
        }

        // Восстанавливаем роутер
        for (int j = 0; j < n; j++) {
            if (j != i) {
                adj[i].push_back(j);
            }
        }
    }
}

int main() {
    int n; // Количество роутеров
    int m; // Количество проводов

    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);

    // Считываем информацию о проводах
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findBottlenecks(adj, n);

    return 0;
}
