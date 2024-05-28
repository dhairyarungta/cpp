class Base{
public: 
    virtual void mf1();
    virtual void mf1(int );
};

class Derived : private Base{
private:
    virtual void mf1(){
        Base::mf1();//only want to import mf1() with no params
    }
public:

};


//another case
class Base1{
public:
    virtual void mf1();
    virtual void mf1(int x);
    virtual void mf1(int x, int y);
    virtual void mf1(double a);

};

class Derived1 : public Base1{
    using  Base1::mf1;// imports all overloads of mf1

} ;

class Airplane{
public:
    virtual void fly() = 0; 
protected:
    void defaultFly();
};

class ModelA : public Airplane{
public:
    virtual void fly(){
        Airplane::defaultFly();
    }
};