#include <vector>

using Tree = std::vector<std::vector<int>>;

class LcaSolver {
 public:
  LcaSolver(const Tree& tree, int root);
  int GetLca(int vertex1, int vertex2);

 private:
  std::vector<int> segments_tree;
  std::vector<int> first_occurrences;
  std::vector<int> result_dfs;
  std::vector<int> heights;
  void InitRow(int i, int start, int end);
  void DfsLca(int vertex, int heigh, std::vector<bool>& visited,
              const Tree& tree);
  int MinFromTree(int i, int s_right, int s_left, int left, int right);
};