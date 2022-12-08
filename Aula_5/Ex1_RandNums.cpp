#include <cstdlib>
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
    std::srand(std::time(nullptr));
    
    for (int i {0}; i<10; i++)
    {
        cout << (rand()%1000)/1000.0 << ' ';
    }

    cout << endl;
    return 0;
}