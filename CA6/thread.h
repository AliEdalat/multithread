#ifndef THREAD_H
#define THREAD_H

#include "functor.h"
#include <iostream>
#include <stdexcept>

class Thread
{
public:
	Thread(Functor* root);
	Thread();
	bool get_is_finished(){return root_of_functors->get_is_finished();}
	void set_priority(int number);
	int get_priority(){return priority;}
	virtual void do_functor();
	//~Thread();
protected:
	int priority;
	Functor* root_of_functors;
	
};

#endif