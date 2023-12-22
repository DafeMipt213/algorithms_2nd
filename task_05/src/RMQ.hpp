#include <vector>

class SolveRMQ {
 public:
  SolveRMQ(const std::vector<int>& data);
  int GitMinimum(size_t start, size_t end);

 private:
  std::vector<std::vector<int>> SparseTable;
  int GetLog(int len);
};