
#include <gtest/gtest.h>

#include <vector>

#include "reverse.hpp"

TEST(Reverse, normal) {
  std ::vector<int> a{1, 2, 3, 4};
  std ::vector<int> b{4, 3, 2, 1};
  std::vector<int> *pa = &a;
  Reverse(pa, a.size());
  ASSERT_EQ(a, b);
}

TEST(Reverse, bellow_zero) {
  std ::vector<int> a{-5, -3, -10};
  std ::vector<int> b{-10, -3, -5};
  std::vector<int> *pa = &a;
  Reverse(pa, a.size());
  ASSERT_EQ(a, b);
}
