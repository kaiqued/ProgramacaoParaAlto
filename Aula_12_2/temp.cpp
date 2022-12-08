#include <iostream>
#include <chrono>
#include <vector>
#include <string.h>

using namespace std;

class Sensor{
    private:
        double value;
        void stop();

    public:
        string description;
        string name;
        string unity;
        
        void read_value(){
            value = 12345.12;
            cout << "O valor é: " << value << unity << endl;
        }
        void start();


};

int main()
{
    Sensor MeuSensor;

    MeuSensor.name = "JORGE";
    MeuSensor.unity = "ºC";

    MeuSensor.read_value();
    cout << MeuSensor.name << endl;
    return 0;
}