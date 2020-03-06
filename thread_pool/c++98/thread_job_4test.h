/*
 * created by lioncfliu on 2020/03/06.
 *
 * */

#ifndef THREAD_JOB_4TEST_H_
#define THREAD_JOB_4TEST_H_

#include "thread_job.h"

#include <string>

typedef struct 
{
	int job_id;
	std::string job_name;

}Job4TestArgs;

class ThreadJob4Test:public ThreadJob 
{
public:
	virtual int run();
public:
	ThreadJob4Test(): ThreadJob(NULL) {}
	~ThreadJob4Test() {}

};

#endif //THREAD_JOB_4TEST_H_
