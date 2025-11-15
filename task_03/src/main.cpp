#include "reverse.hpp"
#include <iostream>

int main() 
try
{
    setlocale(LC_ALL, "RU");

    int array[4]{ 1, 2, 3, 4 };
    int len = 4;
    
    Reverse(array, len);

    std::cout << "Инвертированный массив:" << std::endl;

    for (int i{ 0 }; i < len; i++)
        std::cout << array[i] << " ";
	
    return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
