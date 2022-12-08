#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
 * class Position
 */ 
class Position{
    private:
        double *coords;
    public:
        double get_x() const;
        double get_y() const;
        double get_z() const;
        // Constructors
        Position();
        Position(double x_val, double y_val, double z_val);
        // Destructor
        virtual ~Position();
        // Create-copy Position
        Position(const Position &rhs);
        // Move constructor
        Position(Position &&source);
        // Operator = (Copy assignment) 
        Position &operator=(const Position &rhs);
        // Operator = (Move assignment)
        Position &operator=(Position &&rhs);
        // Operator +
        Position operator+(const Position &rhs) const;
        // Operator +=
        Position operator+=(const Position &rhs);
        // Operator -
        Position operator-(const Position &rhs) const;
        // Operator - (negation)
        Position operator-() const;
        // Operator <<
        friend std::ostream &operator<<(std::ostream &os, const Position &obj);
        // Operator * (gain) // p2 = [x*gain, y*gain, z*gain]
        Position operator*(double gain) const;
        // Method Position.norm() // norm(p) = sqrt(x^2+y^2+z^2)
        double norm() const;
};
// Constructor
Position::Position(): Position(0.0,0.0,0.0){ };
Position::Position(double x_val, double y_val, double z_val) {
    coords = new double[3];
    coords[0] = x_val;
    coords[1] = y_val;
    coords[2] = z_val;
};
Position::~Position() {
    delete coords;
};
// Create-copy Position
Position::Position(const Position &rhs) {
    coords = new double[3];
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
}
// Move constructor
Position::Position(Position &&source) : coords{source.coords}{
    source.coords = nullptr; // Steal pointer
}
// Operator = (Copy assignment)
Position &Position::operator=(const Position &rhs) {
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
    return *this;
}
// Operator = (Move assignment)
Position &Position::operator=(Position &&rhs){
    if (this == &rhs){
        return *this;
    }
    coords = rhs.coords;
    rhs.coords = nullptr; // Steal pointer
    return *this;
}
Position Position::operator+(const Position &rhs) const {
    double x = coords[0]+rhs.coords[0];
    double y = coords[1]+rhs.coords[1];
    double z = coords[2]+rhs.coords[2];
    return Position(x,y,z);
}
Position Position::operator+=(const Position &rhs){
    *this = *this + rhs;
    return *this;
}
Position Position::operator-(const Position &rhs) const {
    double x = coords[0]-rhs.coords[0];
    double y = coords[1]-rhs.coords[1];
    double z = coords[2]-rhs.coords[2];
    return Position(x,y,z);
}
Position Position::operator-() const {
    return Position(-coords[0], -coords[1], -coords[2]);
}
Position Position::operator*(double gain) const {
    return Position(coords[0]*gain, coords[1]*gain, coords[2]*gain);
}
double Position::norm() const{
    return sqrt(pow(coords[0],2.0) + pow(coords[1],2.0) + pow(coords[2],2.0));
}
Position operator*(const double gain, const Position &lhs){
    return lhs*gain;
}
std::ostream &operator<<(std::ostream &os, const Position &obj){
    os << "[" << obj.get_x() << ", " << obj.get_y() << ", " << obj.get_z() << "]";
    return os;
}

double Position::get_x() const {return coords[0];}
double Position::get_y() const {return coords[1];}
double Position::get_z() const {return coords[2];}

/*
 * class World
 */ 
class World{
    public:
        double Temperature(Position &p) const;
        Position Grad(Position &p) const;
};

double World::Temperature(Position &p) const {
    return pow(p.get_x(),2.0)+3.0*p.get_x()+2.0 + pow(p.get_y(),2.0)-5.0*p.get_y()+4.0 + pow(p.get_z(),2.0)-4.0*p.get_z()+8.0;
}
Position World::Grad(Position &p) const {
    return Position(2.0*p.get_x()+3.0, 2.0*p.get_y()-5.0, 2.0*p.get_z()-4.0);
}

/*
 * class Sensor
 */ 
class Sensor: protected World {
    protected:
        Position *loc;
    public:
        string name;
        string unity;
        Sensor(Position &loc);
};
Sensor::Sensor(Position &loc){ // Constructor (force to connecto sensor)
    this->loc = &loc;
}

/*
 * class TemperatureSensor
 */ 
class TemperatureSensor_c: public Sensor{
    friend std::ostream &operator<<(std::ostream &os, const TemperatureSensor_c &obj);
    public:
        double getC() const;
        TemperatureSensor_c(Position &loc);
};
double TemperatureSensor_c::getC() const {
    return Sensor::Temperature(*(Sensor::loc));
}
TemperatureSensor_c::TemperatureSensor_c(Position &loc): Sensor(loc) {};

std::ostream &operator<<(std::ostream &os, const TemperatureSensor_c &obj){
    os << obj.name << ": " << obj.getC() << obj.unity;
    return os;
}

/*
 * class GradientSensor
 */ 
class GradientSensor_c: public Sensor {
    friend std::ostream &operator<<(std::ostream &os, const GradientSensor_c &obj);
    public:
        Position getGrad() const;
        GradientSensor_c(Position &loc);
};
Position GradientSensor_c::getGrad() const {
    return Sensor::Grad(*(Sensor::loc));
}
GradientSensor_c::GradientSensor_c(Position &loc): Sensor(loc) {};

std::ostream &operator<<(std::ostream &os, const GradientSensor_c &obj){
    os << obj.name << ": " << obj.getGrad() << obj.unity;
    return os;
}

/*
 * class Drone
 */ 
class Drone {
    public:
        Position Location;
        TemperatureSensor_c temperatureSensor;
        GradientSensor_c gradientSensor;
        bool Move(Position Displacement);
        Drone(); // Constructor (connect sensor)
};
bool Drone::Move(Position Displacement){
    this->Location = this->Location + Displacement;
    return false;
}
Drone::Drone(): temperatureSensor(Location), gradientSensor(Location){ // Constructor (connect sensor)
    temperatureSensor.name = "Drone temperature:";
    temperatureSensor.unity = "°C";

    gradientSensor.name = "Temperature gradient:";
    gradientSensor.unity = "°C/m";
}

int main() {
    Drone aDrone; // Create a drone
    
    // cout << aDrone.Location << endl; // Print the location
    // aDrone.Move(Position(1,2,3)); // Move current position + vector
    // cout << aDrone.temperatureSensor.getC() << endl; // Print the temperature;
    // cout << aDrone.gradientSensor.getGrad() << endl; // Print the Gradient;

    Position grad;
    do {
        grad = aDrone.gradientSensor.getGrad();
        aDrone.Move(-0.1*grad);
        cout << aDrone.temperatureSensor << ", " << aDrone.gradientSensor << endl;
    } while (grad.norm() > 0.01);

    return 0;
}