#include "topology_sort.hpp"

#define TREE 0
#define BACK 1
#define FORWARD 2
#define CROSS 3

void graph::initialize_graph(bool directed)
{
    int i;
    this->nvertices = 0;
    this->nedges = 0;
    this->directed = directed;
    for (i = 1; i <= MAXV; ++i) this->degree[i] = 0;
    for (i = 1; i <= MAXV; ++i) this->edges[i] = NULL;

}

void graph::insert_edge(int x, int y, bool directed)
{
    edgenote *p;
    p = new edgenote;
    p->weight = NULL;
    p->y = y;
    p->next = this->edges[x];
    this->edges[x] = p;
    this->degree[x] ++;
    if (directed == false)
        this->insert_edge(y, x, true);
    else
        this->nedges ++;
}

void graph::read_graph(bool directed)
{
    int i;
    int m;
    int x, y;
    this->initialize_graph(directed);
    std::cin >> this->nvertices >> m;
    for (i = 1; i <= m; ++i)
    {
        std::cin >> x >> y;
        this->insert_edge(x, y, directed);
    }
}

void graph::print_graph()
{
    int i;
    edgenote *p;
    for (i = 1; i <= this->nvertices; ++i)
    {
        std::cout << i << ":";
        p = this->edges[i];
        while (p != NULL)
        {
            std::cout << " " << p->y;
            p = p->next;
        }
        std::cout << std::endl;
    }
}

int graph::edge_classification(int x, int y)
{
    if (parent[y] == x) return TREE;
    if (discovered[y] && !processed[y]) return BACK;
    if (processed[y] && (entry_time[y] > entry_time[x])) return FORWARD;
    if (processed[y] && (entry_time[y] < entry_time[x])) return CROSS;
    std::cout << "Warning: unclassified edge (" << x << ", " << y << ")" << std::endl;
}

void graph::process_vertex_late(int v)
{
    sorted.push(v);
}

void graph::process_vertex_early(int v)
{
    std::cout << "process vertex early " << v << std::endl;
}


void graph::process_edge(int x, int y)
{
    int classification;
    classification = edge_classification(x, y);
    if (classification == BACK)
        std::cout << "Warning: directed cycle found, not a DAG" << std::endl;
}

void graph::dfs(int v)
{
    edgenote *p;
    int y;
    if (finished) return;
    discovered[v] = true;
    ++time_count;
    entry_time[v] = time_count;
    process_vertex_early(v);
    p = this->edges[v];
    while (p != NULL)
    {
        y = p->y;
        if (discovered[y] == false)
        {
            parent[y] = v;
            process_edge(v, y);
            this->dfs(y);
        }
        else if ((!processed[y]) || (this->directed))
            process_edge(v, y);
        if (finished) return;
        p = p->next;
    }
    process_vertex_late(v);
    ++time_count;
    exit_time[v] = time_count;
    processed[v] = true;
}

void graph::topsort()
{
    int i;
    for (i = 1; i <= this->nvertices; ++i)
        if (discovered[i] == false)
            this->dfs(i);
    while (!sorted.empty())
        {
            std::cout << sorted.top() << " ";
            sorted.pop();
        }
}