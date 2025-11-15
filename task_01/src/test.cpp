#include <gtest/gtest.h>

#include "mediana.hpp"

TEST(Mediana, Simple1) { EXPECT_EQ(mediana(1, 2, 3), 2); }
TEST(Mediana, Simple2) { EXPECT_EQ(mediana(-1, 2, 3), 2); }
TEST(Mediana, Simple3) { EXPECT_EQ(mediana(123, 22, 32345), 123); }
TEST(Mediana, Simple4) { EXPECT_EQ(mediana(1, 3, 3), 3); }
TEST(Mediana, Simple5) { ASSERT_EQ(mediana(1, 2, 3), 2); }
TEST(Mediana, Simple6) { ASSERT_EQ(mediana(1, 1, 1), 1); }
TEST(Mediana, Simple7) { ASSERT_EQ(mediana(-10, 0, 10), 0); }
TEST(Mediana, Simple8) { ASSERT_EQ(mediana(-3, -2, -1), -2); }
TEST(Mediana, Simple9) { ASSERT_EQ(mediana(2, 2, 3), 2); }

