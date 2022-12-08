#include <iostream>

template <class T>



T maximum( T& var1, T& var2){
    if(var1 > var2){
        return var1;
    }else
    if (var1 < var2){
        return var2;
    }else{
        return var1;
    }

    }

int main(){
    float val1 {10.5};
    float val2 {5.2};

    std::cout << maximum(val1, val2)<< std::endl;

    return 0;
}