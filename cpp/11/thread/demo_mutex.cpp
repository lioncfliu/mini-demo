#include <iostream>
#include <thread>
#include <mutex>

volatile int counter(0); // non-atomic
std::mutex mtx; // locks access to counter

void attempt_10k_increase()
{
    for (int i = 0; i < 10000; i++) {
        if (mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}

int main(int argc, char* argv[]) 
{
    std::thread threads[10];
    for (int i = 0; i < 10; i++) { 
        threads[i] = std::thread(attempt_10k_increase);
    }
    
    for (auto & t : threads) t.join();
    std::cout<<"Final counter:" << counter<<std::endl;
    return 0;
}
