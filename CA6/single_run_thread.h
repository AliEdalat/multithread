#ifndef SINGLE_RUN_THREAD_H
#define SINGLE_RUN_THREAD_H

#include "thread.h"

class single_run_thread:public Thread
{
public:
	single_run_thread(Functor* root):Thread(root){}
	void do_functor();
};

#endif