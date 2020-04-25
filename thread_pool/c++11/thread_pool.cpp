/*
 * created by lioncfliu on 2020/03/12.
 *
 * */

#include "thread_pool.h"

ThreadPool::ThreadPool(size_t count): terminated_(false) {
    for (size_t i = 0; i < count; i++) {
        workers_.emplace_back([this]
            {
                for ( ; ; ) {
                    std::function<void()> job;
                    {
                        std::unique_lock<std::mutex> lock(this->mutex_);   
                        auto wait_func = [this]{ return this->terminated_ || ! this->job_queue_.empty(); };
                        this->condition_var_.wait(lock, wait_func);
                        
                        if (this->terminated_ && this->job_queue_.empty()) { return ;}
                        
                        job = std::move(this->job_queue_.front());
                        
                        this->job_queue_.pop();
                    }
                    job();
                }
            });
    }
}


template<typename Func, typename... Args>
auto ThreadPool::add_job(Func&& func, Args&& ... args) 
-> std::future<typename std::result_of<Func(Args...)>::type >
{
    using return_type = typename std::result_of<Func(Args...)>::type;
    auto job = std::make_shared<std::packaged_task<return_type> >(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));   
    std::future<return_type> result = job->get_future(); 
    {
        std::unique_lock<std::mutex>lock(mutex_);
        if (terminated_) { throw std::runtime_error("thread pool terminated while add job !");}
        job_queue_.emplace([job](){return (*job)() ;});
    }
    
    condition_var_.notify_one();
    return result;
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        terminated_ = true;
    }
    condition_var_.notify_all();
    for (std::thread &worker : workers_) {
        worker.join();
    }
}
