#include "reverse.hpp"

void Reverse(std::vector<int> *array, size_t len) {
  for (unsigned int i{0}; i < len / 2; ++i) {
    int mem = (*array)[i];
    (*array)[i] = (*array)[len - 1 - i];
    (*array)[len - 1 - i] = mem;
  }
}