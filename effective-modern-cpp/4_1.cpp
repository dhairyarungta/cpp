#include <memory>
class Investment;
/*
class Bond : public Investment
class Stock : public Investment
class RealEstate : public Investment
*/
auto delInvestment = [](Investment* pInvestment){
    makelog(pInvestment);//some function to make a log before deleting investment
    delete pInvestment;
};

template <typename... Ts>
std::unique_ptr<Investment,decltype(delInvestment)>
createInvestement(Ts&&... params){
    std::unique_ptr<Investment,decltype(delInvestment)>pInv(nullptr,delInvestment);
    if(/*conditions for bond*/){
        pInv.reset(new Stock(std::forward<Ts>(params)...));
    }
    else if(/*conditions for stock*/){
        pInv.reset(new Bond(std::forward<Ts>(params)...));
    }
    else if(/*conditions for Real Estate*/){
        pInv.reset(new RealEstate(std::forward<Ts>(params)...));
    }

    return pInv;
}