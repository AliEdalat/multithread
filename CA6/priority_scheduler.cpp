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
		if(threads[i]->get_is_finished() == false){
			return false;
		}
	}
	return true;
}
void Priority_scheduler::do_threads(){
	//sort(threads.begin(),threads.end(),compare);
	//this->Scheduler::do_threads();
	
	int sum=0;
	for (int i = 0; i < threads.size(); ++i)
	{
		sum+=threads[i]->get_priority();
	}
	//cout<<"SUM :"<<sum<<endl;
	srand(time(0));
	while(!(scheduler_is_completed(this))){
		int random_num=rand()%sum;
		cout<<"RAND :"<<random_num<<endl;
		int min=0;
		int max=0;
		this->remove_completed();
		for (int i = 0; i < threads.size(); ++i)
		{
			max+=threads[i]->get_priority();
			//cout<<"RANGE :"<<'['<<min<<','<<max<<']'<<endl;
			if(random_num >= min && random_num < max && !threads[i]->get_is_finished()){
				cout<<threads[i]->get_priority()<<endl;
				threads[i]->do_functor();
			}
			min=max;
		}
	}
}