/*
 * created by lioncfliu on 2020/03/06.
 *
 * */


#include "thread_pool.h"
#include "thread_job_4test.h"

#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) 
{
	ThreadPool* pool = ThreadPool::get_instance(3);
	Job4TestArgs job_args[20];
	ThreadJob4Test jobs[20];

    std::stringstream ss;
	for (int i = 0; i< 20; i++) {
		ss.str(""); 
		ss<<"test-job-" << i;

		job_args[i].job_id = i;
		job_args[i].job_name = ss.str();
		
		jobs[i].set_args(&job_args[i]);
		pool->add_job(&jobs[i]);
	}

	while ( 1 ) {
		if (0 == pool->get_queue_size()) {
			break;
		}
		sleep(1);
	}

	delete pool;
	std::cout<<"exited from main"<<std::endl;

	return 0;
}
