#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <chrono>

int countdown(int from, int to) 
{
    for (int i = from; i !=to; --i) {
        std::cout<<i <<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout<<"Finished! \n" <<std::endl;
    return from - to;
}

int main(int argc, char* argv[])
{
    std::packaged_task<int(int,int)> task(countdown);
    std::future<int> ret = task.get_future();
    std::thread t(std::move(task), 10, 0);
    int value = ret.get();
    std::cout<<"The countdown lasted for" << value << " seconds. \n"<<std::endl;
    t.join();
    return 0;
}

