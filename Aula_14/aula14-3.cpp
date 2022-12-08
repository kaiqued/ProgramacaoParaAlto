#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ponto{
    private:
        double coords[3];
    public:
        void print_point();
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
        // Exercício: Operator * (gain) // p2 = [x*gain, y*gain, z*gain]
        // Exercício: Operator ++ pre-increment // p2 = p1 + p1.normalized()
        // Desafio: Operator ++ post-increment // p2 = p1 + p1.normalized()
        // Exercício: Operator -- pre-decrement // p2 = p1 - p1.normalized()
        // Desafio: Operator -- post-decrement // p2 = p1 - p1.normalized()
        // Exercício: Method ponto.norm() // norm(p) = sqrt(x^2+y^2+z^2)
        // Exercício: Method ponto.normalize() // normalized(p) = [x/norm(p), y/norm(p), z/norm(p)]
};

// Desafio: Operator * (gain) // precisa funcionar gain*ponto e ponto*gain

void ponto::print_point() {
    cout << "[" << coords[0] << ", " << coords[1] << ", " << coords[2] << "]" << endl;
};

// Constructors
ponto::ponto(double x_val, double y_val, double z_val) {
    coords[0] = x_val;
    coords[1] = y_val;
    coords[2] = z_val;
    cout << "Object at " << this << " has been created" << endl;
};
ponto::ponto(): ponto(0.0,0.0,0.0){ };

// Destructor
ponto::~ponto() {
    cout << "Destructor for object at " << this << endl;
};

// Operator = (Copy assignment)
ponto &ponto::operator=(const ponto &rhs) {
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
    cout << "Object at " << this << " received copy-assignment from " << &rhs << endl;
    return *this;
};

// Operator +
ponto ponto::operator+(const ponto &rhs) const {
    double x = coords[0]+rhs.coords[0];
    double y = coords[1]+rhs.coords[1];
    double z = coords[2]+rhs.coords[2];
    cout << "Add objetct " << this << " and " << &rhs << endl;
    return ponto(x,y,z);
};

// Operator -
ponto ponto::operator-(const ponto &rhs) const {
    double x = coords[0]-rhs.coords[0];
    double y = coords[1]-rhs.coords[1];
    double z = coords[2]-rhs.coords[2];
    cout << "Subtract objetct " << this << " and " << &rhs << endl;
    return ponto(x,y,z);
};

int main() {
    cout << "# Criando um ponto #" << endl;
    ponto p1(1.0,2.0,3.0);
    p1.print_point();
    cout << "============================" << endl;

    cout << "# Copia e atribui um ponto #" << endl;
    ponto p2;
    p2 = p1;
    p2.print_point();
    cout << "============================" << endl;

    cout << "# Soma dois pontos #" << endl;
    ponto p3;
    p3 = p1 + p2;
    p3.print_point();
    cout << "============================" << endl;

    cout << "# Subtrai dois pontos #" << endl;
    ponto p4;
    p4 = p3 - ponto(3,3,0);
    p4.print_point();
    cout << "============================" << endl;

    return 0;
}