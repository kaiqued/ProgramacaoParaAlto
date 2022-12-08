#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Sensor {
    private:
        string nome;
        string unidade;
        double minVal;
        double maxVal;

        void set(string nome, string unidade, double maxVal, double minVal);
        
    public:
        // Constructor:
        Sensor(string nome, string unidade, double maxVal, double minVal);
        // Destructor
        virtual ~Sensor();

        double read();

        // 
        friend ostream &operator<<(std::ostream &os, Sensor &rhs);
};

class Temperatura: public Sensor {
    public:

        double GetC();

};