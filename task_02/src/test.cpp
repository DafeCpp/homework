#include <gtest/gtest.h>

#include <vector>

#include "max_in_vector.hpp"

TEST(max_value, normal) {
  std::vector<int> a{1, 2, 3, 4};
  ASSERT_EQ(max_in_vector(a, 4), 4);
}

TEST(max_value, unsorted) {
  std::vector<int> a{5, 16, 7, 48, 3, 13};
  ASSERT_EQ(max_in_vector(a, 6), 48);
}

TEST(max_value, bellow_zero) {
  std::vector<int> a{-1, -5, -6, -10, -3};
  ASSERT_EQ(max_in_vector(a, 5), -1);
}

TEST(max_value, repeated) {
  std::vector<int> a{1, 2, 2, 2, 2, 5, 5, 5};
  ASSERT_EQ(max_in_vector(a, 8), 5);
}

TEST(max_value, all) {
  std::vector<int> a{7, 0, -5, 13, 14, -48, 7, 18, 17, 1, -30};
  ASSERT_EQ(max_in_vector(a, 11), 18);
}