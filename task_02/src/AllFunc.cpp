#include "AllFunc.hpp"

void AllFunc(std::vector<std::vector<int> > &graph,
             std::set<std::pair<int, int> > &result, std::set<int> &cpvector) {
  int timer = 0, parent = -1;

  std::vector<int> tin(graph.size(), 0);
  std::vector<int> fup(graph.size(), 0);
  std::vector<bool> used(graph.size(), 0);

  std::set<std::pair<int, int> > res;

  std::set<int> cpvec;

  for (int i = 0; i < graph.size(); i++) {
    if (!used[i]) {
      FindBridges(timer, i, graph, tin, fup, parent, res, used);
    }
  }
  result = returnBridges(res);
  tin.resize(graph.size(), 0);
  fup.resize(graph.size(), 0);
  used.resize(graph.size(), 0);
  FindCutPoint(timer, 0, graph, tin, fup, parent, cpvec, used);
}