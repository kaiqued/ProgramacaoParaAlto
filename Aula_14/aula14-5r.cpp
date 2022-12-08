#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ponto{
    private:
        double *coords;
    public:
        void print_point();
        double get_x();
        double get_y();
        double get_z();
        // Constructors
        ponto();
        ponto(double x_val, double y_val, double z_val);
        // Destructor
        ~ponto();
        // Copy constructor
        ponto(const ponto &rhs);
        // Move constructor
        ponto(ponto &&source);
        // Operator = (Copy assignment)
        ponto &operator=(const ponto &rhs);
        // Operator = (Move assignment)
        ponto &operator=(ponto &&rhs);
};

void ponto::print_point() {
    cout << "[" << get_x() << ", " << get_y() << ", " << get_z() << "]" << endl;
};
double ponto::get_x() {return coords[0];}
double ponto::get_y() {return coords[1];}
double ponto::get_z() {return coords[2];}

// Constructors
ponto::ponto(double x_val, double y_val, double z_val) {
    coords = new double[3];
    coords[0] = x_val;
    coords[1] = y_val;
    coords[2] = z_val;
    cout << "Object at " << this << " has been created" << endl;
};
ponto::ponto(): ponto(0.0,0.0,0.0){ };
// Destructor
ponto::~ponto() {
    if (coords != nullptr) 
        cout << "Destructor for object at " << this << endl;
    else
        cout << "Destructor object for temporary" << endl;

    delete coords;
};
// Create-copy constructor
ponto::ponto(const ponto &rhs) {
    coords = new double[3];
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
    cout << "Object at " << this << " has been copyed" << endl;
}
// Move constructor
ponto::ponto(ponto &&source) : coords{source.coords}{
    source.coords = nullptr; // Steal pointer
    cout << "Object at " << this << " has been moved" << endl;
}

// Operator = (Copy assignment)
ponto &ponto::operator=(const ponto &rhs) {
    coords[0] = rhs.coords[0];
    coords[1] = rhs.coords[1];
    coords[2] = rhs.coords[2];
    cout << "Object at " << this << " received copy-assignment from " << &rhs << endl;
    return *this;
};

// Operator = (Move assignment)
ponto &ponto::operator=(ponto &&rhs){
    if (this == &rhs){
        return *this;
    }
    coords = rhs.coords;
    rhs.coords = nullptr; // Steal pointer
    cout << "Object at " << this << " received move-assignment from " << &rhs << endl;
    return *this;
}
        
int main() {
    cout << "Criando um ponto" << endl;
    ponto p1(1.0,2.0,3.0);
    p1.print_point();
    cout << "============================" << endl;

    cout << "Copia e atribui um ponto" << endl;
    ponto p2;
    p2 = p1;
    p1.print_point();
    p2.print_point();
    cout << "============================" << endl;

    cout << "Movendo um ponto" << endl;
    ponto p3{std::move(p2)};
    p3.print_point();
    // p2.print_point(); // ERRO p2 foi movido e não existe mais;
    cout << "============================" << endl;
        
    cout << "Move e atribui um ponto" << endl;
    p2 = std::move(p3);
    p1.print_point();
    p2.print_point();
    // p3.print_point(); // ERRO p3 foi movido e não existe mais;
    cout << "============================" << endl;

    return 0;
}