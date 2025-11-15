#include <gtest/gtest.h>

#include "foonk.h"

TEST(task4, normal1) {
  int a[8]{7, 32, 15, 0, 67, 1, 67, 90};
  int b[8]{15, 0, 67, 1, 67, 90, 7, 32};
  int *pa = a;
  mass(pa, 8, 6);
  ASSERT_EQ(a[0], b[0]);
  ASSERT_EQ(a[1], b[1]);
  ASSERT_EQ(a[2], b[2]);
  ASSERT_EQ(a[3], b[3]);
  ASSERT_EQ(a[4], b[4]);
  ASSERT_EQ(a[5], b[5]);
  ASSERT_EQ(a[6], b[6]);
  ASSERT_EQ(a[7], b[7]);
}