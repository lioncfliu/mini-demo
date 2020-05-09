#include <iostream>
#include <functional>
#include <thread>
#include <future>


void print_int(std::future<int> &future) 
{
    int x = future.get();
    std::cout<<"value: " <<x <<std::endl;
}

int main(int argc, char* argv[])
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();
    std::thread t(print_int, std::ref(future));
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    promise.set_value(10);
    
    t.join();
    return 0;
}
