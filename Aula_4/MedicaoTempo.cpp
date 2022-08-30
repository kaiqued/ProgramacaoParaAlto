#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

int main(){
    using namespace std::chrono;


    const int lenLista {14};

    int lista[lenLista] {0, 4, 5, 1, 6, 13, 35, 521, 1, 52, 555, 2, 7, 15};


/*
    Forma 1:
*/
    high_resolution_clock::time_point tOp1_1 = high_resolution_clock::now();


    int maxAtual = lista[0];

    for (int elemento : lista)
    {   
        if ( elemento > maxAtual) 
        {
            maxAtual = elemento;
        }
    }

    high_resolution_clock::time_point tOp1_2 = high_resolution_clock::now();
    duration<double, std::milli> tempoOp1 = tOp1_2 - tOp1_1;

    high_resolution_clock::time_point tOp2_1 = high_resolution_clock::now();

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


    high_resolution_clock::time_point tOp2_2 = high_resolution_clock::now();
    duration<double, std::milli> tempoOp2 = tOp2_2-tOp2_1;

    cout << "Tempo da operação 1:" << tempoOp1.count() << "ms" << endl;
    cout << "Tempo da operação 2:" << tempoOp2.count() << "ms" << endl;

    return 0;
}