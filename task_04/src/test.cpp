#include "shift.hpp"
#include <gtest/gtest.h>

// Тестовый случай для обычного массива с N < len
TEST(ShiftTests, NormalShift)
{
    int array[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(array) / sizeof(array[0]);
    unsigned int N = 2;

    shift(array, len, N);

    EXPECT_EQ(array[0], 4);
    EXPECT_EQ(array[1], 5);
    EXPECT_EQ(array[2], 1);
    EXPECT_EQ(array[3], 2);
    EXPECT_EQ(array[4], 3);
}

// Тестовый случай для сдвига на 0
TEST(ShiftTests, ZeroShift)
{
    int array[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(array) / sizeof(array[0]);
    unsigned int N = 0;

    shift(array, len, N);

    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 4);
    EXPECT_EQ(array[4], 5);
}

// Тестовый случай для сдвига на длину массива
TEST(ShiftTests, LengthShift)
{
    int array[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(array) / sizeof(array[0]);
    unsigned int N = len; // Сдвиг на длину массива

    shift(array, len, N);

    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 4);
    EXPECT_EQ(array[4], 5);
}

// Тестовый случай для сдвига больше длины массива
TEST(ShiftTests, LargeShift)
{
    int array[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(array) / sizeof(array[0]);
    unsigned int N = 7; // Сдвиг больше длины массива

    shift(array, len, N);

    EXPECT_EQ(array[0], 4);
    EXPECT_EQ(array[1], 5);
    EXPECT_EQ(array[2], 1);
    EXPECT_EQ(array[3], 2);
    EXPECT_EQ(array[4], 3);
}

// Тестовый случай для пустого массива
TEST(ShiftTests, EmptyArray)
{
    int array[] = {};
    size_t len = sizeof(array) / sizeof(array[0]);
    unsigned int N = 2;

    shift(array, len, N);

    EXPECT_EQ(len, 0); // Допускаем, что пустой массив остается пустым
}

// Тестовый случай для массива с одним элементом
TEST(ShiftTests, SingleElementArray)
{
    int array[] = {42};
    size_t len = sizeof(array) / sizeof(array[0]);
    unsigned int N = 3;

    shift(array, len, N);
}