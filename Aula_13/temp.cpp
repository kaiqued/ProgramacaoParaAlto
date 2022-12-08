#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class cart
{
private:
    int id;
    vector<int> productid;

public:
    void addProductToCart(int product);
    void removeProductFromCart(int product);
    void checkOut();

    cart()
    {
        id = 0;
    };
    ~cart();
};

void cart::addProductToCart(int product)
{
    productid.push_back(product);
};

void cart::removeProductFromCart(int product){
    for (int i=0; i<productid.size(); i++){
        if (productid[i] == product){
            delete &productid[i];
        };
    }
};

void cart::checkOut(){
    for (int i=0; i<productid.size(); i++){
        cout << "Produto " << i << ": " << productid[i] << endl;
    }
};

int main()
{
    cart Carrinho1();
    Carrinho1.addProducToCart(123);

    Carrinho1.checkOut();
    return 0;
}