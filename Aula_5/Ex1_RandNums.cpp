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
        cout << rand()%10 << ' ';
    }

    cout << endl;
    return 0;
}