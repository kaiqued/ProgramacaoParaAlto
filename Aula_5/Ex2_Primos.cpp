#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

bool TestaPrimo(int num)
{
    for (int i {2}; i<num; i++){
        if ( num%i == 0 ) {
            return false;
        }
    }
    return true;
}


int main() 
{   
    using namespace std::chrono;

    high_resolution_clock::time_point tInicial = high_resolution_clock::now();

    int count {0};
    for ( int i {1000}; i<= 4000; i++){
        if (TestaPrimo(i)){
            count++;
        }
    }
    
    duration<double, std::milli> tempoOp = high_resolution_clock::now() - tInicial;


    cout << "Existem " << count << " números primos entre 1000 e 4000" << endl;
    cout << "Tempo de operação: " << tempoOp.count() << " ms" << endl;
    
    cout << endl;
    return 0;
}