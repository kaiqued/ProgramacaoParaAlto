#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
    
    string s1 {"Insper"};
    s1 += " Quatá, 200";

    for (char c: s1)
        cout << c << endl;
    

    return 0;
}