#include "mediana.h"
#include <iostream>

int main() {
    double a;
    double b;
    double c;
    std::cin>>a>>b>>c;
    double result = mediana(a, b, c);
    std::cout<<result;
    return 0;
}