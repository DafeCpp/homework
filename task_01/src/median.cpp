#include<median.h>
int median(int a[3]){
    sort(begin(a), end(a));
    return a[1];
}