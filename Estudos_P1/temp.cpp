#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int Somatorio(int n){
    if (n > 0) return (Somatorio(n-1)+n);
    return n;
}

int ELEVA(int x, int n){
    if (n == 1) return x;
    return ELEVA(x*x, n-1);
}
int main() {

    int n{0};
    cout << "Digite um número inteiro: ";

    cin >> n;
    cout << Somatorio(n) << endl;

    return 0;
}