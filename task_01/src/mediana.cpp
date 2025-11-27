#include "mediana.hpp"

int _max(int first_number, int second_number)
{
    return first_number >= second_number ? first_number : second_number;
}

int _min(int first_number, int second_number)
{
    return first_number <= second_number ? first_number : second_number;
}



int mediana(int first_number, int second_number, int third_number)
{
    int maxx = _max(first_number, second_number);
    maxx = _max(maxx, third_number);

    int minn = _min(first_number, second_number);
    minn = _min(minn, third_number);

    int summ = first_number + second_number + third_number;

    return summ - (maxx + minn); 
}