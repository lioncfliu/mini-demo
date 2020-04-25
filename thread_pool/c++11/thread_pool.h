/*
 * created by lionfliu on 2020/03/12.
 *
 * */

#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <vector>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <functional>
#include <future>


class ThreadPool 
{
public:
    template<typename Func, typename ... Args>
    auto add_job(Func&& func, Args&&... args) -> std::future<typename std::result_of<Func(Args...)>::type>;

public:
    ThreadPool(size_t count);
    ~ThreadPool();
    
private:
    std::vector<std::thread> workers_;
    std::queue<std::function<void()> > job_queue_;
    std::mutex  mutex_;
    std::condition_variable condition_var_;
    bool terminated_;
};

#endif //THREAD_POOL_H_
