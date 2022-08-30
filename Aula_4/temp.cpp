#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    char opt {};
    do
    {
        double width {}, height {};
        cout << "Digite a largura e altura separadas por espaço: ";
        cin >> width >> height;
        cout << "A área é: " << width * height << endl;

        cout << "Calcular novamente? (S/N): ";
        cin >> opt;
        cout << endl << opt << endl;

    } while (opt == 'S' || opt == 's');
    return 0;
}