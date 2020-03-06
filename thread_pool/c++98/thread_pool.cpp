/*
 * created by lioncfliu on 2020/03/05.
 *
 * */

#include "thread_pool.h"

#include <iostream>
#include <stdlib.h>


ThreadPool::ThreadPool(int count): thread_count_(count), terminated_(false) {
	pthread_mutex_init(&mutex_, NULL);
	pthread_cond_init(&condition_, NULL);
	create_threads();	
}

ThreadPool::~ThreadPool() {
	clean_threads();
	clean_queue();
}

ThreadPool* ThreadPool::get_instance(int count) {
	static ThreadPool* instance = new ThreadPool(count);
	return instance;
}

int ThreadPool::get_queue_size() { 
	pthread_mutex_lock(&mutex_);
	int size = job_queue_.size();
	pthread_mutex_unlock(&mutex_);
	return size; 

}

int ThreadPool::get_thread_count() { return thread_count_; }

void ThreadPool::create_threads() {
	thread_id_set_ = (pthread_t*)malloc(sizeof(pthread_t) * thread_count_);

	for(int i=0; i < thread_count_; i++) {
		pthread_create(&thread_id_set_[i], NULL, thread_func, this);
	}
}

void ThreadPool::add_job(ThreadJob* job) {
	pthread_mutex_lock(&mutex_);
	job_queue_.push(job);	
	std::cout<<"push a job into queue, current job count:"
			 <<job_queue_.size() <<std::endl;
	pthread_mutex_unlock(&mutex_);
	pthread_cond_signal(&condition_);
}

ThreadJob* ThreadPool::take_job() {
	ThreadJob* job = NULL;
	while(! job) {
		pthread_mutex_lock(&mutex_);
		while (job_queue_.empty() && ! terminated_) {
			pthread_cond_wait(&condition_, &mutex_);
		}

		if (terminated_) {
			pthread_mutex_unlock(&mutex_);
			break;
		}
		
		else if (job_queue_.empty()) {
			pthread_mutex_unlock(&mutex_);
			continue;
        }
		job = job_queue_.front();
		job_queue_.pop();
		pthread_mutex_unlock(&mutex_);
	}
	
	return job;
}

void* ThreadPool::thread_func(void* args) {
	ThreadPool* pool = (ThreadPool *)args;
	
	while (! pool->terminated_) {
		ThreadJob* job = pool->take_job();
		if (! job) { break; }
		std::cout<<"take a job to run" <<std::endl;
		
		job->run();
	}
}

void ThreadPool::clean_queue() {
	while (! job_queue_.empty()) {
		// delete job_queue_.front();
		job_queue_.pop();
	}
}

void ThreadPool::clean_threads() {
	if (! terminated_) {
		return;
	}

	terminated_ = true;
	pthread_cond_broadcast(&condition_);
	for (int i = 0; i < thread_count_; i++) {
		pthread_join(thread_id_set_[i], NULL);
	}
	free(thread_id_set_);
	thread_id_set_ = NULL;
	pthread_mutex_destroy(&mutex_);
	pthread_cond_destroy(&condition_);
}




