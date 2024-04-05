#include <memory>
#include <map>
class Widget;

std::shared_ptr<Widget> spw = std::make_shared<Widget>();
std::weak_ptr<Widget> wpw(spw);

void func(){

    spw = nullptr;
    if(wpw.expired()){
        //shared ptr assigned to the object
    }
}

void func2(){
    //an atomic operation is required to check if shared_ptr is not null and then again access to it
    //because there could be a possible race between call to expired and the hypothetical deference operation
    // this is what lock does
    std::shared_ptr<Widget>spw1 = wpw.lock();
    //lock is an atomic operation
    //if shared ptr had expired by the time lock is called then spw1 = nullptr
    auto spw2 = wpw.lock();


    //other possibility 
    //pass weakptr to constructor of shared ptr
    std::shared_ptr<Widget>spw3(wpw);
    //if wpw had expired exception thrown
}


std::shared_ptr<Widget> fastLoadWidget(WidgetId id){

    static std::unordered_map<WidgetId,weak_ptr<const Widget>>cache;
    std::shared_ptr<Widget>spw = nullptr;
    if(cache.contains(WidgetId)){
        spw = cache[id].lock();

    } 
    if(!spw){
        spw = loadWidget(id);
        cache[id] = spw;
    }

    return spw;
}

template <typename T, typename... &&Ts>
std::unique_ptr<T>
make_unique(Ts&& ... args){
    return std::unique_ptr<T>(new T(std::forward<Ts>(args)...));
}