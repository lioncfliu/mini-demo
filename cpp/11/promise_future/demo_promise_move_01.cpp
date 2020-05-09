#include <iostream>
#include <functional>
#include <thread>
#include <future>


std::promise<int> kPromise;


void print_int() 
{
    std::future<int> future = kPromise.get_future();
    int x = future.get();
    std::cout<<"value: " <<x <<std::endl;
}

int main(int argc, char* argv[])
{
    std::thread t1(print_int);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    kPromise.set_value(10);
    t1.join();


    kPromise = std::promise<int>();
    std::thread t2(print_int);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    kPromise.set_value(2);
    t2.join();
    return 0;
}
