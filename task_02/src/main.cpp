#include <iostream>
#include "max_element.hpp"

int main() 
try
{
    setlocale(LC_ALL, "RU");
    int array[] = {1, 3, 5, 7, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int res = get_max_element(array, size);
    std::cout << res;
	return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}