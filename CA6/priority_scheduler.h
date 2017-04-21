#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include "scheduler.h"
#include <algorithm>

class Priority_scheduler:public Scheduler
{
public:
	Priority_scheduler(std::vector<Thread*> priority_threads):Scheduler(priority_threads){};
	void do_threads();
};

#endif