#include <vector>

using Tree = std::vector<std::vector<int>>;

class SolverLCA {
 public:
  SolverLCA(const Tree& tree, int root);
  int GetLCA(int vertex1, int vertex2);

 private:
  std::vector<int> segments_tree;
  std::vector<int> first_occurrences;
  std::vector<int> result_dfs;
  std::vector<int> heights;
  void init_row(int i, int start, int end);
  void dfs_LCA(int vertex, int heigh, std::vector<bool>& visited,
               const Tree& tree);
  int min_from_tree(int i, int s_right, int s_left, int left, int right);
};