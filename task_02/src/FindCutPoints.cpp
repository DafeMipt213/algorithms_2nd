#include "FindCutPoints.hpp"

void FindCutPoint (int &timer, int start, std::vector< std::vector<int> > &graph, std::vector<int> &tin, std::vector<int> &fup, int parent, std::set<int> &cpvec, std::vector<bool> used) {
    used[start] = 1;
    tin[start] = fup[start] = ++timer;
    int to;
    int children = 0;
    for (int i = 0; i < graph[start].size(); ++i) {
        to = graph[start][i];
        if (to == parent) continue;
        if (used[to])
            fup[start] = std::min(fup[start], tin[to]);
        else {
            FindCutPoint(timer, to, graph, tin, fup, start, cpvec, used);
            fup[start] = std::min(fup[start], fup[to]);
            if (fup[to] >= tin[start] && parent != -1)
                cpvec.insert(start);
            children++;
        }
    }

}

std::set<int> returnCP (std::set<int> &cpvec) {
    return cpvec;
}