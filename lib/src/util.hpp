#pragma once
#include <bits/stdc++.h>
using namespace std;

struct Pair {
  int dist;
  int node;
};
bool operator<(Pair p1, Pair p2) { return (p1.dist > p2.dist); }
struct GraphMatrix {
  int *pointerB;
  int *column;
  int *value;
  int sizeV;
  int sizeE;
};

void Dijkstra(GraphMatrix *gr, int givenNode, int *up, int *dist) {
  for (int i = 0; i < gr->sizeV; i++)
    dist[i] = INT_MAX;
  dist[givenNode] = 0;
  up[givenNode] = givenNode;
  priority_queue<Pair> pq;
  Pair t = {0, givenNode};
  pq.push(t);
  while (!pq.empty()) {
    Pair s = pq.top();
    pq.pop();
    int okr_s = gr->pointerB[s.node];
    int okr_f = gr->pointerB[s.node + 1];
    for (int okr_i = okr_s; okr_i < okr_f; okr_i++) {
      int j = gr->column[okr_i];
      if (dist[j] > (dist[s.node] + gr->value[okr_i])) {
        dist[j] = (dist[s.node] + gr->value[okr_i]);
        up[j] = s.node;
        Pair p = {dist[j], j};
        pq.push(p);
      }
    }
  }
}

bool BellmanFord(GraphMatrix *gr, int givenNode, int *dist) {
  int okr_s, okr_f, okr_i;
  int i, j, k;
  for (i = 0; i < gr->sizeV; i++)
    dist[i] = INT_MAX;
  dist[givenNode] = 0;
  for (k = 0; k < gr->sizeV - 1; k++) {
    for (i = 0; i < gr->sizeV; i++) {
      okr_s = gr->pointerB[i];
      okr_f = gr->pointerB[i + 1];
      for (okr_i = okr_s; okr_i < okr_f; okr_i++) {
        j = gr->column[okr_i];
        if (dist[j] - gr->value[okr_i] > dist[i]) {
          dist[j] = dist[i] + gr->value[okr_i];
        }
      }
    }
  }
  for (i = 0; i < gr->sizeV; i++) {
    okr_s = gr->pointerB[i];
    okr_f = gr->pointerB[i + 1];
    for (okr_i = okr_s; okr_i < okr_f; okr_i++) {
      j = gr->column[okr_i];
      if (dist[j] > (dist[i] + gr->value[okr_i]))
        return false;
    }
  }
  return true;
}