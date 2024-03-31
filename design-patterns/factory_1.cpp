#include <iostream>
class Creator;
class Product{
public:
    virtual void operator()() = 0;
};

class ConcreteProductA : public Product{
    void operator()()override{
        std::cout<<"Hello from concrete product A\n";
    }
};

class ConcreteProductB: public  Product{
    void operator()()override{
        std::cout<<"Hello from concrete product B\n";
    }
};
class Creator {
public:
    virtual Product* factory_method() = 0;
    void doSomething(){
        std::cout<<"Inside Abstract Creator, I am unaware of product type\n";
        std::cout<<"I am unaware of the Concrete Creator type\n";
        Product* product = factory_method();        
        (*product)();
        return ;
    }

};
class ConcreteCreatorA : public Creator{
    Product* factory_method()override{
        return (new ConcreteProductA{});
    }
};

class ConcreteCreatorB : public Creator{
    Product* factory_method()override{
        return (new ConcreteProductB{});
    }

};

void ClientCode(Creator* creator_){
    std::cout<<"Inside client code, I am unaware of the type of Creator\n";
    (*creator_).doSomething();
    return ;
}


int main(){
    std::cout<<"Inside main\n";
    std::cout<<"Launching with Creator A\n";
    ConcreteCreatorA creatorA_{};
    ClientCode(&creatorA_);
    std::cout<<"Launching with Creator B\n";
    ConcreteCreatorB creatorB_{};
    ClientCode(&creatorB_);
}