#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <exception>


void get_int(std::promise<int> &promise) 
{
    int x;
    std::cout<<"Please, enter an integer value: ";
    std::cin.exceptions(std::ios::failbit); // throw a failbit
    
    try {
        std::cin >> x;
        promise.set_value(x);
    } catch (std::exception &) {
        promise.set_exception(std::current_exception());
    } 
}

void print_int(std::future<int> &future)
{
   try {
        int x = future.get();
        std::cout<< "value: " <<x <<std::endl;
    } catch(std::exception &e) {
        std::cout<<"exception caught: "<< e.what() <<std::endl;
    }  
}


int main(int argc, char* argv[])
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();
    std::thread t1(get_int, std::ref(promise));
    std::thread t2(print_int, std::ref(future));

    t1.join();
    t2.join();
    return 0;
}
