#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class city
{
    private:
        string name;
        char *name_pt{&name[0]};
        int pop;

    public:
        void set_city(string name_val, int pop_val);
        void print_city();
        city();
        city(string nameVal, int popVal);
        ~city();
};

city::city()
{
    name = "Sem Nome";
    cout << "Objeto construido: " << name << endl;
}
city::city(string nameVal, int popVal)
    : name{nameVal}, pop{popVal}
{
    for (int i{0};i < name.size();i++){
        *(name_pt+i) = toupper(*(name_pt+i));
    }
    cout << "Objeto construido: " << name << endl;
}
city::~city()
{
    cout << "DeSrtREuir" << endl;
}

void city::set_city(string name_val, int pop_val)
{
    name = name_val;
    pop = pop_val;
    for (int i{0};i < name.size();i++){
        *(name_pt+i) = toupper(*(name_pt+i));
    }
};

void city::print_city()
{
    cout << "Nome:" << name << "; pop:" << pop << endl;
};

int main()
{
    city city1;
    city1.set_city("Campinas", 1213792);
    city1.print_city();

    city city2("Santos", 12345);
    city2.print_city();

    return 0;
}