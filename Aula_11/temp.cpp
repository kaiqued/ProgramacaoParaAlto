#include <iostream>
#include <chrono>
#include <vector>
#include <string.h>

using namespace std;

struct municipio
{
    string nome;
    int pop;
    municipio *prox;
};

void inserirItem(municipio *&head, string nome, int pop){

    municipio *novo;
    novo = new municipio;
    novo->nome = nome;
    novo->pop  = pop;
    novo->prox = nullptr;

    if (head == nullptr){
        head = novo;
    }
    else{
        municipio *m {head};
        while(m->prox != nullptr){
            m = m->prox;
        }
        m -> prox = novo;
    }
}

void imprimirMunicipios(municipio *&head){
    municipio *m{head};
    while(m != nullptr){ // Também funciona while(! m)
        cout << m->nome << ": " << m->pop << endl;
        m = m->prox;
    }
}

void apagarUltimo(municipio *&head){
    municipio *m{head};
    while(m->prox != nullptr){
        m = m->prox;
    }
    cout << m->nome;
}

int main()
{
    
    municipio *head{nullptr};
    
    inserirItem(head, "Nova Cidade", 123);
    inserirItem(head, "Taquarituba", 444);
    inserirItem(head, "Pedro Sampaio", 555);

    apagarUltimo(head);

    // imprimirMunicipios(head);


    

    

    return 0;
}

