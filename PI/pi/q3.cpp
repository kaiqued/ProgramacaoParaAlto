#include <iostream>
#include <cmath>

double my_sinr(double x, int k)
{
	double xk;

	xk = std::pow(-1, k) * std::pow(x, 2.0 * k + 1.0) / std::tgamma(2.0 * k + 2.0);
	if (std::abs(xk) > 0.000001)
		return xk + my_sinr(x, k + 1);
	else
		return xk;
}

double MeuSino(double x)
{
	double xk;
	double sum {0};
	int k {0};
	
	do{
		xk = std::pow(-1, k) * std::pow(x, 2.0 * k + 1.0) / std::tgamma(2.0 * k + 2.0);
		k++;
		sum = xk + sum;
	}while (std::abs(xk) > 0.000001);

	return sum;
}

int main()
{
	std::cout << "MeuSino(0.7) = " << MeuSino(0.7) << std::endl;
	std::cout << "my_sinr(0.7) = " << my_sinr(0.7, 0) << std::endl;
	std::cout << "    sin(0.7) = " << std::sin(0.7) << std::endl;
	return 0;
}
