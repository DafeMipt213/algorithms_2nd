#ifndef LCA_HPP
#define LCA_HPP

#include <vector>

class Solution {
public:
    Solution(std::vector<std::vector<int>> &data, int root);

    int LCA(int v, int u);

private:
    void DFS(int vertex, int parent, int current_height);
    void BuildLCA();

    int MinHeight(int a, int b);

private:
    std::vector<std::vector<int>> adjacency_list_;
    std::vector<int> eulerian_tour_;
    std::vector<int> eulerian_tour_position_;
    std::vector<int> heights_;
    std::vector<int> log_2_;
    int block_size_;
    int block_count_;
    std::vector<std::vector<int>> parent_;
};

#endif
