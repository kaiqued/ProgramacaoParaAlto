#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {


    /*
     * 1. Memory leak (Memória alocada e não liberada)
     */
    // O código abaixo aloca dinamicamente um array de double
    size_t size_array{0};
    double *array_ptr {nullptr};

    cout << "Entre o tamanho do array? ";
    cin >> size_array;

    array_ptr = new double[size_array];
    cout << "Endereço da array: " << array_ptr << endl;

    //array_ptr = nullptr; // Se você fizer isso, não conseguirá liberar a memória.
    
    delete [] array_ptr;

    /*
     * 2. Exercício: Faça um programa para trocar o conteúdo de duas variáveis
     *          utilizando ponteiros
     */
    
    /*
     * 3. Exercício: Faça um programa para imprir o conteúdo de um array
     *          utilizando ponteiros. Não esqueça de informar o tamanho do array
     */
    
    /*
     * 4. Exercício: Faça um programa para mudar um texto em um CString para maiúsculo
     *          utilizando ponteiros. Lembre que um CString sempre termina com \0
     *          Não esqueça de informar o tamanho do array
     */
    
    /*
     * 5. Exercício: Transforme o programa 1. em uma função para criar um array,.
     *          inicializando com um valor. Consulte as notas de aula entender como fazê-lo.
     *          Utilize o programa para imprir o conteúdo de um array e
     *          utilizando ponteiros. Não esqueça de informar o tamanho do array
     */

    /*
     * 6. Diferença entre referência (&) e ponteiro (*): Analise o código abaixo
     */
    vector<string> nomes {"Fulano", "Beltrano", "Cicrano"};

    for (auto str: nomes)
        str = "Sem_nome"; // Todos os nomes irão mudar? Por quê?

    cout << nomes[0] << " " << nomes[1] << " " << nomes[2] << endl;

    for (auto &str: nomes)
        str = "Sem_nome"; // E agora? Todos os nomes irão mudar? Por quê?

    cout << nomes[0] << " " << nomes[1] << " " << nomes[2] << endl;

    return 0;
}
