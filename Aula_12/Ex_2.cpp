#include <iostream>
#include <chrono>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int largura{5}, altura{6};

    cout << "Digite largura e altura: ";
    cin >> largura >> altura;

    cout << "+";

    for (int i{0}; i < largura; i++)
        cout << "-";
    cout << "+" << endl;

    for (int i{0}; i < altura; i++)
    {
        cout << "|";
        for (int i{0}; i < largura; i++)
            cout << " ";
        
        cout << "|" << endl;

        
    }

    cout << "+";
    for (int i{0}; i < largura; i++)
        cout << "-";
    cout << "+" << endl;


    cout << endl;
}