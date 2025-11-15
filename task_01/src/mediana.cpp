#include "mediana.hpp"
#include <vector>

int mediana(int a, int b, int c) {
	int m{-999999999};
    int n{999999999};

    std::vector<int> vec {a, b, c};
    for (int i=0; i<3; i++)
    {
        if (vec[i]>m)
            m=vec[i];
    }

    for (int i=0; i<3; i++)
    {
        if (vec[i]<n)
            n=vec[i];
    }

    int res = (a + b + c) - (m + n);
    return res;
}