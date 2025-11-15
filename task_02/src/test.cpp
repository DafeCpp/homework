#include <gtest/gtest.h>
#include "max_element.hpp"

TEST(MaxElementTests, PositiveArray)
{
    int array[] = {1, 3, 5, 7, 9};
    int size = sizeof(array) / sizeof(array[0]);
    EXPECT_EQ(get_max_element(array, size), 9);
}

TEST(MaxElementTests, NegativeArray)
{
    int array[] = {-1, -3, -5, -7, -9};
    int size = sizeof(array) / sizeof(array[0]);
    EXPECT_EQ(get_max_element(array, size), -1);
}

TEST(MaxElementTests, MixedArray)
{
    int array[] = {-1, 2, -3, 4, -5};
    int size = sizeof(array) / sizeof(array[0]);
    EXPECT_EQ(get_max_element(array, size), 4);
}

TEST(MaxElementTests, SingleElementArray)
{
    int array[] = {42};
    int size = sizeof(array) / sizeof(array[0]);
    EXPECT_EQ(get_max_element(array, size), 42);
}

TEST(MaxElementTests, SameElementArray)
{
    int array[] = {5, 5, 5, 5, 5};
    int size = sizeof(array) / sizeof(array[0]);
    EXPECT_EQ(get_max_element(array, size), 5);
}
