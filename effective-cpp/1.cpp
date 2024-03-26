#include <string>
#include <vector>
#include <iterator>

#define ASPECT_RATIO  1.653
const double aspect_ratio = 1.653;

const char* const author_name = "Scott Meyers";
const std::string author_name {"Scott Meyers"};

class CostEstimate{
    private:
        static const double FudgeFactor;

};

const double CostEstimate::FudgeFactor = 1.35;

class GamePlayer
{
    private:
        enum {NumTurns = 5};
        int scores[NumTurns];
};


template<typename T>
inline void callWithMax(const T&a, const T&b)
{
    f(a>b?a:b);
}

std::vector<int> vec;
const std::vector<int>::iterator iter = vec.begin();
*iter = 10;
++iter; //this will give error because const iter is of the form T*const

std::vector<int>::const_iterator iter2 = vec.begin();
*iter2=10;//this gives error, since iter is of the form const T*
++iter2;



