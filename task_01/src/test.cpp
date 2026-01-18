#include "mediana.hpp"
#include <gtest/gtest.h>

TEST(Test, Simple) {
  ASSERT_EQ(mediana(1, 2, 3), 2);
  ASSERT_EQ(mediana(3, 13, 2), 3);
  ASSERT_EQ(mediana(3, 65, 17), 17);
  ASSERT_EQ(mediana(-2, 8, -100), -2);
  ASSERT_EQ(mediana(-5, -8, -17), -8);
}
