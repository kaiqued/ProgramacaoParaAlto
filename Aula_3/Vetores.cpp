#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main()
{
    // Criar dois vetores
    vector <int> vec1 (2);
    vector <int> vec2 (2);

    // Mostrar o tamanho dos dois
    cout << "Tamanho dos vetores:\n";
    cout << "Size vec1: " << vec1.size() << endl;
    cout << "Size vec2: " << vec2.size() << endl;

    cout << "\n";

    // Adicione os números 1 e 2 no vec1 e 11 e 12 no vec2
    vec1.push_back(1);
    vec1.push_back(2);
    
    vec2.push_back(11);
    vec2.push_back(12);

    // Mostrar os vetores
    cout << "Tamanho dos vetores atualizado:\n";
    cout << "Size vec1: " << vec1.size() << endl;

    for (int i=0; i<vec1.size(); i++){
        cout << "vec1[" << i << "] = " << vec1[i] << endl;
    }

    cout << endl;
    
    cout << "Size vec2: " << vec2.size() << endl;

    for (int i=0; i<vec2.size(); i++){
        cout << "vec2[" << i << "] = " << vec2[i] << endl;
    }

    cout << "\n\n";

    // Criar vetor vec3 bidimensional e colocar os vetores anteriores dentro
    cout << "Inicio vec3 testes: \n";
    vector <vector <int>> vec3;

    vec3.push_back(vec1);
    vec3.push_back(vec2);

    for (int i=0; i<vec3.size(); i++){
        cout << "vec3[" << i << "]: " << endl;
        for (int j=0; j<vec3[i].size(); j++){
            cout << "  " << "vec3[" << i << "][" << j << "] = ";
            cout << vec3[i][j] << endl;
        }
        cout << endl;
    }


    return 0;
}
