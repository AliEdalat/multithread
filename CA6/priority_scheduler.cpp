#include "priority_scheduler.h"
#include <iostream>

using namespace std;

//bool compare(Thread* first,Thread* second){
//	return first->get_priority() > second->get_priority();
//}
bool scheduler_is_completed(Scheduler* pointer){
	vector<Thread*> threads=pointer->get_threads();
	for (int i = 0; i < threads.size(); ++i)
	{
		if(threads[i]->get_is_finished() == false || threads[i]->get_type() == "recurrent_thread"){
			return false;
		}
	}
	cout<<"COMPLETED_SCHEDULER :"<<"true"<<endl;
	return true;
}
int calculate_sum(std::vector<Thread*> threads){
	int sum=0;
	for (int i = 0; i < threads.size(); ++i)
	{
		sum+=threads[i]->get_priority();
	}
	return sum;
}
void Priority_scheduler::do_threads(){
	//sort(threads.begin(),threads.end(),compare);
	//this->Scheduler::do_threads();
	
	
	//cout<<"SUM :"<<sum<<endl;
	srand(time(0));
	while(!(scheduler_is_completed(this))){
		//cout<<"RAND :"<<random_num<<endl;
		int min=0;
		int max=0;
		this->remove_completed();
		int sum=calculate_sum(threads);
		int random_num=rand()%sum;
		for (int i = 0; i < threads.size(); ++i)
		{
			max+=threads[i]->get_priority();
			if(random_num >= min && random_num < max && !threads[i]->get_is_finished()){
				cout<<threads[i]->get_priority()<<endl;
				threads[i]->do_functor();
			}
			min=max;
		}
	}
}