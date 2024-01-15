#include "busses_in_vasyuki.hpp"

#include <limits>
#include <set>
#include <utility>
#include <vector>

const long long INF = std::numeric_limits<long long>::max();

long long BussesInVasyuki(std::vector<std::vector<Edge>>& g, size_t from,
                          size_t to) {
  std::vector<long long> departure_time(g.size(), INF);
  departure_time[from] = 0;
  std::set<std::pair<long long, size_t>> q;
  q.insert(std::make_pair(0, from));
  while (!q.empty()) {
    std::pair<size_t, unsigned long long> cur = *q.begin();
    q.erase(q.begin());

    for (auto& u : g[cur.second]) {
      if (cur.first <= u.time_from) {
        if (departure_time[u.dest] > u.time_dest) {
          departure_time[u.dest] = u.time_dest;
          q.insert(std::make_pair(departure_time[u.dest], u.dest));
        }
      }
    }
  }
  if (departure_time[to] == INF) {
    return -1;
  }
  return departure_time[to];
}