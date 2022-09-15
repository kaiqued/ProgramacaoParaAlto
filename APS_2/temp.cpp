#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main() {
    string line;
    ifstream myfile ("./APS_2/Municipios.txt");

    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 

    return 0;
}