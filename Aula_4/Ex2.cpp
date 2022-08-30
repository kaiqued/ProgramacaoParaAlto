#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main(){

    const int lenLista {4};

    int lista[lenLista] {1, 4, 5, 8};

    int aSum {0};

/*
    Forma 1:
*/
    for (int i {0}; i < lenLista-1; i++)
    {
        for (int j {i+1}; j < lenLista; j++)
        {
            aSum += abs(lista[i] - lista[j]);
        }
    }

    cout << aSum << endl;

    return 0;
}