#include <vector>
#include <string>

struct array_error{
  std :: string message {"array errror"};
};

inline std :: vector <int> move_array (std::vector <int> arr, int length, int N) {
    if (length < 1)
        throw array_error {};

    N = N % length;
    std :: vector <int> moved_arr = arr;
    for (int i{0}; i<N; ++i) {
        auto point = moved_arr.begin();
        moved_arr.insert(point, moved_arr[length-1]);
        moved_arr.pop_back();
    }

    return moved_arr;
}