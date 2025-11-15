#include <gtest/gtest.h>
#include "reverse.hpp"

TEST(ReverseTests, SimpleArray)
{
    int array[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(array) / sizeof(array[0]);
    
    Reverse(array, len);
    
    EXPECT_EQ(array[0], 5);
    EXPECT_EQ(array[1], 4);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 2);
    EXPECT_EQ(array[4], 1);
}

TEST(ReverseTests, EmptyArray)
{
    int array[] = {};
    size_t len = sizeof(array) / sizeof(array[0]);

    Reverse(array, len);

    EXPECT_EQ(len, 0);
}

TEST(ReverseTests, SingleElementArray)
{
    int array[] = {42};
    size_t len = sizeof(array) / sizeof(array[0]);

    Reverse(array, len);

    EXPECT_EQ(array[0], 42);
}

TEST(ReverseTests, EvenLengthArray)
{
    int array[] = {1, 2, 3, 4};
    size_t len = sizeof(array) / sizeof(array[0]);

    Reverse(array, len);

    EXPECT_EQ(array[0], 4);
    EXPECT_EQ(array[1], 3);
    EXPECT_EQ(array[2], 2);
    EXPECT_EQ(array[3], 1);
}

TEST(ReverseTests, SameElementArray)
{
    int array[] = {5, 5, 5, 5, 5};
    size_t len = sizeof(array) / sizeof(array[0]);

    Reverse(array, len);

    EXPECT_EQ(array[0], 5);
    EXPECT_EQ(array[1], 5);
    EXPECT_EQ(array[2], 5);
    EXPECT_EQ(array[3], 5);
    EXPECT_EQ(array[4], 5);
}

TEST(ReverseTests, NegativeArray)
{
    int array[] = {-1, -2, -3, -4, -5};
    size_t len = sizeof(array) / sizeof(array[0]);

    Reverse(array, len);

    EXPECT_EQ(array[0], -5);
    EXPECT_EQ(array[1], -4);
    EXPECT_EQ(array[2], -3);
    EXPECT_EQ(array[3], -2);
    EXPECT_EQ(array[4], -1);
}
