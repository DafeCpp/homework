#include <gtest/gtest.h>
#include "maximum.h"

double sp[] {1, 23 ,4, 234, 34, 4322, 0, -14};
double *ptr = {sp};

TEST(Test, Simple) {
    ASSERT_EQ(maximum(ptr,3), 23);
    ASSERT_EQ(maximum(ptr,30), 4322);
    ASSERT_EQ(maximum(ptr,1), 1);
    ASSERT_EQ(maximum(ptr,5), 234);
}
