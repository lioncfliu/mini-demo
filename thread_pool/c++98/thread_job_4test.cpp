/*
 * created by lioncfliu on 2020/03/06.
 *
 * */

#include "thread_job_4test.h"
#include <unistd.h>
#include <pthread.h>
#include <iostream>

int ThreadJob4Test::run() {
	Job4TestArgs* args = (Job4TestArgs*) ThreadJob::args_;	
	if (args) {
		std::cout<<"job ["<<args->job_id << "," <<args->job_name
				 <<"] is executing on thread ["<<pthread_self()
 				 <<"]" <<std::endl;
		sleep(5);
	}
	return 0;
}

