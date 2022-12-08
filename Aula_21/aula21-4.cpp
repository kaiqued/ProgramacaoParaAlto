#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;


void factorial(int N, int *res) {
    *res = 1;
    for (int i=N; i>1; i--)
        *res *= i;

    std::cout << "Result: " << *res << std::endl;
}

int main() {
    int result;
    std::thread th(factorial, 6, &result);
    std::cout << "Alguma outra tarefa... " << std::endl;

    th.join();

    std::cout << "Terminou... x=" << result << std::endl;
    return 0;
}