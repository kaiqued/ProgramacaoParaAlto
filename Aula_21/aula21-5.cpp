#include <iostream>
#include <chrono>
#include <future>
 
int factorial(std::future<int> *fN) {
    std::cout << "Future Começou!" << std::endl;
    int res = 1;
    std::cout << "Aguardando Promise... " << std::endl;
    int N = fN->get();
    for (int i=N; i>1; i--)
        res *= i;

    std::cout << "Resultado: " << res << std::endl;
    return res;
}

int main() {
    std::cout << "Main Começou!" << std::endl;
    
    std::promise<int> p;
    std::future<int> fp = p.get_future();

    std::future<int> fu = std::async(factorial,&fp);
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Alguma outra tarefa... " << std::endl;

    std::cout << "Keep the promise! " << std::endl;
    p.set_value(6);

    std::cout << "Aguarda o resultado... " << std::endl;
    int x = fu.get();

    std::cout << "Terminou... x=" << x << std::endl;

    return 0;
}