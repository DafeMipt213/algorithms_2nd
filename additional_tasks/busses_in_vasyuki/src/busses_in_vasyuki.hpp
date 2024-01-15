#pragma once

#include <vector>

struct Edge {
  Edge(long long t_f, size_t d, long long t_d)
      : time_from{t_f}, dest{d}, time_dest{t_d} {}
  long long time_from;
  size_t dest;
  long long time_dest;
};

long long BussesInVasyuki(std::vector<std::vector<Edge>>& g, size_t from,
                          size_t to);