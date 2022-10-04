#include <iostream>

struct vogal{
	char letra;
	vogal *prox;
};

void imprimirVogais(vogal *&head){
    vogal *m{head};

	do{
        std::cout << m->letra << std::endl;
        m = m->prox;
    }
    while(m != head);
}

int main() {
	// Alocação de memória para as vogais
	vogal *node0 = new vogal;
	vogal *node1 = new vogal;
	vogal *node2 = new vogal;
	vogal *node3 = new vogal;
	vogal *node4 = new vogal;

	// Inicialização
	*node0 = {'a', node1};
	*node1 = {'e', node2};
	*node2 = {'i', node3};
	*node3 = {'o', node4};
	*node4 = {'u', node0};

	// Início da lista encadeada
	vogal *head{node0};

	imprimirVogais(head);

	// Desaloca a memória 
	delete node0;
	delete node1;
	delete node2;
	delete node3;
	delete node4;

	return 0;
}
