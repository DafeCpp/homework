#include <get_max.h>
int get_max(int* a, int size)
{
    int max_el = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] > max_el)
            max_el = a[i];
    }
    return max_el;
}