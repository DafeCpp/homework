#include <algorithm>
#include <vector>

inline int mediana(int first_number, int second_number, int third_number) {
  std ::vector<int> nums = {first_number, second_number, third_number};
  sort(nums.begin(), nums.end());
  return (nums[1]);
}