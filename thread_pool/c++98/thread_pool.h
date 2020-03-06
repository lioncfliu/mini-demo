/*
 * created by lioncfliu on 2020/03/05.
 * */

#ifndef THREAD_POOL_H_ 
#define THREAD_POOL_H_ 

#include "thread_job.h"

#include <queue>
#include <unistd.h>
#include <pthread.h>

class ThreadPool 
{
public:
	void add_job(ThreadJob* job);
	static ThreadPool* get_instance(int count);
	int get_queue_size();
	int get_thread_count();
public:
	~ThreadPool();

private: ThreadPool(int count);
	void create_threads();
	void clean_threads();
	void clean_queue();
	static void* thread_func(void* args);
	ThreadJob* take_job();

private:
	std::queue<ThreadJob*> job_queue_; 
	bool terminated_;
	int	thread_count_;
	pthread_t* thread_id_set_;
	pthread_mutex_t	mutex_;
	pthread_cond_t	condition_;

};

#endif //THREAD_POOL_H_ 
