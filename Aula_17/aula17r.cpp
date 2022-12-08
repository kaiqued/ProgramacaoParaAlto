#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

class Q{
    friend ostream &operator<<(std::ostream &os, const Q &rhs);
    friend Q operator+(const Q &lhs, const Q &rhs);
    friend Q operator-(const Q &lhs, const Q &rhs);
    friend Q operator*(const Q &lhs, const Q &rhs);
    friend Q operator/(const Q &lhs, const Q &rhs);
    friend bool operator==(const Q &lhs, const Q &rhs);
    friend bool operator>(const Q &lhs, const Q &rhs);
    friend bool operator>=(const Q &lhs, const Q &rhs);
    friend bool operator<(const Q &lhs, const Q &rhs);
    friend bool operator<=(const Q &lhs, const Q &rhs);
    
    friend Q operator-(const Q &rhs);

    private:
        int MDC();
        void simplify();
    public:
        long int n;
        long int d;
        // Constructors and destructors
        Q();
        Q(long int n_val);
        Q(long int n_val, long int d_val);
        ~Q();
        // Unary opperators
        Q operator++();
        Q operator++(int);
        Q operator--();
        Q operator--(int);

        Q operator+=(const Q &rhs);
        Q operator-=(const Q &rhs);
        Q operator*=(const Q &rhs);
        Q operator/=(const Q &rhs);
};

Q::Q():n{0}, d{1} {};
Q::Q(long int n_val): n{n_val}, d{1} {};
Q::Q(long int n_val, long int d_val): n{n_val}, d{d_val} {
    simplify();
};
Q::~Q(){};

int Q::MDC(){
    long int x{abs(n)},y{abs(d)}, temp;
    while (x != y) {
        if (x>y) {
            x = x-y;
        }
        else if (x<y) {
            temp = x;
            x = y;
            y = temp;
        }  
    }
    return y;
}

void Q::simplify(){
    int mdc{MDC()};
    n = n/mdc;
    d = d/mdc;

    if (d<0) { // Mantém o denominador positivo
        n = -n;
        d = -d;
    }
}

Q operator-(const Q &rhs){
    return Q(-rhs.n, rhs.d);
}

ostream &operator<<(std::ostream &os, const Q &rhs){
    if (rhs.d == 1){
        os << rhs.n;
    } else {
        os << rhs.n << "/" << rhs.d;
    }

    return os;
};

Q operator+(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.d + rhs.n*lhs.d;
    temp.d = lhs.d*rhs.d;
    temp.simplify(); // simplify é um método private, mas esse método é friend
    return temp;
};

Q operator-(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.d - rhs.n*lhs.d;
    temp.d = lhs.d*rhs.d;
    temp.simplify(); // simplify é um método private, mas esse método é friend
    return temp;
};

Q operator*(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.n;
    temp.d = lhs.d*rhs.d;
    temp.simplify(); // simplify é um método private, mas esse método é friend
    return temp;
};

Q operator/(const Q &lhs, const Q &rhs){
    Q temp;
    temp.n = lhs.n*rhs.d;
    temp.d = lhs.d*rhs.n;
    temp.simplify(); // simplify é um método private, mas esse método é friend
    return temp;
};

Q Q::operator+=(const Q &rhs){
    *this = *this + rhs;
    return *this;
};

Q Q::operator-=(const Q &rhs){
    *this = *this - rhs;
    return *this;
};

Q Q::operator*=(const Q &rhs){
    *this = *this * rhs;
    return *this;
};

Q Q::operator/=(const Q &rhs){
    *this = *this / rhs;
    return *this;
};

bool operator==(const Q &lhs, const Q &rhs){
    return lhs.n == rhs.n && lhs.d == rhs.d;
};

bool operator>(const Q &lhs, const Q &rhs){
    Q temp{lhs-rhs};
    return temp.n>0;
};

bool operator>=(const Q &lhs, const Q &rhs){
    Q temp{lhs-rhs};
    return temp.n>=0;
};

bool operator<(const Q &lhs, const Q &rhs){
    Q temp{lhs-rhs};
    return temp.n<0;
};

bool operator<=(const Q &lhs, const Q &rhs){
    Q temp{lhs-rhs};
    return temp.n<=0;
};

Q Q::operator++(){
    *this = *this + 1;
    return *this;
}

Q Q::operator++(int){
    Q temp{*this};

    *this = *this + 1;
    return temp;
}

Q Q::operator--(){
    *this = *this - 1;
    return *this;
}

Q Q::operator--(int){
    Q temp{*this};

    *this = *this - 1;
    return temp;
}

int main() {
    Q x{1,3}, y{4,5};

    cout << "{" << x << ", " << y << "} in Q"<< endl;
    cout << "x+y = " << x + y << endl;
    cout << "x*y = " << x * y << endl;
    cout << std::boolalpha; // Para imprimir boolanos como true e false
    cout << "x < y ? " << (x > y) << endl;
    
    // Teste de precisão em função recursiva: x(k+1) = xk + y;
    Q xq{5,11}, yq{5,11};
    float xf{5.0/11.0}, yf{5.0/11.0};

    for (int i{0}; i<1000; i++){ // Teste com i<100 até i<10000
        xq += yq;
        xf += yf;
    }
    cout << "Número racional: " << xq << endl;
    cout << "Número racional convertido para float: " << (static_cast<float>(xq.n)/static_cast<float>(xq.d)) << endl;
    cout << "Número ponto flutuante: " << xf << endl;

    return 0;
}
