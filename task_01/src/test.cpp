#include <gtest/gtest.h>

#include "mediana.hpp"

TEST(Mediana, Simple1) { ASSERT_EQ(mediana(1, 2, 3), 2); }
TEST(Mediana, Simple2) { ASSERT_EQ(mediana(1, 1, 1), 1); }
TEST(Mediana, Simple3) { ASSERT_EQ(mediana(-10, 0, 10), 0); }
TEST(Mediana, Simple4) { ASSERT_EQ(mediana(-3, -2, -1), -2); }
TEST(Mediana, Simple5) { ASSERT_EQ(mediana(2, 2, 3), 2); }
TEST(Mediana, Simple6) { ASSERT_EQ(mediana(1, 3, 3), 3); }
