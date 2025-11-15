#include "fun.h"

int mass(std::vector<int>& vec, int len) {
  int ma = vec[0];
  for (int i{1}; i < len; ++i) {
    ma = std::max(ma, vec[i]);
  }
  return ma;
}