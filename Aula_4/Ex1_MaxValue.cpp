#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main(){

    const int lenLista {9};

    int lista[lenLista] {0, 4, 5, 1, 6, 2, 7, 15};

/*
    Forma 1:
*/
    int maxAtual = lista[0];

    for (int elemento : lista)
    {   
        if ( elemento > maxAtual) 
        {
            maxAtual = elemento;
        }
    }

    cout << maxAtual << endl;


/*
    Forma 2:
*/
    int maxAtual2 = lista[0];

    for (int j {0}; j < lenLista; j++)
    {   
        if ( lista[j] > maxAtual2) 
        {
            maxAtual2 = lista[j];
        }
    }

    cout << maxAtual2 << endl;


    return 0;
}