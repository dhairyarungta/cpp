class IsValAndArch{
    public:
    using DataType = std::unique_ptr<Widget>;

    explicit IsValAndArch(DataType&& ptr): pw (std::move(ptr))
    {}

    bool operator()()const {
        return pw->isValidated() && pw->isArchived();            
    }

    private:
        DataType pw;
}

auto func  = IsValAndArch(std::make_unqiue<Widget>());

//or 

auto func = [pw = std::make_uniqeu<Widget>()]
                {return pw->isValidated() && pw->isArchived();};


std::vector <double>data;

/*Move capture way for C++ 11*/
auto func = std::bind(
    [](const std::vector<double>& data)
    {/*use data*/},
    std::move(data)
);


/*C++ 14 feature*/
auto func = [data = std::move(data)]()
            {/*use data */}; 

template<typename T>
void logAndAdd(T&& name){
    logAndAddImpl(std::forward<T>(name),
        std::is_integral<std::remove_reference<T>>());
}

template<typename T>
logAndAddImpl(T&& name, std::false_type){
    auto now = std::chrono::system_clock::now();
    log(now, "logAndAdd");
    names.emplace(std::forward<T>(name));
}

logAndAddImpl(int id,std::true_type){
    logAndAdd(nameFromId(id));
}