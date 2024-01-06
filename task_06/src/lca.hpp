#include <vector>

struct AllData{
    int n, block_size, block_cnt;
    std::vector<std::vector<int>> graph, st;
    std::vector<int> visited, euler_bypass, height, log2, block_mask;
    std::vector<std::vector<std::vector<int>>> blocks;
    AllData(){};
};

void dfs(int v, int p, int h, AllData &data);
int min_by_h(int i, int j, AllData data);
void precompute_lca(int root, AllData &data);
int lca_in_block(int b, int l, int r, AllData &data);
int lca(int v, int u, AllData &data);