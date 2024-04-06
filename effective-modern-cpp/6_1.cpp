template<typename C>
void workWithContainer (const C&container){

    int value1 = computeValue1();
    int value2 = computeValue2();
    auto divisor = computeDivisor (value1, value2);

    using ContElemT = typename C::value_type;
    
    using std::begin;
    using std::end;
    if(std::all_of(begin(container),end(container)
        [&divisor](const ContElemT& value){return value%divisor ==0 } )){
        //some code
    }
    else {
        //some code
    } 
}