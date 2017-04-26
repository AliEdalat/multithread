#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "thread.h"
#include <iostream>

class Scheduler
{
public:
	Scheduler(std::vector<Thread*> _threads);
	void add_thread(Thread* new_thread);
	std::vector<Thread*> get_threads(){return threads;}
	virtual void do_threads();
	~Scheduler();
protected:
	std::vector<Thread*> threads;
	void remove_completed();
	
};

#endif