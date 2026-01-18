#include <vector>
#include <string>

struct array_error{
  std :: string message {"array errror"};
};

inline std::vector<int> Reverse (std::vector<int> arr, int length) {
  if (length <1)
    throw array_error {};
  
  std :: vector <int> rev_arr {};
  for (int i{length-1}; i>=0; --i) 
    rev_arr.push_back (arr[i]);
  
  return rev_arr;
}