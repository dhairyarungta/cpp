#include <iostream>

template<typename T>
void f(T& param){
    param = 11;
    std::cout<<param<<'\n';
}


int main(){

    const int x = 10;
    const int& y = x;
    f(y);
}
