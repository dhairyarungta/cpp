#include <string>
template <typename T>
void func(T&& param){
    //do something 
    ;
}

int main(){

    std::string name("hello");
    func(name);//arg is lvalue
    //deduced type of T is std::string&, lvalue reference


    func(std::string ("dhairya"));//arg is rvalue 
    //dedcued type of T is std::string, non reference

    //happens due to reference collapsing
}


template<typename T>
decltype(auto) move (T&& param){
    return static_cast<std::remove_referernce_t<T>&&>(param);
}

template<typename T>
T&& forward(typename remove_reference<T>::type& param){
    return static_cast<T&&>(param);
}

template<typename T>
T&& forward(std::remove_reference_t<T>& param){
   return static_cast<T&&>(param); 
}