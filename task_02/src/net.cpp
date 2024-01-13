#include "net.hpp"

void Net::dfs(Node* v, Node* p, int timer) {
  v->used = true;
  tin[v->id] = fup[v->id] = timer++;
  int children = 0;
  for (size_t i = 0; i < v->nodes.size(); ++i) {
    Node* to = v->nodes[i];
    if (to == p) continue;
    if (to->used)
      fup[v->id] = std::min(fup[v->id], tin[to->id]);
    else {
      dfs(to, v, timer);
      fup[v->id] = std::min(fup[v->id], fup[to->id]);
      if (fup[to->id] >= tin[v->id]) {
        weak_nets.push_back({v->id, to->id});
        if (p != nullptr) weak_routers.push_back(v->id);
        ++children;
      }
    }
  }
  if (p == nullptr && children > 1) weak_routers.push_back(v->id);
}
Net::Net(std::vector<Node*> routers) {
  nodes = routers;
  init();
  dfs(nodes[0]);
}
void Net::init() {
  for (int i = 0; i < nodes.size(); ++i) {
    tin.push_back(0);
    fup.push_back(0);
  }
}
;