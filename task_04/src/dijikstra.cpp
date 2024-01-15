#include "dijikstra.hpp"
#include <climits>
#include <iostream>
#include <vector>
#include <limits>

void dijikstra(std::vector<std::vector<int> > &w, int s) {
    size_t n = w.size();
    bool used[n];       // вектор посещений
    int d[n];           // вектор расстояний до s
    for (int i = 0; i < n; ++i) {
        d[i] = w[s][i];
        used[i] = false;
    }

    d[s] = 0;
    int index = 0, u = 0;
    for (int i = 0; i < n; i++) {
        int min = INT_MAX;
        // ищем ближайшую вершину
        for (int j = 0; j < n; j++) {
            if (!used[j] && d[j]<min) {
                min = d[j]; 
                index = j;
            }
        }
        u = index;
        used[u] = true;
        // релаксация ребер
        for (int j = 0; j < n; j++) {
            if (!used[j] && w[u][j]!=INT_MAX && d[u]!=INT_MAX && (d[u] + w[u][j] < d[j])) {
                d[j] = d[u] + w[u][j];
            }
        }
    }

    std::cout << "Алгоритм Дейкстры:\t\n";
    
    for (int i = 0; i < n; i++) {
        if (d[i]!=INT_MAX)
            std::cout << s << " -> " << i << " = " << d[i] << std::endl;
        else 
            std::cout << s << " -> " << i << " = " << "маршрут недоступен" << std::endl;
    }
}

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<std::vector<int> > w(n, std::vector<int> (n, INT_MAX));
    
    dijikstra(w, s);

    return 0;
}