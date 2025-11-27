#include "shift_right.hpp"

bool _arrays_equality(int* array1, int* array2, const size_t& len)
{
    // Функция для проверки равенства массивов
    
    int* pa1 = array1;
    int* pa2 = array2;

    size_t it{0};

    while (it < len)
    {

        if (pa1[it] == pa2[it]) ++it;

        else return false;
    }

    return true;
}

void Shift_right(int* array, const size_t& len, const unsigned int& N)
{
    int* _array = new int[len];

    size_t max_it = len - 1;
    
    for (size_t it{0}; it < len; ++it)
    {
        if (it < N)
            _array[it] = array[len - N + it];
        else
            _array[it] = array[it - N]; 
    }

    for (size_t i{0}; i < len; ++i)
        array[i] = _array[i];
    
    delete[] _array;

}

int* return_sh_array(int* array, const size_t& len, const size_t& N)
{
    // Дополнительную функцию для того, чтобы написать тесты
    // для функции Shift_right, которая возвращает void

    Shift_right(array, len, N);

    return array;
}