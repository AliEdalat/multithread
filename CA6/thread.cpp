#include "thread.h"

using namespace std;

bool runnable_node(vector<Functor*> funcotrs){
	if(funcotrs.size() == 0){
		return true;
	}
	for (int i = 0; i < funcotrs.size(); ++i)
	{
		//cout<<funcotrs[i]->get_type()<<funcotrs[i]->get_is_finished()<<endl; 
		if(funcotrs[i]->get_is_finished() == false){
			return false;
		}
	}
	return true;
}
void complete_small_part(Functor* root,bool& run_first_functor){
	vector<Functor*> children=root->get_children();
	if(!runnable_node(children)){
		for (int i = 0; i < children.size(); ++i)
		{
			if(!children[i]->get_is_finished()){
				//cout<<children[i]->get_type()<<endl;
				complete_small_part(children[i],run_first_functor);
			}
		}
		
		if(runnable_node(children) && run_first_functor == false){
			root->calculate_result_value();
			run_first_functor=true;
			//cout<<root->get_type()<<endl;
			return;
		}
	}else if(runnable_node(children) && run_first_functor == false){
		root->calculate_result_value();
		run_first_functor=true;
		//cout<<root->get_type()<<endl;
		return;
	}
}
void Thread::do_functor(){
	bool run=false;
	complete_small_part(root_of_functors,run);
	/*cout<<root_of_functors->get_type()<<endl;
	vector<Functor*> children=root_of_functors->get_children();
	cout<<runnable_node(children)<<endl;
	root_of_functors->calculate_result_value();
	*/
}
Thread::Thread(Functor* root){
	root_of_functors=root;
	priority=0;
}
Thread::Thread(){
	priority=0;
}
void Thread::set_priority(int number){
	if(number<0 || number>20){
		throw runtime_error("invalid priority value!");
	}
	priority=number;
}
/*Thread::~Thread(){
	cout<<"DELETE ROOT OF FUNCTORS!"<<endl;
	delete root_of_functors;
}*/