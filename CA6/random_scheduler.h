#ifndef RANDOM_SCHEDULER_H
#define RANDOM_SCHEDULER_H

#include "scheduler.h"

class Random_scheduler:public Scheduler
{
public:
	Random_scheduler(std::vector<Thread*> random_threads):Scheduler(random_threads){};
	void do_threads();
};

#endif