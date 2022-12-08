#include <iostream>

template <class T> class pilha {
    public:
		void push(T val){
			if (this->topo < 255)
				this->vals[++this->topo] = val;
			else
				std::cout << "Erro: Pilha Cheia" << std::endl;
		}

		T pop(){
			if (this->topo >= 0)
				return this->vals[this->topo--];
			else
				std::cout << "Erro: Pilha Vazia" << std::endl;
		}
		void imprime(){
			for (int i{0}; i<=this->topo ; ++i)
				std::cout << this->vals[i] << " ";

			std::cout << std::endl << std::endl;
		}
		int size(){
			return this->topo + 1;
		}

	private:
		int topo{-1};
		T vals[255];
};

int main() {
	pilha<char> uma_pilha;
	// Ex.1
	// uma_pilha.topo = 1;
	

	std::cout << "Tamanho da pilha: " << uma_pilha.size() << std::endl;
	std::cout << "Conteúdo da Pilha: ";
	uma_pilha.imprime();

	uma_pilha.push('a');
	uma_pilha.push('b');
	uma_pilha.push('c');

	std::cout << "Tamanho da pilha: " << uma_pilha.size() << std::endl;
	std::cout << "Conteúdo da Pilha: ";
	uma_pilha.imprime();

	std::cout << "Último elemento: " << uma_pilha.pop() << std::endl;

	std::cout << "Tamanho da pilha: " << uma_pilha.size() << std::endl;
	std::cout << "Conteúdo da Pilha: ";
	uma_pilha.imprime();

	return 0;
}
