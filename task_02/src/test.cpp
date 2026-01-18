#include <gtest/gtest.h>
#include <vector>
#include <max_value.hpp>

TEST(max_value, normal) {
  std::vector <int> a {1,2,3,4};
  ASSERT_EQ(max_value(a, 4), 4);
}

TEST(max_value, unsorted) {
  std::vector <int> a {5, 16, 7, 48, 3, 13};
  ASSERT_EQ(max_value(a, 6), 48);
}

TEST(max_value, bellow_zero) {
  std::vector <int> a {-1,-5,-6,-10,-3};
  ASSERT_EQ(max_value(a, 5), -1);
}

TEST(max_value, repeated) {
  std::vector <int> a {1,2,2,2,2,5,5,5};
  ASSERT_EQ(max_value(a, 8), 5);
}

TEST(max_value, error) {
  std::vector <int> a {7, 0, -5, 13, 14, -48, 7, 18, 17, 1, -30};
  ASSERT_THROW(max_value(a, 0), array_error);
}

TEST(max_value, all) {
  std::vector <int> a {7, 0, -5, 13, 14, -48, 7, 18, 17, 1, -30};
  ASSERT_EQ(max_value(a, 11), 18);
}