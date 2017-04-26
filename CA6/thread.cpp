#include "thread.h"

using namespace std;

bool runnable_node(vector<Functor*> funcotrs, string type){
	if(funcotrs.size() == 0){
		return true;
	}
	if(type == "if" && funcotrs[0]->get_is_finished() && (funcotrs[1]->get_is_finished() || funcotrs[2]->get_is_finished())){
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
	string type=root->get_type();
	if(!runnable_node(children ,type)){
		for (int i = 0; i < children.size(); ++i)
		{
			if(root->get_type() == "if" && children[0]->get_is_finished()){
				if(children[0]->get_result() == 0 && !children[2]->get_is_finished()){
					//cout<<"ELSE BRANCH !"<<endl;
					complete_small_part(children[2],run_first_functor);
					continue;

				}
				else if(children[0]->get_result() != 0 && !children[1]->get_is_finished()){
					//cout<<"IF BRANCH !"<<endl;
					complete_small_part(children[1],run_first_functor);
					continue;
				}else{
					continue;
				}				
			}
			if(!children[i]->get_is_finished()){
				//cout<<children[i]->get_type()<<endl;
				complete_small_part(children[i],run_first_functor);
			}
		}
		
		if(runnable_node(children , type) && run_first_functor == false){
			root->calculate_result_value();
			run_first_functor=true;
			//cout<<root->get_type()<<endl;
			return;
		}
	}else if(runnable_node(children , type) && run_first_functor == false){
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
	type="basic_thread";
	priority=0;
}
Thread::Thread(){
	type="basic_thread";
	priority=0;
}
void Thread::set_priority(int number){
	if(number<0 || number>20){
		throw runtime_error("invalid priority value!");
	}
	priority=number;
}
void delete_recursive(Functor* root){
	vector<Functor*> children=root->get_children();
	if (children.size() != 0)
	{
		for (int i = 0; i < children.size(); ++i)
		{
			delete_recursive(children[i]);
		}
		cout<<root->get_type()<<endl;
		delete root;
	}else{
		cout<<root->get_type()<<endl;
		delete root;
	}
}
Thread::~Thread(){
	cout<<"DELETE ROOT OF FUNCTORS!"<<endl;
	delete_recursive(root_of_functors);
}