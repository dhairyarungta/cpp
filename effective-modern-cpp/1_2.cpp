template<typename Container, typename Index>
auto authAndAcess(Container& c, Index i)
    ->decltype(c[i])//a trailing return has the benefit that a functions parameters
                    //can be used in the specification
    {
        //some function call
        return c[i];
    }


template<typename Container, typename Index>
decltype(auto) //type deduced is whatever c[i] is, either reference or object
authAndAccess(Container& c, Index i)
{
    authenticateUser();
    return c[i];
}


template<typename Container, typename Index>
decltype(auto)
authAndAccess(Container&& c, Index i)
{
    authenticateUser();
    return std::forward<Container>(c)[i];
}


template<typename T>
class TD;

TD<decltype(x)>xType;
TD<decltype(y)>yType;

std::cout<<typeid(x).name()<<'\n';
std::cout<<typeid(y).name()<<'\n';

#include <boost/type_index.hpp>
template<typename T>
void f(const T& param){
    using std::cout;
    using boost::typeindex::type_id_with_cvr;

    cout<<"T =  "<<type_id_with_cvr<T>().pretty_name()<<'\n';

    cout<<"param =  "<<type_id_with_cvr<decltype(param)>().pretty_name()<<'\n';
}