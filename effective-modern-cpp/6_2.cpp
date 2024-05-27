
std::find_if(v.begin(),v.end(),
    [](int val){return 0<val && val<10;});

auto c1 = 
    [x](int y){return x*y>55;};

auto c2 = c1;
auto c3 = c2;


using FilterContainer = 
    std::vector<std::function<bool(int)>>;

FilterContainer filters;

filters.empalce(
    [](int value){return value%5 == 0 ;}
);

if(std::all_of(begin(container),end(container),
    [&](const auto &value){
        return value%divisor == 0;
    }))// use of auto keyword allowed


