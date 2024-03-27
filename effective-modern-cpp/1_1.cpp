template <typename T, typename N>
constexpr std::size_t arraySize(T(&)[N])noexcept{
    return N;
}

template <typename T>
void f(T& param);

const char name_array []= "Hello world";

f(name_array);
//type of T deduced is char[12];

//else if T Paratype of f was not a reference
template<typename T>
void f(T param);


const char name_array[] = "Hello world";

f(name_array);
//type of T deduced now is const char * because of array to pointer decay

//decay of function arguments to pointers

void someFunc(int , double);

template <typename T>
void f1(T param);

f1(someFunc);//T is deduced to void(*)(int, double)

template <typename T>
void f2(T param);

f2(someFunc);//T is deduced to void(&)(int, double)