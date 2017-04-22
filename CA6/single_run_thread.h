#ifndef SINGLE_RUN_THREAD_H
#define SINGLE_RUN_THREAD_H

#include "thread.h"

class single_run_thread:public Thread
{
public:
	single_run_thread(Functor* root):Thread(root){
		type="single_run_thread";
	}
	single_run_thread(){
		type="single_run_thread";	
	}
	void do_functor();
};

#endif