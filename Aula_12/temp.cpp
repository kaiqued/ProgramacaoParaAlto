#include <iostream>
#include <chrono>
#include <vector>
#include <string.h>

using namespace std;

int soma (int n){
    if (n==1)
        return 1;
    
    return n + soma(n-1);
}

int MDC (int x, int y){
    if (x > y)
        return MDC(x-y, y);
    if (x < y)
        return MDC(y, x);

    return x;
    
}

int main()
{
    cout << MDC(1000, 20) << endl;
    return 0;
}