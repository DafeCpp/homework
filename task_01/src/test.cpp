#include <gtest/gtest.h>

#include <sum.hpp>

TEST(Test, Simple) { ASSERT_EQ(Sum(1, 2, 3), 6); }