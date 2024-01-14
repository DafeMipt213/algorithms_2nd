#include "graph.hpp"


vector<pair<size_t, size_t>> Graph::bridge_finder(size_t v, int p) {
    vec_bridges.clear();
    util_articulation_points_and_bridge_finder(v, p);
    return vec_bridges;
}

vector<size_t> Graph::articulation_points_finder(size_t v, int p) {
    vec_articulation_points.clear();
    util_articulation_points_and_bridge_finder(v, p);
    return vec_articulation_points;
}

void Graph::util_articulation_points_and_bridge_finder(size_t v, int p) {
    parent[v] = p;
    tin[v] = timer++;
    ret[v] = tin[v];
    used[v] = true;
    for (auto to: g[v]) {
        if (to == p) continue;
        if (used[to]) ret[v] = min(ret[v], tin[to]);
        else {
            util_articulation_points_and_bridge_finder(to, v);
            ret[v] = min(ret[v], ret[to]);
            if (ret[to] == tin[to]) vec_bridges.emplace_back(pair(v, to));
            if (ret[to] >= tin[v] && p != -1) vec_articulation_points.push_back(v);
        }
    }
}
