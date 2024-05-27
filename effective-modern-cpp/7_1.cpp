void f (){
    std::this_thread::sleep_for(1s);
}

auto fut = std::async(f);

if(fut.wait_for(0s)==std::future_status::defered)){
    // fut.get(); or 
    // fut.wait();
}
else {
    while(fut.wait_for(100ms) != std::future_status::ready){
        ;
        //do somethig
    }
    //fut is ready
}


auto fut2 = std::aysnc (std::launch::async, f);