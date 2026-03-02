#include <algorithm>
#include <vector>

inline int max_in_vector(const std::vector<int>& vec, int len) {
  int ma{-10000000};
  for (int i{0}; i < len; ++i) {
    ma = std::max(ma, vec[i]);
  }
  return ma;
}