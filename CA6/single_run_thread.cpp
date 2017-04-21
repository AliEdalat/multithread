#include "single_run_thread.h"

using namespace std;

bool runnable(vector<Functor*> funcotrs){
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
void complete_small_part_single_run(Functor* root){
	vector<Functor*> children=root->get_children();
	if(!runnable(children)){
		for (int i = 0; i < children.size(); ++i)
		{
			if(!children[i]->get_is_finished()){
				//cout<<children[i]->get_type()<<' ';
				complete_small_part_single_run(children[i]);
			}
		}
		
		if(runnable(children)){
			root->calculate_result_value();
			//cout<<root->get_type()<<endl;
			return;
		}
	}else{
		root->calculate_result_value();
		//cout<<root->get_type()<<endl;
		return;
	}
}
void single_run_thread::do_functor(){
	complete_small_part_single_run(root_of_functors);
}