#include "offsetter.hpp"

void offsetter(std::vector<int> *array, size_t len, int n) {
  std::vector<int> memory = (*array);
  if (n >= len) {
    n = n - len;
  }
  for (unsigned int i{0}; i < len; ++i) {
    if (i < n) {
      (*array)[i] = memory[len - n + i];
    } else {
      (*array)[i] = memory[i - n];
    }
  }
}