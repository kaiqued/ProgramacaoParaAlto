#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

bool trava{false};

void Task1(std::future<int> *f1, std::promise<int> *p1) {
	int f1res = f1->get();

	// --- Não modificar a partir daqui
	cout << "Task 1 síncrona iniciou" << endl;
	sleep_for(seconds(rand()%10));
	cout << "Task 1 síncrona terminou" << endl;
	// --- Não modificar até daqui
	
	p1->set_value(f1res); // Destrava outras threads
}

void Task2(std::shared_future<int> *f2, std::promise<int> *p2) {	
	int f2res = f2->get();
	
	// --- Não modificar a partir daqui
	cout << "Task 2 síncrona iniciou" << endl;
	sleep_for(seconds(rand()%10));
	cout << "Task 2 síncrona terminou" << endl;
	// --- Não modificar até daqui

	p2->set_value(f2res+1); // Destrava outras threads
}

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

int main() 
{
	std::srand(time(nullptr));

    // Promise para a tarefa 1
    std::promise<int> p0;
    std::future<int> f1 = p0.get_future();
    // Future da tarefa 1
    std::promise<int> p1;
    std::future<void> T1 = std::async(Task1, &f1, &p1);

    // Promise para as tarefa 2
    std::shared_future<int> f2 = p1.get_future();
    // Future da tarefa 2
    std::promise<int> p2;
    std::future<void> T2 = std::async(Task2, &f2, &p2);

	
	p0.set_value(1);

	f2.get();

    return 0;
}