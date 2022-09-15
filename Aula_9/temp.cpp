#include <iostream>
#include <chrono>
#include <vector>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct municipio
{
    string nome;
    string UF;
    int pop;
    municipio *prox;
};

void SwapMunicipios(municipio *M1, municipio *M2)
{
    municipio temp{ *M1 };
    *M1 = *M2;
    *M2 = temp;
}

void PrintMunicipios(municipio m[]){
    int i = 0;

    while (1){
        cout << m[i].nome << " - " << m[i].UF << " - " << m[i].pop << " - ";
        if (m[i].prox == nullptr) break;
        cout << "NEXT: " << (*m[i].prox).nome << endl;
        i++;
    }
    cout << endl;
}

void bubbleSort(municipio A[], int n){
    for ( int i=0; i <= n-2; i++ ){
        for ( int j=0; j <= n-2; j++ ){
            if (A[j].pop > A[j+1].pop ){
                SwapMunicipios(&A[j], &A[j+1]);
            }
        }
    }

}

int main()
{

    municipio estado[8];

    estado[0].nome = "São Paulo";
    estado[0].UF = "SP";
    estado[0].pop = 999999999;
    estado[0].prox = &estado[1];

    estado[1].nome = "Taquarituba";
    estado[1].UF = "TA";
    estado[1].pop = 999999;
    estado[1].prox = &estado[2];

    estado[2].nome = "São João de Meretim";
    estado[2].UF = "SJ";
    estado[2].pop = 999;
    estado[2].prox = nullptr;


    PrintMunicipios(estado);
    

    return 0;
}

