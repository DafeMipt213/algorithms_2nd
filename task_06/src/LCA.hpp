#include <map>
#include <vector>

#include "../../task_05/src/RMQ.hpp"

struct Node {
  int value;
  int height;
  bool used;
  Node *left_child;
  Node *right_child;
  Node(int value);
};

class BinaryTree {
 public:
  BinaryTree();
  ~BinaryTree();

  void destroy_tree();
  void destroy_tree(Node *leaf);
  void dfs_inner(int current_height, Node *current_vertex, int &cnt);
  void dfs();
  int findAncestor(int value1, int value2);
  void makeRmq();

  std::vector<int> heights;
  std::vector<int> values;
  std::map<int, int> indexes;
  Node *root;
  RMQ rmq;
};