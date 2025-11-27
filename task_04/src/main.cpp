#include <iostream>
#include "shift_right.hpp"


int main()
{
    int arr1[5] {1,2, 3, 4, 5};
    int right_answer1[5] {4, 1, 2, 3};
    int* answer1 = return_sh_array(arr1, 5, 1);

    std::cout << "Array: {";

    for (size_t i = 0; i < 5; i++)
    {
        
        std::cout << answer1[i] << ", ";
    }

    std::cout << "}";
    
}
