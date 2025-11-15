#include <gtest/gtest.h>
#include <vector>

#include "fun.h"

TEST(maxmass, normal) {
  std::vector<int> a{1, 2, 3, 4};
  ASSERT_EQ(mass(a, 4), 4);
}

TEST(maxmass, unsorted) {
  std::vector<int> a{5, 16, 7, 48, 3, 13};
  ASSERT_EQ(mass(a, 6), 48);
}
