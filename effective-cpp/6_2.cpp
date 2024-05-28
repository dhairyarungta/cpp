#include <iostream>

class A{
public:
    virtual void func(){
        std::cout<<" insdie 1\n";
        // std::cout<<x<<" insdie 1\n";
    }
}; 

class B : public A{
public:
    using A::func;
    virtual void func(){
        std::cout<<"Inside 2\n";
    }

};

int main(){
    A a;
    B b;
    b.A::func();
}