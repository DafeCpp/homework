#include <algorithm>

inline int median(int first_number, int second_number, int third_number) {
  int mi{std::min(first_number, std::min(second_number, third_number))},
      ma{std::max(first_number, std::max(second_number, third_number))};
  return (first_number + second_number + third_number - ma - mi);
}