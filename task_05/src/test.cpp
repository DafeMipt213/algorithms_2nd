
#include <gtest/gtest.h>
#include <RMQ.hpp>

TEST(RMQ, Test1) {
  std::vector<int> vec = {1, 0, 4, 3, 5, 10};
  std::vector< std::vector<int> > vec2D = table_construct(vec.size(), vec);
  ASSERT_EQ(RMQ(1, 7, vec2D), 0);
}

TEST(RMQ, Test2) {
  std::vector<int> vec = {14, 11, 13, 9, 7, 4, 10, 2, 5, 3};
  std::vector< std::vector<int> > vec2D = table_construct(vec.size(), vec);
  ASSERT_EQ(RMQ(1, 8, vec2D), 2);
}

TEST(RMQ, Test3) {
  std::vector<int> vec = {25, 16, 31, 50 ,5 ,21};
  std::vector< std::vector<int> > vec2D = table_construct(vec.size(), vec);
  ASSERT_EQ(RMQ(4, 6, vec2D), 5);
}



TEST(RMQ, Test_check_for_bad_input) {
  std::vector<int> vec = {14, 11, 13, 9, 7, 4, 10, 2, 5, 3};
  std::vector< std::vector<int> > vec2D = table_construct(vec.size(), vec);
  ASSERT_ANY_THROW(RMQ(-1, 8, vec2D));
}

TEST(RMQ, Empty_vector) {
  std::vector<int> vec = {};
  std::vector< std::vector<int> > vec2D = table_construct(vec.size(), vec);
  ASSERT_ANY_THROW(RMQ(1, 8, vec2D));
}