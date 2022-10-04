#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>

unsigned int nearest(std::vector<double> f, double T){
	unsigned int L, R, m;
    
	L = 0;
	R = f.size()-1;
	while(R-L > 1){
		m = (L+R)/2;
		if (f.at(m)<T)
			L = m;
		else if (f.at(m)>T)
			R = m;
		else
			return m;
	}
	if (abs(f.at(L)) < abs(f.at(R)))
		return L;
	else
		return R;
}

unsigned int nearest2(std::vector<double> *&f, double T){

	std::vector<double>  *p_f{f};

	unsigned int L, R, m;
    
	L = 0;
	R = p_f->size()-1;
	while(R-L > 1){
		m = (L+R)/2;
		if (p_f->at(m)<T)
			L = m;
		else if (p_f->at(m)>T)
			R = m;
		else
			return m;
	}
	if (abs(p_f->at(L)) < abs(p_f->at(R)))
		return L;
	else
		return R;
}


using namespace std::chrono;

int main() {
	// Cria um vetor com valores crescentes
	std::vector<double> f_inc(10000);
	for (size_t i{0}; i<f_inc.size(); i++){
		f_inc.at(i) = std::sqrt(i);
	}

	std::cout << std::endl << "Nearest: " << std::endl;


	// variáveis para medição de tempo
	int idx;
	high_resolution_clock::time_point t1, t2;
	duration<double, std::milli> time_span;

	// Teste da função nearest
	t1 = high_resolution_clock::now();
	idx = nearest(f_inc, 33.3);
	t2 = high_resolution_clock::now();

	std::cout << "O mais próximo de 33.3 é f(" << idx << ")=" << f_inc.at(idx) << std::endl;

	time_span = t2 - t1;
	std::cout << "Elapsed time: " << time_span.count() << " ms" << std::endl;

	//
	// Teste sua função nearest2 aqui!
	//


	std::cout << std::endl << "Nearest2: " << std::endl;


	// variáveis para medição de tempo
	int idx2;
	high_resolution_clock::time_point t3, t4;
	duration<double, std::milli> time_span2;

	// Teste da função nearest
	t3 = high_resolution_clock::now();
	idx2 = nearest(f_inc, 33.3);
	t4 = high_resolution_clock::now();

	std::cout << "O mais próximo de 33.3 é f(" << idx2 << ")=" << f_inc.at(idx2) << std::endl;

	time_span2 = t4 - t3;
	std::cout << "Elapsed time: " << time_span2.count() << " ms" << std::endl;

	return 0;
}
