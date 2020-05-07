#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex mtx; // locks access to counter

void fireworks()
{
    while (! mtx.try_lock_for(std::chrono::milliseconds(500))) {
        std::cout<<"-";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"*\n";
    mtx.unlock();
}

int main(int argc, char* argv[]) 
{
    std::thread threads[10];
    for (int i = 0; i < 10; i++) { 
        threads[i] = std::thread(fireworks);
    }
    
    for (auto & t : threads) t.join();
    return 0;
}
