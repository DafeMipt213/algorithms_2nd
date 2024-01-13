
#include <gtest/gtest.h>

#include "rmq.hpp"

TEST(RMQ, Simple1) {
  std::vector<double> data = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < data.size(); ++i) ASSERT_EQ(RMQ(data, i, i), data[i]);
}

TEST(RMQ, Simple2) {
  std::vector<double> data = {3, 4, 1, 2, 4, 5};
  ASSERT_EQ(RMQ(data, 0, 6), 1);
  ASSERT_EQ(RMQ(data, 5, 6), 5);
  ASSERT_EQ(RMQ(data, 0, 2), 1);
  ASSERT_EQ(RMQ(data, 0, 1), 3);
}

TEST(RMQ, Simple3) {
  std::vector<double> data = {1, 1, 1, 1, 1, 1, 1};
  ASSERT_EQ(RMQ(data, 0, 6), 1);
}

TEST(RMQ, Simple4) {
  std::vector<double> data = {
      569, 719, 762, 908, 215, 393, 154, 132, 928, 342, 925, 95,  307, 570, 63,
      627, 338, 248, 741, 930, 664, 613, 657, 948, 393, 244, 984, 427, 560, 409,
      184, 440, 868, 191, 430, 583, 922, 949, 78,  842, 990, 407, 88,  267, 714,
      661, 731, 658, 878, 895, 903, 518, 461, 185, 981, 956, 61,  814, 515, 971,
      410, 727, 572, 519, 158, 484, 228, 115, 139, 481, 706, 389, 170, 899, 941,
      257, 524, 390, 234, 732, 513, 326, 549, 665, 506, 667, 980, 682, 211, 474,
      521, 107, 433, 107, 431, 262, 835, 570, 109, 229};
  for (int i = 0; i < data.size(); ++i) ASSERT_EQ(RMQ(data, i, i), data[i]);
  ASSERT_EQ(RMQ(data, 0, 99), *std::min_element(begin(data), end(data)));
  auto end = begin(data);
  advance(end, 50);
  ASSERT_EQ(RMQ(data, 0, 49), *std::min_element(begin(data), end));
}

TEST(RMQ, SortedArray) {
  std::vector<double> data = {
      4,   16,  35,  43,  43,  63,  70,  75,  87,  99,  100, 127, 131, 135, 137,
      140, 141, 184, 189, 221, 236, 239, 243, 257, 262, 275, 282, 294, 296, 303,
      315, 317, 322, 336, 343, 344, 347, 353, 355, 364, 382, 398, 434, 446, 447,
      465, 466, 482, 487, 493, 510, 518, 525, 557, 589, 592, 623, 627, 628, 642,
      645, 650, 656, 658, 663, 679, 681, 685, 694, 701, 711, 720, 737, 738, 746,
      748, 755, 761, 778, 780, 789, 796, 805, 815, 820, 820, 832, 833, 836, 843,
      868, 878, 878, 895, 908, 927, 942, 971, 979, 988};
  auto begin = data.begin();
  for (int i = 0; i < data.size(); ++i) {
    ASSERT_EQ(RMQ(data, i, 99), *std::min_element(begin, end(data)));
    advance(begin, 1);
  }
}