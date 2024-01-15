#include "topology_sort.hpp"

#include <vector>
#include <algorithm>

#include "topology_sort.hpp"

void dfs(int v, std::vector<std::vector<int> >& g, std::vector<Colors>& color, std::vector<int>& ans, bool is_circle){
    color[v] = Colors::Gray;
    for(auto& to : g[v]){
        if(color[to] == Colors::White){
            dfs(to, g, color, ans, is_circle);
        }
        else if (color[to] == Colors::Gray) {
            is_circle = true;
        }

        if(is_circle == true){
            return;
        }
    }
    color[v] = Colors::Black;
    ans.push_back(v);
}

void topology_sort(std::vector<std::vector<int> >& g, std::vector<Colors>& color, std::vector<int>& ans, bool is_circle){
    for(int i = 0; i < g.size(); ++i){
        if (color[i] == Colors::White){
            dfs(i, g, color, ans, is_circle);
        }
    }
    reverse(ans.begin(), ans.end());
}
