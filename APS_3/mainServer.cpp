#include "ClassSensor.h"
#include "ClassServer.h"


class Device {
    public:
    string nome;

    Temperatura Ts;

    Device(string nome);
};


Device::Device(string nome){
    this->nome = nome;
    Ts = Temperatura(nome, )
}