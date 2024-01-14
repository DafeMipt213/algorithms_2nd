#pragma once

#include <iostream>
#include <queue>
#include <stack>

#define MAXV 10

struct edgenote
{
    int y;
    int weight;
    struct edgenote *next;
};

struct graph
{

    void initialize_graph(bool directed);
    void insert_edge(int x, int y, bool directed);
    void read_graph(bool directed);
    void print_graph();
    int edge_classification(int x, int y);
    void process_vertex_late(int v);
    void process_vertex_early(int v);
    void process_edge(int x, int y);
    void dfs(int v);
    void topsort();

    edgenote *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;

    bool processed[MAXV+1];
    bool discovered[MAXV+1];
    int parent[MAXV+1];
    int entry_time[MAXV+1];
    int exit_time[MAXV+1];
    int time_count = 0;
    bool finished = false;
    std::stack<int> sorted;
};
