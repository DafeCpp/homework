#include <vector>
#include <string>
#include <algorithm>

struct array_error{
  std :: string message {"array error"}; 
};

inline int max_value(std :: vector <int> arr, int length) {
  if (length < 1)
    throw array_error {};

  int max_val = {arr[0]};
  for (auto num:arr) {
    max_val = std::max(max_val, num);
  }

  return max_val;
}