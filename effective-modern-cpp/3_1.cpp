#include <vector>
enum Color {black, white, red};
enum class Color_class{black, white,red};

std::vector<std::size_t>
    primeFactors(std::size_t x);

Color c = red;
Color_class c2 = Color_class::red;

if(c<10.0){//implicit conversion from enum to int and then double
   ; //compiles 
}

if(c2<10.0){
    ;//compilation error
}