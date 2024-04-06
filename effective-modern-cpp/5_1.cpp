//std::move function

template <typename T>
typename remove_reference<T>::type&& move(T&& param){
    using ReturnType = typename remove_reference<T>::type&&
    return static_cast<ReturnType>(param);
}

template<typename T>
decltype(auto) move(T&&param)
{
    using ReturnType = remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
}

class Widget{

};
void process(const Widget& w);
void process(Widget&& w);

template<typename T>
void logAndProcess(T&& param){
    std::cout<<"System time\n";
    process(std::forward<T>(param));
}


auto timeFuncInvocation = 
    [](auto&& func, auto&&... params){
        start timer;
        std::forward<decltype(func)>(std::forward<decltype(params)>(params)...);
    };

template <typename T>
void logAndAdd(T&& name){
    auto now = std::chrono::system_clock::now();
    log(now,"logAndAdd");
    names.emplace(std::forward<T>(name));
}