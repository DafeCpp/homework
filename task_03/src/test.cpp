
#include <gtest/gtest.h>

#include "reverse.hpp"


int arr1[4] {1,2, 3, 4};
int right_answer1[4] {4, 3, 2, 1};
int* answer1 = return_re_array(arr1, 4);

TEST(Revese, Simple1) { ASSERT_EQ(_arrays_equality(answer1, right_answer1, 4), true); }


int arr2[5] {5, 5, 5, 5, 5};
int right_answer2[5] {5, 5, 5, 5, 5};
int* answer2 = return_re_array(arr2, 5);

TEST(Revese, Simple2) { ASSERT_EQ(_arrays_equality(answer2, right_answer2, 5), true); }

int arr3[6] {0, 1, 0, 1, 0, 1};
int right_answer3[6] {1, 0, 1, 0, 1, 0};
int* answer3 = return_re_array(arr3, 6);

TEST(Revese, Simple3) { ASSERT_EQ(_arrays_equality(answer3, right_answer3, 6), true); }

int arr4[5] {1, 4, 9, 16, 25};
int bad_answer1[5] {25, 16, 9, 4, 10000};
int* answer4 = return_re_array(arr4, 5);

TEST(Revese, SimpleError1) { ASSERT_EQ(_arrays_equality(answer4, bad_answer1, 5), false); }

int arr5[5] {1, 4, 9, 16, 25};
int bad_answer5[5] {1, 4, 9, 16, 25};
int* answer5 = return_re_array(arr5, 5);

TEST(Revese, SimpleError2) { ASSERT_EQ(_arrays_equality(answer4, bad_answer1, 5), false); }


// TEST(Revese, WHAT) { ASSERT_EQ(answer3, right_answer3); } У одинаковых массивов разные адреса
