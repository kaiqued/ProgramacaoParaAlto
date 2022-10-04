#include <iostream>

int main() {
	long int n{55555};
	int s{};

	int divisor {10};
	long int value {n};

    for (int divisor{10}; value%divisor > 0; divisor *= 10){
		
		int temp {value%divisor};
		s += 10*temp/divisor;
		value = value - temp;
	}
	
	std::cout << "Soma dos dígitos de " << n << " é " << s << std::endl;
	return 0;		
}
