#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class ponto{
    // friend permite colocar um protótipo que não é da clase, dentro da class
    friend ponto operator*(double gain, const ponto &lhs);
    private:
        double coords[3];
    public:
        void print_point();
        double get_x() const;
        double get_y() const;
        double get_z() const;
        // Constructors
        ponto();
        ponto(double x_val, double y_val, double z_val);
        // Destructor
        ~ponto();
        // Operator = (Copy assignment)
        ponto &operator=(const ponto &rhs);
        // Operator +
        ponto operator+(const ponto &rhs) const;
        // Exercício: Operator -
        ponto operator-(const ponto &rhs) const;
        // Exercício: Operator - (negation)
        ponto operator-() const;
        // Exercício: Operator * (gain) // p2 = [x*gain, y*gain, z*gain]
        ponto operator*(double gain) const;
        // Exercício: Method ponto.norm() // norm(p) = sqrt(x^2+y^2+z^2)
        double norm() const;
};

void ponto::print_point() {
    cout << "[" << coords[0] << ", " << coords[1] << ", " << coords[2] << "]" << endl;
};
double ponto::get_x() const {return coords[0];};
double ponto::get_y() const {return coords[1];};
double ponto::get_z() const {return coords[2];};       

// Constructors
ponto::ponto(double x_val, double y_val, double z_val) {
    coords[0] = x_val;
    coords[1] = y_val;
    coords[2] = z_val;
    //cout << "Object at " << this << " has been created" << endl;
};
ponto::ponto(): ponto(0.0,0.0,0.0){ };

// Destructor
ponto::~ponto() {
    //cout << "Destructor for object at " << this << endl;
};

// Operator = (Copy assignment)
ponto &ponto::operator=(const ponto &rhs) {
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
    //cout << "Object at " << this << " received copy-assignment from " << &rhs << endl;
    return *this;
};

// Operator +
ponto ponto::operator+(const ponto &rhs) const {
    double x = coords[0]+rhs.coords[0];
    double y = coords[1]+rhs.coords[1];
    double z = coords[2]+rhs.coords[2];
    //cout << "Add object " << this << " and " << &rhs << endl;
    return ponto(x,y,z);
};

// Operator -
ponto ponto::operator-(const ponto &rhs) const {
    double x = coords[0]-rhs.coords[0];
    double y = coords[1]-rhs.coords[1];
    double z = coords[2]-rhs.coords[2];
    //cout << "Sub object " << this << " and " << &rhs << endl;
    return ponto(x,y,z);
};

// Operator - (negation)
ponto ponto::operator-() const {
    //cout << "Negation of the object " << this << endl;
    return ponto(-coords[0], -coords[1], -coords[2]);
};

// Exercício: Operator * (gain) // p 2 [x*gain, y*gain, z*gain]
ponto ponto::operator*(double gain) const {
    //cout << "Gain of the object " << this << " by " << gain << endl;
    return ponto(coords[0]*gain, coords[1]*gain, coords[2]*gain);
}

// Exercício: Method ponto.norm() // norm(p) = sqrt(x^2+y^2+z^2)
double ponto::norm() const{
    //cout << "Norm of " << this << endl;
    return sqrt(pow(coords[0],2.0) + pow(coords[1],2.0) + pow(coords[2],2.0));
};

ponto operator*(const double gain, const ponto &lhs){
    //cout << "Gain of the objetct " << &lhs << " by " << gain << endl;
    return lhs*gain;
}

double temperatura(const ponto &p){
    return pow(p.get_x(),2.0)+3.0*p.get_x()+2.0 + pow(p.get_y(),2.0)-5.0*p.get_y()+4.0 + pow(p.get_z(),2.0)-4.0*p.get_z()+8.0;
}

ponto gradiente(const ponto &p){
    return ponto(2.0*p.get_x()+3.0, 2.0*p.get_y()-5.0, 2.0*p.get_z()-4.0);
}

int main() {
    cout << "# Achando a temperatura mínima em uma sala #" << endl;
    ponto p1(0.0,0.0,0.0);
    double t;
    ponto grad;

    do {
        t = temperatura(p1);
        grad = gradiente(p1);
        
        p1 = p1 - 0.1*grad;

        cout << "Temperature=" << t << ", norm(grad)=" << grad.norm() << endl;
    } while (grad.norm() > 0.01);
    return 0;
}