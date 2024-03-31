//C++11, constexpr function with only one executable statement which has to be a return statement
constexpr int pow (int base, int exp)noexcept{
    return (exp==0 ? 1 : base*pow(base,exp-1));
}

//C++14 implementation
constexpr int pow(int base, int exp)noexcept{
    auto result = 1;
    for (int i =0;i<exp;i++)
        result *=base;
    
    return result;
}
