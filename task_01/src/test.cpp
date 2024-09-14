#include <gtest/gtest.h>

#include <median.hpp>

TEST(Test, Simple) { ASSERT_EQ(Median(1, 2, 3), 6); }