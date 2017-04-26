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
		cout<<"COUNTER :"<<i<<endl;
		if(!threads[i]->get_is_finished()){
			threads[i]->do_functor();
		}
		for (int i = 0; i < threads.size(); ++i)
		{
			cout<<'	'<<i<<threads[i]->get_type()<<endl;
		}
		this->remove_completed();
		for (int i = 0; i < threads.size(); ++i)
		{
			cout<<'	'<<i<<threads[i]->get_type()<<endl;
		}
		cout<<"SIZE :"<<threads.size()<<endl;
		if(i >= (threads.size()-1)){
			i=-1;
		}
	}
}
void Scheduler::remove_completed(){
	for (int i = 0; i < threads.size(); ++i)
	{
		if(threads[i]->get_is_finished()){
			if(threads[i]->get_type() == "recurrent_thread"){
				cout<<"reverted"<<endl;
				threads[i]->revert_functors_state();
			}else{
				cout<<"removed :"<<threads[i]->get_type()<<endl;
				delete threads[i];
				threads.erase(threads.begin()+i);
				i=-1;
			}
		}
	}
}
Scheduler::~Scheduler(){
	cout<<"DELETE SCHEDULER!"<<endl;
	for (int i=0; i<threads.size() ;i++) {
		cout<<"COUNTER :"<<i<<endl;
		cout<<i<<" :"<<threads[i]->get_type()<<endl;
    	delete (threads[i]);
    	threads.erase(threads.begin()+i);
    	i=0;
	}
}