#include <iostream>
#include <chrono>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;

unsigned long fib(unsigned long n){
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int ELEVA(int x, int n){
    if (n == 1) return x;
    return ELEVA(x*x, n-1);
}

int main() 
{
    cout << ELEVA(2,4) << endl;

    return 0;
}