#include <cstddef>

void shift(int* array, size_t& len, unsigned int& N)
{
    if (len == 0) return;

    N = N % len; 
    if (N == 0) return;

    for (size_t i = 0; i < N; ++i)
    {
        int temp = array[len - 1];
        for (size_t j = len - 1; j > 0; --j)
        {
            array[j] = array[j - 1];
        }
        array[0] = temp;
    }
}
