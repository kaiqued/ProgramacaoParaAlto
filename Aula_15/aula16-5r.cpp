#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sensor {
    protected:
        string name;
        string unity;
        double gain;
        double offset;
    public:
        void calibrate(double gain, double offset); // Virtual function;
        void set(string name, string unity); // Virtual function
        virtual void print() = 0; // Virtual function
};
void Sensor::calibrate(double gain, double offset) {
    this->gain = gain;
    this->offset = offset;
}
void Sensor::set(string name, string unity) {
    this->name = name;
    this->unity = unity;
}

class TemperatureSensor: public Sensor {
    public:
        double getC();
        double getF();
        virtual void print() override;
};
double TemperatureSensor::getC(){
    return 0.0;
}
double TemperatureSensor::getF(){
    return 0.0;
}
void TemperatureSensor::print(){
    cout << name << ": " << getC() << unity << endl;
}

class MoistureSensor: public Sensor {
    public:
        double getRelative();
        virtual void print() override;
};
double MoistureSensor::getRelative(){
    return 0.0;
}
void MoistureSensor::print(){
    cout << name << ": " << getRelative() << unity << endl;
}

class PressureSensor: public Sensor {
    public:
        double getPa();
        double getAtm();
        virtual void print() override;
};
double PressureSensor::getPa(){
    return 0.0;
}
double PressureSensor::getAtm(){
    return 0.0;
}
void PressureSensor::print(){
    cout << name << ": " << getAtm() << unity << endl;
}

class Device {
    private:
        string name;
        string serial;
        vector<Sensor*> Device_sensors;
    public:
        Device();
        void set(string name, string serial);
        TemperatureSensor ts;
        MoistureSensor ms;
        PressureSensor ps;
        void print_sensors();
};
Device::Device(){
    Device_sensors.push_back(&ts);
    Device_sensors.push_back(&ms);
    Device_sensors.push_back(&ps);
}
void Device::set(string name, string serial) {
    this->name = name;
    this->serial = serial;
}
void Device::print_sensors(){
    for (auto s: Device_sensors){
        s->print();
    }
}

int main() {
    // Criando sensores
    TemperatureSensor PTC1;
    PTC1.set("Tempratura do Solo", "°C");
    PTC1.calibrate(1.0, 0.0);

    MoistureSensor Higro1;
    Higro1.set("Umidade do ar", "%");
    Higro1.calibrate(1.0, 0.0);

    PressureSensor Press1;
    Press1.set("Pressão atmosférica", " atm");
    Press1.calibrate(1.0, 0.0);

    // Criando um dispositivo
    Device IOT_device;
    IOT_device.set("Estação 1", "S12.34");
    IOT_device.ts = PTC1;
    IOT_device.ms = Higro1;
    IOT_device.ps = Press1;

    IOT_device.print_sensors();

    return 0;
}