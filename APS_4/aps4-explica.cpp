#include <iostream>
#include <iomanip>
#include <thread>
#include <string>
#include <random>

using namespace std;

void print_fila(double *fila, size_t n, int DeltaT); // Imprime a fila

int main(){
    int numeroRepeticoes {10000};

    cout << "Minutes| Queue" << endl;

    // Variáveis para geração de números randômicos
    std::random_device rd;
    std::default_random_engine g;
    g.seed( rd() );
    normal_distribution<double> chegadas(5.0,1.0); // Chega 5 pessoas por minuto
    normal_distribution<double> atendimento1(6.0,5.0); // São atendidos 6 pessoas por minuto (std=5, há atendimentos muito rápidos e muito lentos)


    double avg_filas[60]{0.0};
    double tempo_ocioso[60]{0.0};


    for (int i=0; i<numeroRepeticoes; i++){
        
        // Variáveis para controle da fila
        double fila[60]{0.0};
        double atendido{0.0};
        
        // Ciclo principal
        for (int t{1}; t<60; ++t){
            fila[t] = fila[t-1] + chegadas(g); // Chegada na fila
            atendido = min(max(atendimento1(g),0.0), fila[t]); // Números atendidos na fila
            fila[t] -= atendido; // Reduz fila

            avg_filas[t] += fila[t];

            if (fila[t] == 0){

            }
        }

        // Imprime a fila
        // print_fila(fila, 60, 1);
    }

    // Calcular a média
    for (size_t i{1}; i<60; i++){
        avg_filas[i] = avg_filas[i]/numeroRepeticoes;
        cout << i << " = " << avg_filas[i] << endl;

    }

    return 0;
}

void print_fila(double *fila, size_t n, int DeltaT){

    for (size_t i{0}; i<n; i += DeltaT) {
        double avg_time{0};
        for (size_t k{i}; k<i+DeltaT; ++k){
            avg_time += fila[i];
        }
        cout << setw(4) << i << "-" << setw(2) << (i+DeltaT) << "| ";
        cout << string(static_cast<int>(avg_time/DeltaT),'*') << endl;
    }
    cout << string(30,'-') << endl;
}