#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int borne = 201 * 1000;
int nbNodes, nbEdges;

vector<int> adj[borne];
bool vu[borne];
vector<pair<int, int>> ivComp;

void Dfs(int nod, int& weaker, int& bigger) {
  vu[nod] = true;
  weaker = min(weaker, nod);
  bigger = max(bigger, nod);

  for (int neighbor : adj[nod])
    if (!vu[neighbor]) {
      Dfs(neighbor, weaker, bigger);
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> nbNodes >> nbEdges;
  for (int iEdge = 0; iEdge < nbEdges; ++iEdge) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int nod = 0; nod < nbNodes; ++nod) {
    if (!vu[nod]) {
      int weaker = nod, bigger = nod;
      Dfs(nod, weaker, bigger);
      ivComp.emplace_back(weaker, bigger);
    }
  }

  int curEnd = -1;
  int rep = 0;

  for (auto comp : ivComp) {
    if (comp.first <= curEnd) {
      ++rep;
    }
    curEnd = max(curEnd, comp.second);
  }

  cout << rep << "\n";
  return 0;
}