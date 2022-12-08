#include "ClassSensor.h"

using namespace std;

Sensor::Sensor(string nome, string unidade, double maxVal, double minVal){
    this->set(nome, unidade, maxVal, minVal);

    cout << "Sensor " << nome << " inicializado" << endl;
}

Sensor::~Sensor(){
    cout << "Sensor " << nome << " destruido" << endl;
}

double Sensor::read(){
    srand(time(nullptr));
    double randomNumber = (( rand()%1000 ) / 1000.0); // Número randomico de 0 a 1
    // Usando a transformação de escala para calcular:
    return ((randomNumber - 0) * (this->maxVal - this->minVal) / (1.0 - 0.0)) + this->minVal;

}


void Sensor::set(string nome, string unidade, double maxVal, double minVal) {
    this->nome = nome;
    this->unidade = unidade;
    this->maxVal = maxVal;
    this->minVal = minVal;
}

ostream &operator<<(std::ostream &os, Sensor &rhs){
    os << "Sensor :"<< rhs.read() << " " << rhs.unidade << endl;

    return os;
};


