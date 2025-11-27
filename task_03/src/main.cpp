#include <iostream>
#include "reverse.hpp"

// Тестирование функции _arrays_equality

int main()
{
    int arr_1[4] {1, 2, 3, 4};
    int arr_2[4] {1, 2, 3, 4};
    int arr_error [4] {4, 2, 3, 4};

    int arr4[5] {1, 4, 9, 16, 25};
    int right_answer4[5] {25, 16, 9, 4, 1};
    int* answer4 = return_re_array(arr4, 5);
    
    std::cout << "True: " << true << std::endl;
    std::cout << _arrays_equality(arr_1, arr_2, 4) << std::endl;
    std::cout << _arrays_equality(answer4, right_answer4, 5) << std::endl;

    std::cout << "False: " << false << std::endl;
    std::cout << _arrays_equality(arr_1, arr_error, 4) << std::endl;

}
