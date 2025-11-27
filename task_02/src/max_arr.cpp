#include "max_arr.hpp"

int max_arr(int* pa, int length)
{
    int maxx = *pa;

    for (int i = 0; i < length; ++i)
    {
        if (*pa >= maxx) maxx = *pa;
        pa += 1;
    }

    return maxx;
}