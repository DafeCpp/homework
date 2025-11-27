#include <gtest/gtest.h>
#include "max_arr.hpp"

int arr1[4] {1,2, 3, 4};
int* pa1 = &arr1[0];

int arr2[10] {1, 3, 7, 1, 15, 2, 9, 10, 10, 3};
int* pa2 = &arr2[0];

int arr3[6] {-9, -6, -7, -15, -60, -25};
int* pa3 = &arr3[0];

int arr4[1] {12};
int* pa4 = &arr4[0];

int arr5[3] {-9999999, -9999999, 1};
int* pa5 = &arr5[0];

TEST(Max_Arr, Simple1) { ASSERT_EQ(max_arr(pa1, 4), 4); }

TEST(Max_Arr, Simple2) { ASSERT_EQ(max_arr(pa2, 10), 15); }

TEST(Max_Arr, Simple3) { ASSERT_EQ(max_arr(pa3, 5), -6); }

TEST(Max_Arr, Simple4) { ASSERT_EQ(max_arr(pa4, 1), 12); }

TEST(Max_Arr, Simple5) { ASSERT_EQ(max_arr(pa5, 3), 1); }