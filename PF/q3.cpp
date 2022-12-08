#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Shape{ // Abstract class
    // Seu código aqui!
};

class Elipse: { // Concrete class (Obs. Obedeça a herança de Shape)
    // Seu código aqui!
};
double Elipse::area(){ return R1 * R2 * M_PI; };

class Circle: { // Concrete class (Obs. Obedeça a herança de Elipse)
    // Seu código aqui!
}
double Circle::area(){ return R * R * M_PI; };

class Triangle: { // Concrete class (Obs. Obedeça a herança de Shape)
    // Seu código aqui!
}
double Triangle::area(){double s{(L1+L2+L3)/2.0};  return std::sqrt(s*(s-L1)*(s-L2)*(s-L3)); };

class Rectangle: { // Concrete class (Obs. Obedeça a herança de Shape)
    // Seu código aqui!
}
double Rectangle::area(){return L1*L2; };

class Square: { // Concrete class (Obs. Obedeça a herança de Rectangle)
    // Seu código aqui!
}
double Square::area(){return L*L; };

int main() {
    Elipse e;
    e.R1 = 2.0;
    e.R2 = 3.0;
	std::cout << "Elipse Area: " << e.area() << std::endl;

	Circle c;
    c.R = 2.0;
	std::cout << "Circle Area: " << c.area() << std::endl;
	
    Triangle t;
    t.L1 = 2.0;
    t.L2 = 3.0;
    t.L3 = 4.0;
    std::cout << "Triangle Area: " << t.area() << std::endl;

    Rectangle r;
    r.L1 = 2.0;
    r.L2 = 3.0;
    std::cout << "Rectangle Area: " << r.area() << std::endl;
    
    Square s;
    s.L = 2.0;
    std::cout << "Square Area: " << s.area() << std::endl;
    
	return 0;
}
