#include <iostream>
#include "shift.hpp"

int main() 
try
{
    setlocale(LC_ALL, "RU");

    int array[5]{ 1, 2, 3, 4, 5};
    size_t len = 5;
    unsigned int N = 2;
    
    shift(array, len, N);

    std::cout << "Сдвинутый  массив:" << std::endl;

    for (int i{ 0 }; i < len; i++)
        std::cout << array[i] << " ";
	
    return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
