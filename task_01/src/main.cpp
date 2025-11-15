#include "mediana.hpp"

#include <iostream>

int main() 
try
{
    setlocale(LC_ALL, "RU");

	return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
