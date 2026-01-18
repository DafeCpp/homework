
#include <gtest/gtest.h>
#include <vector>
#include "reverse.hpp"

TEST(Reverse, error) {
    std :: vector <int> a {};
    ASSERT_THROW (Reverse (a, 0), array_error);
}

TEST(Reverse, normal) {
    std :: vector <int> a {1,2,3,4};
    std :: vector <int> b {4,3,2,1};
    a = Reverse (a, a.size());
    ASSERT_EQ (a, b);
}

TEST(Reverse, bellow_zero) {
    std :: vector <int> a {-5,-3,-10};
    std :: vector <int> b {-10,-3,-5};
    a = Reverse (a, a.size());
    ASSERT_EQ (a, b);
}

TEST(Reverse, repeated) {
    std :: vector <int> a {1,1,1,1};
    std :: vector <int> b {1,1,1,1};
    a = Reverse (a, a.size());
    ASSERT_EQ (a, b);
}