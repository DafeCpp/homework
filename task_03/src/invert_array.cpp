#include <invert_array.h>
void invert_array(int* a, int size)
{
    for (int i = 0; i < size/2; i++)
    {
        int tmp = a[i];
        a[i] = a[size - i - 1];
        a[size - i] = tmp;
    }
}