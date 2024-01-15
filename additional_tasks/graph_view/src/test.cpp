#include <gtest/gtest.h>

#include <stack>

#include "translation.hpp"

TEST(Translation, convert_vec_vec_to_vec_set) {
  std::vector<std::vector<int>> g_vec = {
      {1, 2, 4},     // v0
      {0, 1, 2, 2},  // v1
      {2},           // v2
      {},            // v3
      {},            // v4
      {},            // v5
  };

  std::vector<std::unordered_set<int>> g_set_expected = {
      {1, 2, 4},     // v0
      {0, 1, 2, 2},  // v1
      {2},           // v2
      {},            // v3
      {},            // v4
      {},            // v5
  };

  std::vector<std::unordered_set<int>> g_set =
      convert_vec_vec_to_vec_set(g_vec);

  ASSERT_EQ(g_set, g_set_expected);
}

TEST(Translation, convert_vec_vec_to_matrix) {
  std::vector<std::vector<int>> g_vec = {
      {1, 2, 4},     // v0
      {0, 1, 2, 2},  // v1
      {2},           // v2
      {},            // v3
      {},            // v4
      {},            // v5
  };

  std::vector<std::vector<int>> g_matrix_expected = {
      {0, 1, 1, 0, 1, 0},  // v0
      {1, 1, 1, 0, 0, 0},  // v1
      {0, 0, 1, 0, 0, 0},  // v2
      {0, 0, 0, 0, 0, 0},  // v3
      {0, 0, 0, 0, 0, 0},  // v4
      {0, 0, 0, 0, 0, 0},  // v5
  };

  std::vector<std::vector<int>> g_matrix = convert_vec_vec_to_matrix(g_vec);

  ASSERT_EQ(g_matrix, g_matrix_expected);
}

TEST(Translation, convert_vec_vec_to_vec_pair) {
  std::vector<std::vector<int>> g_vec = {
      {1, 2, 4},     // v0
      {0, 1, 2, 2},  // v1
      {2},           // v2
      {},            // v3
      {},            // v4
      {},            // v5
  };

  std::vector<std::pair<int, int>> g_pair_expected = {
      {0, 1}, {0, 2}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 2}, {2, 2}};
  std::vector<std::pair<int, int>> g_pair = convert_vec_vec_to_vec_pair(g_vec);

  ASSERT_EQ(g_pair, g_pair_expected);
}

TEST(Translation, convert_matrix_to_vec_vec) {
  std::vector<std::vector<int>> g_matrix = {
      {0, 1, 1, 0, 1, 0},  // v0
      {1, 1, 1, 0, 0, 0},  // v1
      {0, 0, 1, 0, 0, 0},  // v2
      {0, 0, 0, 0, 0, 0},  // v3
      {0, 0, 0, 0, 0, 0},  // v4
      {0, 0, 0, 0, 0, 0},  // v5
  };

  std::vector<std::vector<int>> g_vec_expected = {
      {1, 2, 4},  // v0
      {0, 1, 2},  // v1
      {2},        // v2
      {},         // v3
      {},         // v4
      {},         // v5
  };

  std::vector<std::vector<int>> g_vec = convert_matrix_to_vec_vec(g_matrix);

  ASSERT_EQ(g_vec, g_vec_expected);
}

TEST(Translation, convert_vec_pair_to_vec_vec) {
  std::vector<std::pair<int, int>> g_pair = {{0, 1}, {0, 2}, {0, 4}, {1, 0},
                                             {1, 1}, {1, 2}, {2, 2}};

  std::vector<std::vector<int>> g_vec_expected = {
      {1, 2, 4},  // v0
      {0, 1, 2},  // v1
      {2},        // v2
      {},         // v3
      {},         // v4
      {},         // v5
      {}          // v6
  };

  std::vector<std::vector<int>> g_vec = convert_vec_pair_to_vec_vec(g_pair);

  ASSERT_EQ(g_vec, g_vec_expected);
}

TEST(Translation, convert_matrix_to_vec_set) {
  std::vector<std::vector<int>> g_matrix = {
      {0, 1, 1, 0, 1, 0},  // v0
      {1, 1, 1, 0, 0, 0},  // v1
      {0, 0, 1, 0, 0, 0},  // v2
      {0, 0, 0, 0, 0, 0},  // v3
      {0, 0, 0, 0, 0, 0},  // v4
      {0, 0, 0, 0, 0, 0},  // v5
  };

  std::vector<std::unordered_set<int>> g_set_expected = {
      {1, 2, 4},     // v0
      {0, 1, 2, 2},  // v1
      {2},           // v2
      {},            // v3
      {},            // v4
      {},            // v5
  };

  std::vector<std::unordered_set<int>> g_set =
      convert_matrix_to_vec_set(g_matrix);

  ASSERT_EQ(g_set, g_set_expected);
}

TEST(Translation, convert_vec_pair_to_matrix) {
  std::vector<std::pair<int, int>> g_pair = {{0, 1}, {0, 2}, {0, 4},
                                             {1, 0}, {1, 1}, {1, 2}};

  std::vector<std::vector<int>> g_matrix_expected = {
      {0, 1, 1, 0, 1, 0},  // v0
      {1, 1, 1, 0, 0, 0},  // v1
      {0, 0, 0, 0, 0, 0},  // v2
      {0, 0, 0, 0, 0, 0},  // v3
      {0, 0, 0, 0, 0, 0},  // v4
      {0, 0, 0, 0, 0, 0},  // v5
  };

  std::vector<std::vector<int>> g_matrix = convert_vec_pair_to_matrix(g_pair);

  ASSERT_EQ(g_matrix, g_matrix_expected);
}

TEST(Translation, convert_matrix_to_vec_pair) {
  std::vector<std::vector<int>> g_matrix = {
      {0, 1, 1, 0, 1, 0},  // v0
      {1, 1, 1, 0, 0, 0},  // v1
      {0, 0, 0, 0, 0, 0},  // v2
      {0, 0, 0, 0, 0, 0},  // v3
      {0, 0, 0, 0, 0, 0},  // v4
      {0, 0, 0, 0, 0, 0},  // v5
  };

  std::vector<std::pair<int, int>> g_pair_expected = {{0, 1}, {0, 2}, {0, 4},
                                                      {1, 0}, {1, 1}, {1, 2}};

  std::vector<std::pair<int, int>> g_pair =
      convert_matrix_to_vec_pair(g_matrix);

  ASSERT_EQ(g_pair, g_pair_expected);
}

TEST(Translation, convert_vec_pair_to_vec_set) {
  std::vector<std::pair<int, int>> g_pair = {{0, 1}, {0, 2}, {0, 4},
                                             {1, 0}, {1, 1}, {1, 2}};

  std::vector<std::unordered_set<int>> g_set_expected = {
      {1, 2, 4},     // v0
      {0, 1, 2, 2},  // v1
      {},            // v2
      {},            // v3
      {},            // v4
      {},            // v5
  };

  std::vector<std::unordered_set<int>> g_set =
      convert_vec_pair_to_vec_set(g_pair);

  ASSERT_EQ(g_set, g_set_expected);
}

TEST(Translation, convert_vec_set_to_vec_pair) {
  std::vector<std::unordered_set<int>> g_set = {
      {4, 2, 1},  // v0
      {2, 1, 0},  // v1
      {},         // v2
      {},         // v3
      {},         // v4
      {},         // v5
  };

  std::vector<std::pair<int, int>> g_pair_expected = {{0, 1}, {0, 2}, {0, 4},
                                                      {1, 0}, {1, 1}, {1, 2}};

  std::vector<std::pair<int, int>> g_pair = convert_vec_set_to_vec_pair(g_set);

  ASSERT_EQ(g_pair, g_pair_expected);
}
