#include <iostream>
#include <chrono>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int valor;
    cout << "Digite um valor para descobrir as notas: ";
    cin >> valor;

    int notas[6]{100, 50, 20, 10, 5, 1};

    for (int i{0}; i < 6; ++i)
    {
        int temp{valor / notas[i]};
        if (temp > 0)
        {
            cout << temp << " notas de " << notas[i] << endl;
            valor -= temp * notas[i];
        }
    }
}