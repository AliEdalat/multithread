#ifndef RECURRENT_THREAD_H
#define RECURRENT_THREAD_H

#include "thread.h"

class Recurrent_thread:public Thread
{
public:
	Recurrent_thread(Functor* _root):Thread(_root){
		type="recurrent_thread";
	};
	Recurrent_thread(){
		type="recurrent_thread";
	}
	void revert_functors_state();
	void do_functor();
};

#endif