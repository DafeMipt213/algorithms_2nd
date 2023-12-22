#include "LCA.hpp"

void SolverLCA::dfs_LCA(int vertex, int height, std::vector<bool>& visited,
                        const Tree& tree) {
  visited[vertex] = true;
  heights[vertex] = height;
  result_dfs.push_back(vertex);
  for (int i = 0; i < tree[vertex].size(); ++i)
    if (!visited[tree[vertex][i]]) {
      dfs_LCA(tree[vertex][i], height + 1, visited, tree);
      result_dfs.push_back(vertex);
    }
}

SolverLCA::SolverLCA(const Tree& tree, int root) {
  heights = std::vector<int>(tree.size());
  std::vector<bool> visited(tree.size(), false);

  dfs_LCA(root, 1, visited, tree);

  segments_tree = std::vector<int>(result_dfs.size() * 4 + 1, -1);
  init_row(1, 0, result_dfs.size() - 1);

  first_occurrences = std::vector<int>(tree.size(), -1);
  for (size_t i = 0; i < result_dfs.size(); ++i) {
    int vertex = result_dfs[i];
    if (first_occurrences[vertex] == -1) first_occurrences[vertex] = i;
  }
}

void SolverLCA::init_row(int i, int start, int end) {
  if (start == end)
    segments_tree[i] = result_dfs[start];
  else {
    int middle = (start + end) >> 1;
    init_row(i + i, start, middle);
    init_row(i + i + 1, middle + 1, end);
    if (heights[segments_tree[i + i]] < heights[segments_tree[i + i + 1]])
      segments_tree[i] = segments_tree[i + i];
    else
      segments_tree[i] = segments_tree[i + i + 1];
  }
}

int SolverLCA::GetLCA(int vertex1, int vertex2) {
  int index1 = first_occurrences[vertex1];
  int index2 = first_occurrences[vertex2];
  if (index1 > index2) std::swap(index1, index2);
  return min_from_tree(1, 0, result_dfs.size() - 1, index1, index2);
}

int SolverLCA::min_from_tree(int i, int s_left, int s_right, int left,
                             int right) {
  if (s_left == left && s_right == right) return segments_tree[i];
  int s_middle = (s_left + s_right) >> 1;
  if (right <= s_middle)
    return min_from_tree(i + i, s_left, s_middle, left, right);
  if (left > s_middle)
    return min_from_tree(i + i + 1, s_middle + 1, s_right, left, right);
  int answer1 = min_from_tree(i + i, s_left, s_middle, left, s_middle);
  int answer2 =
      min_from_tree(i + i + 1, s_middle + 1, s_right, s_middle + 1, right);
  return (heights[answer1] < heights[answer2]) ? answer1 : answer2;
}
