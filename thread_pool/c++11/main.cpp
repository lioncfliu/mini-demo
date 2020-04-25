/*
 * created by lioncfliu on 2020/03/12.
 * */

#include "thread_pool.h"

#include <iostream>
#include <vector>
#include <chrono>


int main(int argc, char* argv[]) 
{
    ThreadPool pool(4);
    std::vector<std::future<int> > result;
    for (int i = 0 ; i < 20 ; i++) {
        result.emplace_back(pool.add_job([i]{
            std::cout<<"job-" << i <<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return i * i;
        }));
    }
    
    for (auto && r : result) {
        std::cout<<r.get() <<std::endl;
    }

    return 0;
}

