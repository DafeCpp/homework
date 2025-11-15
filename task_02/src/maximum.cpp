#include "maximum.h"

double maximum(double *ptr, const int size) {
    double maximum = *ptr;
    for(auto i{1}; i < size; i++) {
        if (maximum < *(ptr + i))
            maximum = *(ptr + i);
    }
    return maximum;
}