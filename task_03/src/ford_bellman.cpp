#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::pair<std::vector<int>, bool> Ford(const std::vector<std::vector<std::pair<int, int> > >& graph, int v, int infinity) {
    std::vector<int> dist(graph.size(), infinity), p (graph.size(), -1);
    dist[v] = 0;
    for (int k = 0; k < graph.size() - 1; ++k)
		for (int i = 0; i < graph.size(); ++i)
			for (const auto& j : graph[i])
				if (dist[i] != infinity && dist[j.first] > dist[i] + j.second) {
					dist[j.first] = dist[i] + j.second;
                    p[j.first] = i;
                }

    int x = -1;
    for (int i = 0; i < graph.size(); ++i)
        for (const auto& j : graph[i])
            if (dist[i] != infinity && dist[j.first] > dist[i] + j.second) {
                dist[j.first] = dist[i] + j.second;
                p[j.first] = i;
                x = j.first;
                break;
            }
    if (x == -1)
        return {dist, false};

    for (int i = 0; i < graph.size(); ++i)
        x = p[x];
    std::vector<int> path;
    for (int i = x;; i = p[i]) {
        path.push_back(i);
        if (i == x && path.size() > 1)
            break;
    }
    std::reverse(path.begin(), path.end());
    return {path, true};
}


int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    --s;
    constexpr int infinity = std::numeric_limits<int>::max();
    std::vector<std::vector<std::pair<int, int>>> graph(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int f, s, len;
        std::cin >> f >> s >> len;
        graph[--f].push_back({--s, len});
    }
    auto ans = Ford(graph, s, infinity);
    if (ans.second) {
        std::cout << "Cicle: ";
        for (auto& i : ans.first)
            std::cout << i + 1 << ", ";
        return 0;
    }
    std::cout << "No Cicle\n";
    for (int i = 0; i < graph.size(); ++i) {
        std::cout << s + 1 << "-->" << i + 1 << " = ";
        if (ans.first[i] == infinity)
            std::cout << "INF\n";
        else 
            std::cout << ans.first[i] << '\n';
    }
}