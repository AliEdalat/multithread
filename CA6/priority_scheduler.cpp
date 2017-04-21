#include "priority_scheduler.h"
#include <iostream>

using namespace std;

bool compare(Thread* first,Thread* second){
	return first->get_priority() > second->get_priority();
}
void Priority_scheduler::do_threads(){
	sort(threads.begin(),threads.end(),compare);
	this->Scheduler::do_threads();
}