#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sensor { 
    private:
        string name;
        string unity;
        double gain;
        double offset;
    public:
        void calibrate(double gain, double offset); // Prototipo
        void set(string name, string unity); // Prototipo
};
void Sensor::calibrate(double gain, double offset) { // Implementação
    this->gain = gain;
    this->offset = offset;

}
void Sensor::set(string name, string unity) { // Implementação
    this->name = name;
    this->unity = unity;
}

class PressureSensor: public Sensor {
    private:
    public:
        int GethPa(void){
            return 10000;
        }
        int GetAtm(void){
            return 123456;
        }
};

class MoistureSensor: public Sensor {
    private:
    public:
        int GetRelative(void){
            return 10000;
        }
};

class TemperatureSensor: public Sensor {
    private:
    public:
        int GetC(void){
            return 10000;
        }
        int GetF(void){
            return 10000;
        }
};

class Device{
    private:
        string Name;
        string Serial;
        

    public:
        PressureSensor ps;
        TemperatureSensor ts;
        MoistureSensor ms;
        void set(string Name, string Serial){
            this->Name = Name;
            this->Serial = Serial;
        }
};


// ESCREVA A CLASSE Device

int main() {
    // Criando sensores
    TemperatureSensor PTC1;
    PTC1.set("Tempratura do Solo", "°C");
    PTC1.calibrate(1.0, 0.0);

    MoistureSensor Higro1;
    Higro1.set("Umidade do ar", "%");
    Higro1.calibrate(1.0, 0.0);

    PressureSensor Press1;
    Press1.set("Pressão atmosférica", "atm");
    Press1.calibrate(1.0, 0.0);

    // Criando um dispositivo
    Device IOT_device;
    IOT_device.set("Estação 1", "S12.34");
    IOT_device.ts = PTC1;
    IOT_device.ms = Higro1;
    IOT_device.ps = Press1;

    return 0;
}