#include "mediana.h"
#include <vector>
double mediana(double a, double b, double c) {
    double max_value = {a};
    double min_value = {a};
    std::vector numbers = {a, b, c};
    for(auto &x: numbers) {
        if (x < min_value)
            min_value = x;
        if (x>max_value)
            max_value = x;
    }
    double mediana_value = a + b + c - min_value - max_value;
    return mediana_value;
}
