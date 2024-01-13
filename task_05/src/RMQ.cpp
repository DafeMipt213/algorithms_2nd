#include "RMQ.hpp"

const int INF = 1e9;

std::vector<std::vector<int> > table_construct(int n, std::vector<int> &vec) {
  int new_size = ceil(log2(n));
  for (int i = n; i < pow(2, new_size); ++i) {
    vec.push_back(INF);
  }
  int tmp = 1;
  int count = 1;
  std::vector<std::vector<int> > vec2D;
  vec2D.resize(pow(2, new_size));

  std::vector<int> tmp_vec = vec;
  while (pow(2, tmp) <= pow(2, new_size)) {
    for (int i = 0; i < tmp_vec.size() - count; ++i) {
      vec2D[tmp].push_back(std::min(tmp_vec[i], tmp_vec[i + count]));
    }
    tmp_vec = vec2D[tmp];
    tmp++;
    count *= 2;
  }

  return vec2D;
}

int RMQ(int a, int b, std::vector<std::vector<int> > vec2D) {
  if (a > b or a < 0 or b >= vec2D.size()) throw "Bad input";
  if (vec2D.size() == 0) throw "Empty array";
  int dist = b - a + 1;
  int log_dist = floor(log2(dist));

  int k =
      std::min(vec2D[log_dist][a], vec2D[log_dist][dist - pow(2, log_dist)]);

  return k;
}