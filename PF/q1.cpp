#include <iostream>
#include <string>

class Equipamento {
    public:
        std::string nome;
};

class Motor: public Equipamento {
    private:
        std::string unidade{"cv"};
    public:
        double potencia{0.0};
        void Especificacoes();
        Motor(std::string nome);
};

void Motor::Especificacoes(){
    std::cout << "Equipamento: " << nome << std::endl;
    std::cout << "Pontência: " << potencia << " " << unidade <<std::endl;
};

Motor::Motor(std::string nome){
    this->nome = nome;
}


class Compressor: public Equipamento {
    private:
        std::string unidade{"bar"};
    public:
        double pressao{0.0};
        void Especificacoes();
        Compressor(std::string nome);
};

void Compressor::Especificacoes(){
    std::cout << "Equipamento: " << nome << std::endl;
    std::cout << "Pressão: " << pressao << " " << unidade <<std::endl;
};

Compressor::Compressor(std::string nome){
    this->nome = nome;
}


int main() {
    // // Ex.1
    // Motor Misturador;
    // Misturador.nome = "Motor do Misturador";
    // Misturador.potencia = 15;
    
    // // Ex.2
    // Compressor AlimentacaoPneumatica;
    // AlimentacaoPneumatica.nome = "Alimentação Pneumática";
    // AlimentacaoPneumatica.pressao = 6;

    // // Ex.3
    // Misturador.Especificacoes();
    // AlimentacaoPneumatica.Especificacoes();

    // Ex.4
    Motor Misturador1("Motor do Misturador");
    Misturador1.potencia = 15;

    Compressor AlimentacaoPneumatica1("Alimentação Pneumática");
    AlimentacaoPneumatica1.pressao = 6;

    Misturador1.Especificacoes();
    AlimentacaoPneumatica1.Especificacoes();
}
