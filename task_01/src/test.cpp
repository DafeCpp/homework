#include <gtest/gtest.h>
#include <median.h>
#include <sum.hpp>

TEST(Test, Simple) {ASSERT_EQ(median({1, 6, 4}), 4);}