#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int borne = 201 * 1000;
int nodes, edges;

vector<int> adj[borne];
bool vu[borne];
vector<pair<int, int>> comp;

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

  cin >> nodes >> edges;
  for (int edge = 0; edge < edges; ++edge) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int nod = 0; nod < nodes; ++nod) {
    if (!vu[nod]) {
      int weaker = nod, bigger = nod;
      Dfs(nod, weaker, bigger);
      comp.emplace_back(weaker, bigger);
    }
  }

  int end = -1;
  int rep = 0;

  for (auto comp : comp) {
    if (comp.first <= end) {
      ++rep;
    }
    end = max(end, comp.second);
  }

  cout << rep << "\n";
  return 0;
}