#include <gtest/gtest.h>

#include "shift_right.hpp"

int arr1[4] {1,2, 3, 4};
int right_answer1[4] {4, 1, 2, 3};
int* answer1 = return_sh_array(arr1, 4, 1);

TEST(Shift, Simple1) { ASSERT_EQ(_arrays_equality(answer1, right_answer1, 4), true); }


int arr2[4] {1,2, 3, 4};
int right_answer2[4] {3, 4, 1, 2};
int* answer2 = return_sh_array(arr2, 4, 2);

TEST(Shift, Simple2) { ASSERT_EQ(_arrays_equality(answer2, right_answer2, 4), true); }


int arr3[4] {1,2, 3, 4};
int right_answer3[4] {1, 2, 3, 4};
int* answer3 = return_sh_array(arr3, 4, 0);

TEST(Shift, Simple3) { ASSERT_EQ(_arrays_equality(answer3, right_answer3, 4), true); }

int arr4[5] {1, 2, 3, 4, 5};
int bad_answer4[5] {1, 2, 3, 4, 5};
int* answer4 = return_sh_array(arr4, 5, 2);

TEST(Shift, SimpleError1) { ASSERT_EQ(_arrays_equality(answer4, bad_answer4, 5), false); }

int arr5[5] {1, 2, 3, 4, 5};
int right_answer5[5] {1, 2, 3, 4, 5};
int* answer5 = return_sh_array(arr5, 5, 5);

TEST(Shift, Simple5) { ASSERT_EQ(_arrays_equality(answer5, right_answer5, 5), true); }