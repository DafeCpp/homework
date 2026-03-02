#include <gtest/gtest.h>

#include <offsetter.hpp>

TEST(task4, normal1) {
  std ::vector<int> a{7, 32, 15, 0, 67, 1, 67, 90};
  std ::vector<int> b{15, 0, 67, 1, 67, 90, 7, 32};
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 6);
  ASSERT_EQ(a, b);
}

TEST(task4, cycle1) {
  std ::vector<int> a{7, 32, 15, 0, 67, 1, 67, 90};
  std ::vector<int> b{15, 0, 67, 1, 67, 90, 7, 32};
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 6);
  ASSERT_EQ(a, b);
}

TEST(task4, cycle2) {
  std ::vector<int> a{7, 32, 15, 0, 67, 1, 67, 90};
  std ::vector<int> b{15, 0, 67, 1, 67, 90, 7, 32};
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 6);
  ASSERT_EQ(a, b);
}

TEST(task4, normal2) {
  std ::vector<int> a{5, 19, 4, 72, 85, 1, 4, 6};
  std ::vector<int> b{1, 4, 6, 5, 19, 4, 72, 85};
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 11);
  ASSERT_EQ(a, b);
}

TEST(task4, bellow_zero) {
  std ::vector<int> a{-1, 3, 5, 10, -8};
  std ::vector<int> b{10, -8, -1, 3, 5};
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 2);
  ASSERT_EQ(a, b);
}

TEST(task4, big_test1) {
  std ::vector<int> a{};
  for (int i{0}; i < 100; ++i) a.push_back(11);
  std ::vector<int> b = a;
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 1);
  ASSERT_EQ(b, a);
}

TEST(task4, big_test2) {
  std ::vector<int> a{};
  for (int i{0}; i < 10000; ++i) a.push_back(11);
  std ::vector<int> b = a;
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 100);
  ASSERT_EQ(b, a);
}

TEST(task4, big_test3) {
  std ::vector<int> a{};
  for (int i{0}; i < 1000000; ++i) a.push_back(11);
  std ::vector<int> b = a;
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 1000);
  ASSERT_EQ(b, a);
}

TEST(task4, big_test4) {
  std ::vector<int> a{};
  for (int i{0}; i < 10000000; ++i) a.push_back(11);
  std ::vector<int> b = a;
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 10000000);
  ASSERT_EQ(b, a);
}

TEST(task4, big_test_final) {
  std ::vector<int> a{};
  for (int i{0}; i < 100000000; ++i) a.push_back(11);
  std ::vector<int> b = a;
  std::vector<int> *pa = &a;
  offsetter(pa, a.size(), 1000000000);
  ASSERT_EQ(b, a);
}