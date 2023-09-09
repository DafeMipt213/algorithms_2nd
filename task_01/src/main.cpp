#include <iostream>
#include <vector>

#include "topology_sort.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    bool is_circle = false;
    std::vector<std::vector<int> > g(n, std::vector<int>(0));
    std::vector<Colors> color(n, Colors::White);
    std::vector<int> ans(0);

    int a, b;
    for(int i = 0; i < m; ++i){
        std::cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
    }

    topology_sort(g, color, ans, is_circle);

    for(int i : ans){
        std::cout << i + 1 << " ";
    }
}
