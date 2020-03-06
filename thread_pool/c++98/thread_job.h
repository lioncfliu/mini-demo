/*
 * created by lioncfliu on 2020/03/05.
 * */

#ifndef THREAD_JOB_H_
#define THREAD_JOB_H_

class ThreadJob
{
public:
	void set_args(void *args) { args_ = args; }
	virtual int run() = 0;
public:
	ThreadJob(void* args): args_(args) {}
	~ThreadJob() {}
protected:
	void* args_;
};


#endif //THREAD_JOB_H_
