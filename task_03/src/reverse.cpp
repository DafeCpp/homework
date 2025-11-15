#include "reverse.hpp"

void Reverse(double *array, int len) {
    for(auto i{0}; int(i<len/2); i++) {
        double old_el = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = old_el;
    }
}