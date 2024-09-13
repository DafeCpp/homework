
#include <gtest/gtest.h>
#include <shift_array.h>
int a[] = {1, 2, 3, 4, 5};
TEST(Shift, Simple) {
    ASSERT_EQ(get_max(a, 5), 5);
    }