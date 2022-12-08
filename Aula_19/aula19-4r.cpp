#include <iostream>
#include <memory>
#include <string>

using namespace std;

template<class T>
class node{
    public:
        T Content;
        std::shared_ptr<node> prox{nullptr};
};

struct municipio {
    string name;
    int pop;
};

void print_list(std::shared_ptr<node<string>> cursor){
    while (cursor != nullptr) {
        std::cout << cursor->Content << std::endl;
        cursor = cursor->prox;
    }
}

void print_list(std::shared_ptr<node<municipio>> cursor){
    while (cursor != nullptr) {
        std::cout << cursor->Content.name <<
            " " << cursor->Content.pop << std::endl;
        cursor = cursor->prox;
    }
}


int main() {
    auto head = make_shared<node<municipio>>();
    shared_ptr<node<municipio>> cursor{head};
    cursor->Content.name = "São Paulo";
    
    cursor->prox = std::make_shared<node<municipio>>();
    cursor = cursor->prox;
    cursor->Content.name = "Santos";
    
    cursor->prox = std::make_shared<node<municipio>>();
    cursor = cursor->prox;
    cursor->Content.name = "Campinas";
    
    cursor->prox = std::make_shared<node<municipio>>();
    cursor = cursor->prox;
    cursor->Content.name = "Bauru";

    print_list(head);

    return 0;
}