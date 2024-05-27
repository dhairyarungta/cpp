#include <iostream>
class A{
public:
    template <typename T>
    A(T&& str,int i ):pw(std::forward<T>(str))
    {
        std::cout<<"Template constructor\n";
    }
    std::string pw;
};

int main(){
    A a("hello world", 0);
    A b(std::move(a));
    //std::cout<<"string value : "<<a.pw<<'\n';
    std::cout<<"string value : "<<b.pw<<'\n';
}