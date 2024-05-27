#include <type_traits>
template<typename T>
void logAndAdd(T&& name){
    logAndAddImpl(std::forward<T>(name),std::is_integral<typename std::remove_reference<T>::type>());
    //logAndAddImpl(std::forward<T>(name),std::is_integer<std::remove_reference_t<T>>())
}


template<typename T>
void logAndAddImpl(T&&name, std::false_type){
    //some code
    names.emplace(std::forward<T>(name));
}


template<typename T>
struct remove_reference {typedef T type;};

template <typename T>
struct remove_reference<T&>{typedef T type;};

template <typename T>
struct remove_reference<T&&>{typedef T type;};