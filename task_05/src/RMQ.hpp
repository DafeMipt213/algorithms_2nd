#include <vector>

class RmqSolver {
 public:
  RmqSolver(const std::vector<int>& data);
  int GitMinimum(size_t start, size_t end);

 private:
  std::vector<std::vector<int>> sparse_table;
  int GetLog(int len);
};