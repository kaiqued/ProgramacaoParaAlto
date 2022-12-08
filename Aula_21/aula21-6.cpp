#include <iostream>
#include <chrono>
#include <future>
#include <string>
using namespace std::chrono;

/*
 * Exemplo, criar um fluxo de dados: Tarefa 1 ---> (tarefa 2 e 3) ---> tarefa 4
 */

void tarefa1(std::future<int> *f1, std::promise<int> *p1){
    int f1res = f1->get();

    int t_sleep{std::rand()%1000+3000}; // Aguarda um tempo aleatório
    std::this_thread::sleep_for(milliseconds(t_sleep));

    std::cout << "Tarefa 1" << std::endl;
    p1->set_value(f1res); // Dispara tarefas 1 e 2
}

void tarefa2(std::shared_future<int> *f2, std::promise<int> *p2){
    int f2res = f2->get();

    int t_sleep{std::rand()%1000+3000}; // Aguarda um tempo aleatório
    std::this_thread::sleep_for(milliseconds(t_sleep));

    std::cout << "Tarefa 2" << std::endl;
    p2->set_value(f2res+1); // Dispara tarefas 1 e 2
}

void tarefa3(std::shared_future<int> *f3, std::promise<int> *p3){
    int f3res = f3->get();

    int t_sleep{std::rand()%1000+3000}; // Aguarda um tempo aleatório
    std::this_thread::sleep_for(milliseconds(t_sleep));

    std::cout << "Tarefa 3" << std::endl;
    p3->set_value(f3res+1); // Dispara tarefas 1 e 2
}

int tarefa4(std::future<int> *f42, std::future<int> *f43){
    int f42res = f42->get();
    int f43res = f43->get();

    int t_sleep{std::rand()%1000+3000}; // Aguarda um tempo aleatório
    std::this_thread::sleep_for(milliseconds(t_sleep));

    std::cout << "Tarefa 4" << std::endl;
    return f42res+f43res;
}

int main() {
    std::srand(time(nullptr));

    // Promise para a tarefa 1
    std::promise<int> p0;
    std::future<int> f1 = p0.get_future();
    // Future da tarefa 1
    std::promise<int> p1;
    std::future<void> T1 = std::async(tarefa1, &f1, &p1);

    // Promise para as tarefa 2 e 3
    std::shared_future<int> f2 = p1.get_future();
    // Future da tarefa 2
    std::promise<int> p2;
    std::future<void> T2 = std::async(tarefa2, &f2, &p2);

    // Future da tarefa 3
    std::promise<int> p3;
    std::future<void> T3 = std::async(tarefa3, &f2, &p3);

    // Promise para a tarefa 4
    std::future<int> f42 = p2.get_future();
    std::future<int> f43 = p3.get_future();
    // Promise para a tarefa 4
    std::future<int> f4 = std::async(tarefa4, &f42, &f43);

    p0.set_value(1); // Inicia a primeira tarefa

    f4.get();

    return 0;
}