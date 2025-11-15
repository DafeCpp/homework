#include <gtest/gtest.h>

#include "sum.hpp"

TEST(ps, Simple1) { ASSERT_EQ(ps(1, 2, 3), 2); }
TEST(ps, Simple2) { ASSERT_EQ(ps(1, 1, 1), 1); }
TEST(ps, Simple3) { ASSERT_EQ(ps(-10, 0, 10), 0); }
TEST(ps, Simple4) { ASSERT_EQ(ps(-3, -2, -1), -2); }
TEST(ps, Simple5) { ASSERT_EQ(ps(2, 2, 3), 2); }
TEST(ps, Simple6) { ASSERT_EQ(ps(1, 3, 3), 3); }