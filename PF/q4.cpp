#include <iostream>

class Cplx {
	private:
		double a{0.0},b{0.0};
	public:
		Cplx();
		Cplx(double a, double b);
		// Substitui Cplx add(Cplx y); por :
		Cplx operator+(const Cplx &rhs)const;
		// Substitui Cplx Cplx sub(Cplx y); por :
		Cplx operator-(const Cplx &rhs)const;
		// Substitui Cplx Cplx Cplx mul(Cplx y); por :
		Cplx operator*(const Cplx &rhs)const;
		// Substitui Cplx Cplx Cplx div(Cplx y); por :
		Cplx operator/(const Cplx &rhs)const;
		// Criei o operador <<:
		friend std::ostream &operator<<(std::ostream &os, const Cplx &obj);
		void print();
};

Cplx::Cplx(): a{0.0},b{0.0}{};
Cplx::Cplx(double a, double b) {
	this->a = a;
	this->b = b;
};
Cplx Cplx::operator+(const Cplx &rhs) const{
	return Cplx(this->a+ rhs.a, this->b+rhs.b);
}
Cplx Cplx::operator-(const Cplx &rhs)const{
	return Cplx(this->a-rhs.a, this->b-rhs.b);
}
Cplx Cplx::operator*(const Cplx &rhs)const{
	return Cplx(this->a*rhs.a - this->b*rhs.b, this->a*rhs.b + this->b*rhs.a);
}
Cplx Cplx::operator/(const Cplx &rhs)const{
	double r2 = rhs.a*rhs.a+rhs.b*rhs.b;
	return Cplx((this->a*rhs.a + this->b*rhs.b)/r2, (this->b*rhs.a - this->a*rhs.b)/r2);
}
void Cplx::print(){
	std::cout << "[" << a << "," << b << "]" << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Cplx &obj){
    os << "[" << obj.a << "," << obj.b << "]";
    return os;
}

int main() {
	Cplx x(1,2);
	Cplx y(3,4);
	
	std::cout << "Soma:"          << x+y << std::endl;
	std::cout << "Subtração:"     << x-y << std::endl;
	std::cout << "Multiplicação:" << x*y << std::endl;
	std::cout << "Divisão:"       << x/y << std::endl;

	return 0;
}
