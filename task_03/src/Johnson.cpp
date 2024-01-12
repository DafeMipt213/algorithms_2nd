#include "util.hpp"

void Johnson(GraphMatrix *gr, int *up, int *dist) {
  int i, j, n;
  int okr_s, okr_f, okr_i;
  int *h;
  GraphMatrix gr_h;
  n = gr->sizeV;
  gr_h.sizeV = n + 1;
  gr_h.sizeE = gr->sizeE + n;
  gr_h.column = new int[gr->sizeE + n];
  gr_h.value = new int[gr->sizeE + n];
  gr_h.pointerB = new int[n + 2];
  h = new int[n + 1];
  for (i = 0; i < gr->sizeE; i++) {
    gr_h.column[i + n] = gr->column[i] + 1;
    gr_h.value[i + n] = gr->value[i];
  }
  gr_h.pointerB[0] = 0;
  for (i = 0; i < n; i++) {
    gr_h.pointerB[i + 1] = gr->pointerB[i] + n;
    gr_h.column[i] = i;
    gr_h.value[i] = 0;
  }
  gr_h.pointerB[i + 1] = gr->pointerB[i] + n;
  bool f = false;
  f = BellmanFord(&gr_h, 0, h);
  if (!f) {
    printf("exist negativ circle\n");
    return;
  }
  for (i = 0; i < n; i++) {
    okr_s = gr->pointerB[i];
    okr_f = gr->pointerB[i + 1];
    for (okr_i = okr_s; okr_i < okr_f; okr_i++) {
      j = gr->column[okr_i];
      gr->value[okr_i] += h[i + 1] - h[j + 1];
    }
  }
  for (i = 0; i < n; i++)
    Dijkstra(gr, i, up + n * i, dist + n * i);
  for (i = 0; i < n; i++) {
    okr_s = gr->pointerB[i];
    okr_f = gr->pointerB[i + 1];
    for (okr_i = okr_s; okr_i < okr_f; okr_i++) {
      j = gr->column[okr_i];
      gr->value[okr_i] -= h[i + 1] - h[j + 1];
    }
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      dist[n * i + j] += h[j + 1] - h[i + 1];
  delete[] h;
}