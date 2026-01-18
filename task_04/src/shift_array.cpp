#include <shift_array.h>
void shift_array(int* a, int size, int N)
{
    int tmp = a[size - 1];
    int* buff = new int[N];
    for (int i = size - N; i < size; i++)
        buff[i - size + N] = a[i];
    for (int i = size - 1; i >= 0; i--)
    {
        a[i] = a[(i + N) % size];
    }
    for (int i = 0; i < N; i++)
    {
        a[i] = buff[i];
    }
    delete buff;
}