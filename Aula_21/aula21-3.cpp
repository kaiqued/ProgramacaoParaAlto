#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>

std::mutex m;

void SensorIOT() {
    std::unique_lock<std::mutex> lck (m);

    // Não mexer nesse código daqui
    static int cont{0};
    ++cont;
    int t_sleep{std::rand()%1000};
    std::this_thread::sleep_for(std::chrono::milliseconds(t_sleep));
    std::cout << "Atualizou... " << cont << std::endl;
    // Até aqui
    
    lck.unlock();
}

int main() 
{
    std::srand(time(nullptr));
    std::thread s[4];
    

    for(int i{0}; i<4; i++){
        s[i] = std::move(std::thread(SensorIOT));
    }
    
    for(int i{0}; i<4; i++){
        s[i].join();
    }

    return 0;
}