#include "rmq.hpp"

void DFS(int v, int p, int h, AllData &data) {
  data.visited[v] = data.euler_bypass.size();
  data.euler_bypass.push_back(v);
  data.height[v] = h;

  for (int u : data.graph[v]) {
    if (u == p) continue;
    DFS(u, v, h + 1, data);
    data.euler_bypass.push_back(v);
  }
}

int MinimumHeights(int i, int j, const AllData &data) {
  return data.height[data.euler_bypass[i]] < data.height[data.euler_bypass[j]]
             ? i
             : j;
}

void Precompute(int root, AllData &data) {
  data.visited.assign(data.n, -1);
  data.height.assign(data.n, 0);
  data.euler_bypass.reserve(2 * data.n);
  DFS(root, -1, 0, data);

  int m = data.euler_bypass.size();
  data.log2.reserve(m + 1);
  data.log2.push_back(-1);
  for (int i = 1; i <= m; i++) data.log2.push_back(data.log2[i / 2] + 1);

  data.block_size = std::max(1, data.log2[m] / 2);
  data.block_cnt = (m + data.block_size - 1) / data.block_size;

  data.st.assign(data.block_cnt,
                 std::vector<int>(data.log2[data.block_cnt] + 1));
  for (int i = 0, j = 0, b = 0; i < m; i++, j++) {
    if (j == data.block_size) j = 0, b++;
    if (j == 0 || MinimumHeights(i, data.st[b][0], data) == i)
      data.st[b][0] = i;
  }
  for (int l = 1; l <= data.log2[data.block_cnt]; l++) {
    for (int i = 0; i < data.block_cnt; i++) {
      int ni = i + (1 << (l - 1));
      if (ni >= data.block_cnt)
        data.st[i][l] = data.st[i][l - 1];
      else
        data.st[i][l] =
            MinimumHeights(data.st[i][l - 1], data.st[ni][l - 1], data);
    }
  }

  data.block_mask.assign(data.block_cnt, 0);
  for (int i = 0, j = 0, b = 0; i < m; i++, j++) {
    if (j == data.block_size) j = 0, b++;
    if (j > 0 && (i >= m || MinimumHeights(i - 1, i, data) == i - 1))
      data.block_mask[b] += 1 << (j - 1);
  }

  data.blocks.resize(1 << (data.block_size - 1));
  for (int b = 0; b < data.block_cnt; b++) {
    int mask = data.block_mask[b];
    if (!data.blocks[mask].empty()) continue;
    data.blocks[mask].assign(data.block_size,
                             std::vector<int>(data.block_size));
    for (int l = 0; l < data.block_size; l++) {
      data.blocks[mask][l][l] = l;
      for (int r = l + 1; r < data.block_size; r++) {
        data.blocks[mask][l][r] = data.blocks[mask][l][r - 1];
        if (b * data.block_size + r < m)
          data.blocks[mask][l][r] =
              MinimumHeights(b * data.block_size + data.blocks[mask][l][r],
                             b * data.block_size + r, data) -
              b * data.block_size;
      }
    }
  }
}

int LCABlock(int b, int l, int r, const AllData &data) {
  return data.blocks[data.block_mask[b]][l][r] + b * data.block_size;
}

int LCA(int v, int u, const AllData &data) {
  int l = data.visited[v];
  int r = data.visited[u];
  if (l > r) std::swap(l, r);
  int bl = l / data.block_size;
  int br = r / data.block_size;
  if (bl == br)
    return data.euler_bypass[LCABlock(bl, l % data.block_size,
                                      r % data.block_size, data)];
  int ans1 = LCABlock(bl, l % data.block_size, data.block_size - 1, data);
  int ans2 = LCABlock(br, 0, r % data.block_size, data);
  int ans = MinimumHeights(ans1, ans2, data);
  if (bl + 1 < br) {
    l = data.log2[br - bl - 1];
    int ans3 = data.st[bl + 1][l];
    int ans4 = data.st[br - (1 << l)][l];
    ans = MinimumHeights(ans, MinimumHeights(ans3, ans4, data), data);
  }
  return data.euler_bypass[ans];
}

int RMQ(int left, int right, const std::vector<int> &graph) {
  AllData data;
  std::vector<int> parent(graph.size(), -1);
  std::stack<int> stack;

  for (int i = 0; i < graph.size(); i++) {
    int last = -1;
    while (!stack.empty() && graph[stack.top()] >= graph[i]) {
      last = stack.top();
      stack.pop();
    }
    if (!stack.empty()) parent[i] = stack.top();
    if (last >= 0) parent[last] = i;
    stack.push(i);
  }

  int root = -1;
  data.graph.assign(graph.size(), std::vector<int>());
  for (int i = 0; i < graph.size(); i++) {
    data.graph[i].push_back(parent[i]);
    if (parent[i] != -1) data.graph[parent[i]].push_back(i);
    if (parent[i] == -1) root = i;
  }
  data.n = graph.size();
  Precompute(root, data);
  return LCA(left, right, data);
}