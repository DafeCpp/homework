#include <ranges>
#include <gtest/gtest.h>

#include "reverse.hpp"

double sp[] {1, 23, 4, 234, 34, 4322, 0, -14};
double sp_mod[] {-14, 0, 4322, 34, 234, 4, 23, 1};
double sp2[] {1, 23, 4, 5, 7};
double sp_mod2[] {7, 5, 4, 23, 1};


TEST(Reverse, Simple) {
    Reverse(sp, 8);
    for (int i{0}; i < 8; i++) {
        ASSERT_EQ(sp[i], sp_mod[i]);
    }
    Reverse(sp2, 5);
    for (int i{0}; i < 5; i++) {
        ASSERT_EQ(sp2[i], sp_mod2[i]);
    }
}
