
#include <gtest/gtest.h>

#include "invert_array.h"

int test_in[]={1, 2, 3, 4, 5};
int test_out[] = {5, 4, 3, 2, 1};
invert(test_in, 5);
TEST(Reverse, Simple) {
    for(i=0; i<5; i++){
    ASSERT_EQ(test_in[i], test_out[i]);
    }
    }
