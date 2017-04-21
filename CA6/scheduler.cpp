#include "scheduler.h"
#include <iostream>

using namespace std;

Scheduler::Scheduler(std::vector<Thread*> _threads){
	for (int i = 0; i < _threads.size(); ++i)
	{
		threads.push_back(_threads[i]);
	}
}
void Scheduler::add_thread(Thread* new_thread){
	threads.push_back(new_thread);
}
bool scheduler_is_finished(Scheduler* pointer){
	vector<Thread*> threads=pointer->get_threads();
	for (int i = 0; i < threads.size(); ++i)
	{
		if(threads[i]->get_is_finished() == false){
			return false;
		}
	}
	return true;
}
void Scheduler::do_threads(){
	for (int i = 0; i < threads.size(); ++i)
	{
		//cout<<"COUNTER :"<<i<<endl;
		if(!scheduler_is_finished(this)){
			if(!threads[i]->get_is_finished()){
				//cout<<threads[i]->get_priority()<<endl;
				threads[i]->do_functor();
			}
			/*if(threads[i]->get_is_finished()){
				threads.erase(threads.begin()+i);
			}
			*/
			if(i == (threads.size()-1)){
				i=-1;
			}
		}
	}
}
/*Scheduler::~Scheduler(){
	cout<<"DELETE SCHEDULER!"<<endl;
	for (std::vector<Thread*>::iterator it = threads.begin(); it != threads.end(); ++it) {
    	delete *it;
	}
}
*/