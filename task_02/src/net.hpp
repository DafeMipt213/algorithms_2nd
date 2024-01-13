#include <algorithm>
#include <vector>

struct Node {
  int id;
  std::vector<Node*> nodes;
  bool used{false};
  Node(int id, std::vector<Node*> nodes = {}) : id(id), nodes(nodes) {}
  void setNodes(std::vector<Node*> routers) { nodes = routers; }
};

class Net {
 public:
  std::vector<int> weak_routers;
  std::vector<std::pair<int, int>> weak_nets;
  void dfs(Node* v, Node* p = nullptr, int timer = 0);
  Net(std::vector<Node*> routers);

 private:
  std::vector<Node*> nodes;
  std::vector<int> tin;
  std::vector<int> fup;
  void init();
};