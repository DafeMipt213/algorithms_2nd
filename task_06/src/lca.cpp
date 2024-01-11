#include "lca.hpp"
#include <cmath>

Solution::Solution(std::vector<std::vector<int>> &data, int root) {
    int size = data.size();
    eulerian_tour_position_.assign(size, -1);
    heights_.assign(size, 0);
    eulerian_tour_.reserve(2 * size);

    adjacency_list_ = data;

    parent_.assign(size, std::vector<int>(log2(size) + 1, -1));

    DFS(root, -1, 0);
    BuildLCA();
}

void Solution::DFS(int vertex, int parent, int current_height) {
    eulerian_tour_position_[vertex] = (int)eulerian_tour_.size();
    eulerian_tour_.push_back(vertex);
    heights_[vertex] = current_height;

    parent_[vertex][0] = parent;
    for (int i = 1; i <= log_2_.size(); ++i) {
        if (parent_[vertex][i - 1] != -1) {
            parent_[vertex][i] = parent_[parent_[vertex][i - 1]][i - 1];
        }
    }

    for (int u : adjacency_list_[vertex]) {
        if (u != parent) {
            DFS(u, vertex, current_height + 1);
            eulerian_tour_.push_back(vertex);
        }
    }
}

void Solution::BuildLCA() {
   }

int Solution::MinHeight(int a, int b) {
    return (heights_[a] < heights_[b]) ? a : b;
}

int Solution::LCA(int v, int u) {
    if (eulerian_tour_position_[v] > eulerian_tour_position_[u]) {
        std::swap(v, u);
    }

    int l = eulerian_tour_position_[v];
    int r = eulerian_tour_position_[u];

    int answer = MinHeight(eulerian_tour_[l], eulerian_tour_[r]);

    for (int i = log_2_.size(); i >= 0; --i) {
        if (parent_[eulerian_tour_[r]][i] != -1 &&
            eulerian_tour_position_[parent_[eulerian_tour_[r]][i]] >= l) {
            answer = MinHeight(answer, eulerian_tour_[parent_[eulerian_tour_[r]][i]]);
            r = eulerian_tour_position_[parent_[eulerian_tour_[r]][i]];
        }
    }

    return answer;
}