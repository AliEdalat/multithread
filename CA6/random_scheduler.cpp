#include "random_scheduler.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool _is_finished(Scheduler* pointer){
	vector<Thread*> threads=pointer->get_threads();
	for (int i = 0; i < threads.size(); ++i)
	{
		if(threads[i]->get_is_finished() == false){
			return false;
		}
	}
	return true;
}
void Random_scheduler::do_threads(){
	srand(time(0));
	while(!(_is_finished(this))){
		int size=threads.size();
		int index=rand()%size;
		if(!threads[index]->get_is_finished()){
			threads[index]->do_functor();
		}
		this->remove_completed();
	}
}