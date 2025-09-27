#include <bits/atomic_wait.h>
#include <iostream>

#include "utils.hpp"

int main() {
  utils::IntArray a(10);

  for (int i = 0; i < a.GetSize(); ++i) {
    a[i] = i;
  }

  int sum = 0;
  for (int i = 0; i < a.GetSize(); ++i) {
    sum += a[i];
  }

  std::cout << sum << '\n';

  utils::IntArray adda;
  utils::IntArray b(1, 1);

  { utils::IntArray a; }

  return 0;
}
