#include <iostream>
#include <chrono>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;

void bubbleSort(vector <int> &A, int n){


    for ( int i=0; i <= n-2; i++ ){
        for ( int j=0; j <= n-2; j++ ){
            if (A.at(j) > A.at(j+1) ){
                swap(A.at(j), A.at(j+1));
            }
        }
    }
    for (int i=0; i<A.size(); i++){
        cout << "A[" << i << "] = " << A[i] << endl;
    }
    cout << endl;

}


int main() 
{
    vector <int> LISTA {4, 3, 1, 2, 0, 10, 8, 5, 9, 6, 7};

    bubbleSort(LISTA, LISTA.size());

    return 0;
}