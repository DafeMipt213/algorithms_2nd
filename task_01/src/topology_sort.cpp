#include "topology_sort.hpp"

#define TREE 0
#define BACK 1
#define FORWARD 2
#define CROSS 3

void Graph::InitializeGraph(bool directed) {
  int i;
  this->nvertices = 0;
  this->nedges = 0;
  this->directed = directed;
  for (i = 1; i <= MAXV; ++i) this->degree[i] = 0;
  for (i = 1; i <= MAXV; ++i) this->edges[i] = NULL;
}

void Graph::InsertEdge(int x, int y, bool directed) {
  Edgenote *p;
  p = new Edgenote;
  p->weight = NULL;
  p->y = y;
  p->next = this->edges[x];
  this->edges[x] = p;
  this->degree[x]++;
  if (directed == false)
    this->InsertEdge(y, x, true);
  else
    this->nedges++;
}

void Graph::ReadGraph(bool directed) {
  int i;
  int m;
  int x, y;
  this->InitializeGraph(directed);
  std::cin >> this->nvertices >> m;
  for (i = 1; i <= m; ++i) {
    std::cin >> x >> y;
    this->InsertEdge(x, y, directed);
  }
}

void Graph::PrintGraph() {
  int i;
  Edgenote *p;
  for (i = 1; i <= this->nvertices; ++i) {
    std::cout << i << ":";
    p = this->edges[i];
    while (p != NULL) {
      std::cout << " " << p->y;
      p = p->next;
    }
    std::cout << std::endl;
  }
}

void Graph::SetQuantity(int nvertices, int nedges) {
  InitializeGraph(true);
  this->nvertices = nvertices;
  this->nedges = nedges;
}

int Graph::EdgeClassification(int x, int y) {
  if (parent[y] == x) return TREE;
  if (discovered[y] && !processed[y]) return BACK;
  if (processed[y] && (entry_time[y] > entry_time[x])) return FORWARD;
  if (processed[y] && (entry_time[y] < entry_time[x])) return CROSS;
  std::cout << "Warning: unclassified edge (" << x << ", " << y << ")"
            << std::endl;
}

void Graph::ProcessVertexLate(int v) { sorted.push(v); }

void Graph::ProcessVertexEarly(int v) {
  // std::cout << "process vertex early " << v << std::endl;
}

void Graph::ProcessEdge(int x, int y) {
  int classification;
  classification = EdgeClassification(x, y);
  if (classification == BACK)
    std::cout << "Warning: directed cycle found, not a DAG" << std::endl;
}

void Graph::Dfs(int v) {
  Edgenote *p;
  int y;
  if (finished) return;
  discovered[v] = true;
  ++time_count;
  entry_time[v] = time_count;
  ProcessVertexEarly(v);
  p = this->edges[v];
  while (p != NULL) {
    y = p->y;
    if (discovered[y] == false) {
      parent[y] = v;
      ProcessEdge(v, y);
      this->Dfs(y);
    } else if ((!processed[y]) || (this->directed))
      ProcessEdge(v, y);
    if (finished) return;
    p = p->next;
  }
  ProcessVertexLate(v);
  ++time_count;
  exit_time[v] = time_count;
  processed[v] = true;
}

std::vector<int> Graph::TopSort() {
  int i;
  std::vector<int> vec_vertex;
  for (i = 1; i <= this->nvertices; ++i)
    if (discovered[i] == false) this->Dfs(i);
  while (!sorted.empty()) {
    vec_vertex.push_back(sorted.top());
    sorted.pop();
  }
  return vec_vertex;
}